/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   field_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 19:24:17 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/04 21:47:45 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>
#include "printf.h"
#include "formatters.h"

char	*apply_field_width(char *str, t_flags *flags)
{
	char		*newstr;
	const char	pad_c =
		(flags->pad_zeroes && !flags->pad_neg_f_width) ? '0' : ' ';
	const int	s_len = ft_strlen(str);

	if (!flags->min_field_width)
		return (str);
	if (s_len > flags->min_field_width_n ||
			s_len > INT_MAX)
		return (str);
	newstr = malloc(sizeof(char) * (flags->min_field_width_n + 1));
	ft_memset(newstr, pad_c, flags->min_field_width_n);
	newstr[flags->min_field_width_n] = '\0';
	if (flags->pad_neg_f_width)
		ft_memcpy(newstr, str, s_len);
	else
		ft_memcpy(newstr + (flags->min_field_width_n - s_len), str, s_len);
	free(str);
	return (newstr);
}

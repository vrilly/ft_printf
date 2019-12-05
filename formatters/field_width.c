/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   field_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 19:24:17 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/05 19:56:15 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>
#include <unistd.h>
#include "printf.h"
#include "formatters.h"

static void	set_neg(char *str, t_flags *flags, int s_len)
{
	if (flags->pad_zeroes && !flags->precision)
		str[0] = '-';
	else if (!flags->pad_neg_f_width)
		str[flags->min_field_width_n - s_len] = '-';
}

static char	get_pad_char(t_flags *flags)
{
	if (flags->pad_zeroes &&
			!flags->precision &&
			!flags->pad_neg_f_width)
		return ('0');
	return (' ');
}

char		*apply_field_width(char *str, t_flags *flags)
{
	const char	pad_c = get_pad_char(flags);
	const int	s_len = ft_strlen(str);
	const int	is_neg = (str[0] == '-' && flags->pad_zeroes);
	char		*newstr;

	if (!flags->min_field_width)
		return (str);
	if (s_len > flags->min_field_width_n ||
			s_len > INT_MAX)
		return (str);
	flags->min_field_width_n -= flags->print_null_term;
	newstr = malloc(sizeof(char) * (flags->min_field_width_n + 1));
	ft_memset(newstr, pad_c, flags->min_field_width_n);
	newstr[flags->min_field_width_n] = '\0';
	if (flags->pad_neg_f_width)
		ft_memcpy(newstr, str, s_len);
	else
		ft_memcpy(newstr + (flags->min_field_width_n - s_len) + is_neg,
				str + is_neg, s_len);
	if (is_neg)
		set_neg(newstr, flags, s_len);
	free(str);
	return (newstr);
}

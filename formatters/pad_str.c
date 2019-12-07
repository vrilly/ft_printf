/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pad_str.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 16:26:25 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/07 22:17:01 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "formatters.h"

char		*pad_str(char *str, int pad_nums, char pad_char)
{
	int		s_len;
	char	*newstr;
	char	is_neg;

	s_len = ft_strlen(str);
	if (!pad_nums && *str == '0')
	{
		free(str);
		return (ft_strdup(""));
	}
	if (s_len >= pad_nums)
		return (str);
	is_neg = (*str == '-');
	newstr = ft_calloc(pad_nums + 1 + is_neg, sizeof(char));
	if (is_neg)
		newstr[0] = '-';
	ft_memset(newstr + is_neg, pad_char, pad_nums - s_len + is_neg);
	ft_strlcat(newstr, str + is_neg, pad_nums + 1 + is_neg);
	free(str);
	return (newstr);
}

char		*pad_str_rev(char *str, int pad_nums, char pad_char)
{
	int		s_len;
	char	*newstr;

	s_len = ft_strlen(str);
	if (s_len >= pad_nums)
		return (str);
	newstr = ft_calloc(pad_nums + 1, sizeof(char));
	ft_strlcpy(newstr, str, pad_nums + 1);
	ft_memset(newstr + s_len, pad_char, pad_nums - s_len);
	free(str);
	return (newstr);
}

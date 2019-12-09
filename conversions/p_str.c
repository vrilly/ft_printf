/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_str.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 13:39:51 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/09 14:23:55 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "conversions.h"

static char	*p_null(t_flags *flags)
{
	char	*str;
	char	*ret;
	int		ret_s;

	str = ft_strdup("(null)");
	if (!str)
		return (NULL);
	if (flags->precision)
		ret_s = flags->precision_n + 1;
	else
		ret_s = ft_strlen(str) + 1;
	ret = malloc(ret_s);
	ft_strlcpy(ret, str, ret_s);
	free(str);
	return (ret);
}

char		*p_str(va_list arg, t_flags *flags)
{
	char	*str;
	char	*ret;
	int		ret_s;

	str = va_arg(arg, char*);
	if (str == NULL)
		return (p_null(flags));
	if (flags->precision)
		ret_s = flags->precision_n + 1;
	else
		ret_s = ft_strlen(str) + 1;
	ret = malloc(ret_s);
	ft_strlcpy(ret, str, ret_s);
	return (ret);
}

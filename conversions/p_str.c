/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_str.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 13:39:51 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/07 23:27:12 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "conversions.h"

char	*p_str(va_list arg, t_flags *flags)
{
	char	*str;
	char	*ret;
	int		ret_s;

	str = va_arg(arg, char*);
	if (str == NULL)
		str = ft_strdup("(null)");
	if (flags->precision)
		ret_s = flags->precision_n + 1;
	else
		ret_s = ft_strlen(str) + 1;
	ret = malloc(ret_s);
	ft_strlcpy(ret, str, ret_s);
	return (ret);
}

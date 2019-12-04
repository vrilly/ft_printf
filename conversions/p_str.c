/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_str.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 13:39:51 by tjans         #+#    #+#                 */
/*   Updated: 2019/11/30 20:32:09 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "conversions.h"

char	*p_str(va_list arg, t_flags *flags)
{
	char	*str;
	char	*ret;
	size_t	ret_s;

	str = va_arg(arg, char*);
	if (str == NULL)
		return(ft_strdup("(null)"));
	if (flags->precision)
		ret_s = flags->precision_n + 1;
	else
		ret_s = ft_strlen(str) + 1;
	ret = malloc(ret_s);
	ft_strlcpy(ret, str, ret_s);
	return (ret);
}

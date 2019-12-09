/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_uint.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 14:44:32 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/09 14:54:28 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"
#include "formatters.h"

char	*p_uint(va_list arg, t_flags *flags)
{
	unsigned int	i;
	char			*ret;

	i = va_arg(arg, unsigned int);
	ret = ltoa_base_unsigned(i, 10);
	if (!ret)
		return (NULL);
	if (flags->precision)
		ret = pad_str(ret, flags->precision_n, '0');
	return (ret);
}

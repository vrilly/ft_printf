/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_hex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/29 20:17:28 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/09 14:53:25 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"
#include "formatters.h"

char	*p_hex_lower(va_list arg, t_flags *flags)
{
	char			*str;
	unsigned int	i;

	i = va_arg(arg, unsigned int);
	str = ltoa_base_unsigned(i, 16);
	if (!str)
		return (NULL);
	if (flags->precision)
		str = pad_str(str, flags->precision_n, '0');
	return (str);
}

char	*p_hex_upper(va_list arg, t_flags *flags)
{
	char	*str;

	str = p_hex_lower(arg, flags);
	if (!str)
		return (NULL);
	strupper(str);
	return (str);
}

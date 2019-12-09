/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_int.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 15:18:45 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/09 14:52:01 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"
#include "formatters.h"

char	*p_int(va_list arg, t_flags *flags)
{
	int		i;
	char	*ret;

	i = va_arg(arg, int);
	ret = ltoa_signed(i);
	if (!ret)
		return (NULL);
	if (flags->precision)
		ret = pad_str(ret, flags->precision_n, '0');
	return (ret);
}

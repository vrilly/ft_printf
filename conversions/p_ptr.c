/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_ptr.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/29 19:08:28 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/09 14:53:43 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "conversions.h"
#include "formatters.h"

char	*p_ptr(va_list arg, t_flags *flags)
{
	void	*ptr;
	char	*ptr_addr_str;

	ptr = va_arg(arg, void*);
	ptr_addr_str = ltoa_base_unsigned((unsigned long)ptr, 16);
	if (!ptr_addr_str)
		return (NULL);
	if (flags->precision)
		ptr_addr_str = pad_str(ptr_addr_str, flags->precision_n, '0');
	if (flags->min_field_width_n >= 2 && flags->pad_zeroes)
		flags->min_field_width_n -= 2;
	if (flags->pad_zeroes)
		apply_field_width(&ptr_addr_str, flags);
	ptr_addr_str = prefix_hex(ptr_addr_str);
	apply_field_width(&ptr_addr_str, flags);
	return (ptr_addr_str);
}

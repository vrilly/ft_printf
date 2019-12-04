/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_ptr.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/29 19:08:28 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/01 18:44:35 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "conversions.h"
#include "formatters.h"

char	*p_ptr(va_list arg, t_flags *flags)
{
	void	*ptr;
	char	*ptr_addr_str;

	ptr = va_arg(arg, void*);
	ptr_addr_str = ltoa_base_unsigned((unsigned long)ptr, 16);
	if (flags->precision)
		ptr_addr_str = pad_str(ptr_addr_str, flags->precision_n, '0');
	return(prefix_hex(ptr_addr_str));
}

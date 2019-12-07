/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_char.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 15:25:04 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/07 23:26:28 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <unistd.h>
#include "conversions.h"

char	*p_char(va_list arg, t_flags *flags)
{
	unsigned char	c;
	char			*ret;

	c = (unsigned char)va_arg(arg, int);
	flags->precision = flags->precision;
	if (!c)
		flags->print_null_term = 1;
	ret = ft_calloc(sizeof(char), 2);
	ret[0] = c;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_char.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 15:25:04 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/04 18:46:36 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "conversions.h"

char	*p_char(va_list arg, t_flags *flags)
{
	unsigned char	c;
	char			*ret;

	c = (unsigned char)va_arg(arg, int);
	ret = ft_calloc(sizeof(char), 2);
	ret[0] = c;
	return (ret);
}

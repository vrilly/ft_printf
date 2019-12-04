/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 18:29:47 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/04 18:46:12 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <libft.h>
#include "printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list	args;
	char	*ret;
	size_t	len;

	va_start(args, fmt);
	ret = format_str(fmt, args);
	va_end(args);
	ft_putstr_fd(ret, 1);
	len = ft_strlen(ret);
	free(ret);
	return (len);
}

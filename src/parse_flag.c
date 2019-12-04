/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flag.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 11:29:16 by tjans         #+#    #+#                 */
/*   Updated: 2019/11/26 14:38:34 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "printf.h"

static int	get_precision(const char **fmt)
{
	int	precision;

	precision = 0;
	while (ft_isdigit(**fmt))
	{
		precision *= 10;
		precision += **fmt - '0';
		(*fmt)++;
	}
	return (precision);
}

static void	set_flag(t_flags *flags, const char **fmt)
{
	if (**fmt == '-')
	{
		flags->pad_neg_f_width = 1;
		(*fmt)++;
	}
	if (**fmt == '0')
	{
		flags->pad_zeroes = 1;
		(*fmt)++;
	}
	if (**fmt == '.')
	{
		(*fmt)++;
		flags->precision = 1;
		flags->precision_n = get_precision(fmt);
	}
}

t_flags		*parse_flags(const char **fmt)
{
	t_flags	*flags;

	flags = ft_calloc(1, sizeof(t_flags));
	if (!flags)
		return (NULL);
	set_flag(flags, fmt);
	return (flags);
}

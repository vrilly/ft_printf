/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flag.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 11:29:16 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/05 19:50:30 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "printf.h"

static int	get_precision(const char **fmt, va_list args, t_flags *flags)
{
	int	precision;

	precision = 0;
	if (**fmt == '*')
	{
		precision = va_arg(args, int);
		(*fmt)++;
		if (precision < 0)
		{
			precision *= -1;
			if (!flags->precision)
				flags->pad_neg_f_width = 1;
			else
				flags->precision = 0;
		}
		return (precision);
	}
	while (ft_isdigit(**fmt))
	{
		precision *= 10;
		precision += **fmt - '0';
		(*fmt)++;
	}
	return (precision);
}

static void	set_flag(t_flags *flags, const char **fmt, va_list args)
{
	while (**fmt == '-' || **fmt == '0')
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
	}
	if (ft_isdigit(**fmt) || **fmt == '*')
	{
		flags->min_field_width = 1;
		flags->min_field_width_n = get_precision(fmt, args, flags);
	}
	if (**fmt == '.')
	{
		(*fmt)++;
		flags->precision = 1;
		flags->precision_n = get_precision(fmt, args, flags);
	}
}

t_flags		*parse_flags(const char **fmt, va_list args)
{
	t_flags	*flags;

	(*fmt)++;
	flags = ft_calloc(1, sizeof(t_flags));
	if (!flags)
		return (NULL);
	set_flag(flags, fmt, args);
	return (flags);
}

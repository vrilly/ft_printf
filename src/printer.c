/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 16:30:19 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/09 14:59:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "printf.h"
#include "utils.h"
#include "formatters.h"

static int	cleanup(int retval, int elements, ...)
{
	va_list	arg;
	int		i;
	void	*mem_to_free;

	i = 0;
	va_start(arg, elements);
	while (i < elements)
	{
		mem_to_free = va_arg(arg, void*);
		if (mem_to_free != NULL)
			free(mem_to_free);
		i++;
	}
	va_end(arg);
	return (retval);
}

static int	prt_str(const char **str)
{
	char	*ex;
	int		s_len;

	s_len = ft_strclen(*str, '%');
	ex = malloc(sizeof(char) * s_len + 1);
	if (!ex)
		return (0);
	ft_strlcpy(ex, *str, s_len + 1);
	*str += s_len;
	write(1, ex, s_len);
	free(ex);
	return (s_len);
}

static int	eval_conv(const char **fmt, va_list args)
{
	t_flags		*flags;
	t_ctable	*converter;
	char		*ret;
	int			ret_len;

	if (**fmt != '%')
		return (prt_str(fmt));
	flags = parse_flags(fmt, args);
	converter = find_conv(**fmt);
	while (!converter && **fmt != '\0')
	{
		converter = find_conv(**fmt);
		(*fmt)++;
	}
	if (!converter || !flags)
		return (cleanup(0, 1, flags));
	else
		ret = converter->conv(args, flags);
	if (ret == NULL)
		return (cleanup(0, 1, flags));
	ret_len = apply_field_width(&ret, flags);
	if (**fmt)
		(*fmt)++;
	write(1, ret, ret_len);
	return (cleanup(ret_len, 2, flags, ret));
}

int			print_str(const char *fmt, va_list args)
{
	int	ret;

	ret = 0;
	while (*fmt)
		ret += eval_conv(&fmt, args);
	return (ret);
}

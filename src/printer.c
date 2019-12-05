/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 16:30:19 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/05 19:48:33 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <unistd.h>
#include "printf.h"
#include "formatters.h"

static void	prt_nul(void)
{
	const char	nul = '\0';

	write(1, &nul, 1);
}

static int	prt_str(const char **str)
{
	char	*ex;
	int		s_len;

	s_len = ft_strclen(*str, '%');
	ex = malloc(sizeof(char) * s_len + 1);
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
	while (!(converter = find_conv(**fmt)) && **fmt != '\0')
		(*fmt)++;
	if (!converter)
		return (0);
	else
		ret = converter->conv(args, flags);
	ret = apply_field_width(ret, flags);
	if (**fmt)
		(*fmt)++;
	ret_len = ft_strlen(ret);
	write(1, ret, ret_len);
	ret_len += flags->print_null_term;
	if (flags->print_null_term && !flags->pad_neg_f_width)
		prt_nul();
	free(flags);
	free(ret);
	return (ret_len);
}

int			print_str(const char *fmt, va_list args)
{
	int	ret;

	ret = 0;
	while (*fmt)
		ret += eval_conv(&fmt, args);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formatter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 20:37:07 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/05 16:42:44 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "printf.h"
#include "formatters.h"

static char	*extract_str(const char **str)
{
	char	*ex;
	size_t	s_len;

	s_len = ft_strclen(*str, '%') + 1;
	ex = malloc(sizeof(char) * s_len);
	ft_strlcpy(ex, *str, s_len);
	*str += s_len - 1;
	return (ex);
}

static char	*eval_conv(const char **fmt, va_list args)
{
	t_flags		*flags;
	t_ctable	*converter;
	char		*ret;

	if (**fmt != '%')
		return (extract_str(fmt));
	(*fmt)++;
	flags = parse_flags(fmt, args);
	converter = NULL;
	while (!converter && **fmt != '\0')
	{
		converter = find_conv(**fmt);
		if (!converter)
			(*fmt)++;
	}
	if (!converter)
		ret = ft_strdup("");
	else
		ret = converter->conv(args, flags);
	ret = apply_field_width(ret, flags);
	if (**fmt)
		(*fmt)++;
	free(flags);
	return (ret);
}

char	*format_str(const char *fmt, va_list args)
{
	t_strlist	*strlist;
	char		*result;
	char		*conv_res;

	conv_res = eval_conv(&fmt, args);
	if (conv_res == NULL)
		return (ft_strdup(""));
	strlist = strlist_create(conv_res);
	while (*fmt)
	{
		conv_res = eval_conv(&fmt, args);
		if (conv_res == NULL)
			break ;
		strlist_append(strlist, conv_res);
	}
	result = strlist_join(strlist);
	strlist_free(&strlist);
	return (result);
}

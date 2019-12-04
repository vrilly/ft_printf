/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 11:23:53 by tjans         #+#    #+#                 */
/*   Updated: 2019/11/30 20:33:00 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>

typedef struct	s_flags
{
	char	pad_neg_f_width;
	char	pad_zeroes;
	char	precision;

	int		precision_n;
}				t_flags;

typedef struct	s_ctable
{
	char	c_arg;
	char	*(*conv)(va_list args, t_flags *flags);
}				t_ctable;

extern t_ctable	g_ctable[];
t_ctable		*find_conv(char c);

char			*ltoa_base_unsigned(unsigned long n, int base);
char			*ltoa_signed(long n);

t_flags			*parse_flags(const char **fmt);
char			*format_str(const char *fmt, va_list args);
int				ft_printf(const char *fmt, ...);
int				ft_vsprintf(char *str, const char *fmt, va_list args);

#endif

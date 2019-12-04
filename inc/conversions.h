/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 13:00:32 by tjans         #+#    #+#                 */
/*   Updated: 2019/11/30 20:32:27 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H
# include "printf.h"

char	*p_sign(va_list arg, t_flags *flags);
char	*p_str(va_list arg, t_flags *flags);
char	*p_int(va_list arg, t_flags *flags);
char	*p_char(va_list arg, t_flags *flags);
char	*p_uint(va_list arg, t_flags *flags);
char	*p_ptr(va_list arg, t_flags *flags);
char	*p_hex_lower(va_list arg, t_flags *flags);
char	*p_hex_upper(va_list arg, t_flags *flags);

#endif

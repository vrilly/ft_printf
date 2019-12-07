/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formatters.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 15:56:40 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/07 23:28:10 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATTERS_H
# define FORMATTERS_H
# include <stdlib.h>
# include "printf.h"

char	*prefix_hex(char *str);
char	*pad_str(char *str, int pad_nums, char pad_char);
char	*pad_str_rev(char *str, int pad_nums, char pad_char);
int		apply_field_width(char **str, t_flags *flags);
void	strupper(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formatters.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 15:56:40 by tjans         #+#    #+#                 */
/*   Updated: 2019/11/30 16:48:33 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATTERS_H
# define FORMATTERS_H
# include <libft.h>
# include <stdlib.h>

char	*prefix_hex(char *str);
char	*pad_str(char *str, int pad_nums, char pad_char);
char	*pad_str_rev(char *str, int pad_nums, char pad_char);
void	strupper(char *str);

#endif

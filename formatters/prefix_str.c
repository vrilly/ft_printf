/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prefix_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 15:58:54 by tjans         #+#    #+#                 */
/*   Updated: 2019/11/30 15:59:31 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "formatters.h"

char	*prefix_hex(char *str)
{
	char	*newstr;

	newstr = ft_strjoin("0x", str);
	free(str);
	return (newstr);
}

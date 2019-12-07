/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlen.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 10:31:44 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/07 23:15:46 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strclen(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	return (ft_strclen(s, 0));
}

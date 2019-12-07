/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calloc.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 15:49:41 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/07 23:13:49 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			bytes;

	bytes = count * size;
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, bytes);
	return ((void*)ptr);
}

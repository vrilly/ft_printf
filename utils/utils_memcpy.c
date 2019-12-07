/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memcpy.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:58:52 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/07 23:13:44 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdst;

	csrc = (unsigned char*)src;
	cdst = (unsigned char*)dst;
	if (!src && !dst)
		return (NULL);
	while (n)
	{
		*cdst = *csrc;
		csrc++;
		cdst++;
		n--;
	}
	return (dst);
}

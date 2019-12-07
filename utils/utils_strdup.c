/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strdup.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 15:57:41 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/07 23:14:24 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*dup;

	i = 0;
	len = ft_strlen(s1);
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

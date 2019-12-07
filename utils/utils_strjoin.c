/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 18:49:00 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/07 23:14:53 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str_size;
	char	*jstr;

	if (!s1 || !s2)
		return (NULL);
	str_size = ft_strlen(s1);
	str_size += ft_strlen(s2);
	str_size++;
	jstr = malloc(sizeof(char) * str_size);
	if (!jstr)
		return (NULL);
	ft_strlcpy(jstr, s1, str_size);
	ft_strlcat(jstr, s2, str_size);
	return (jstr);
}

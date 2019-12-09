/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nconv.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 12:08:08 by tjans         #+#    #+#                 */
/*   Updated: 2019/12/09 14:51:19 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <limits.h>
#include "conversions.h"

static void		ft_strrev(char *s)
{
	char	swp;
	char	*s1;

	s1 = s + ft_strlen(s) - 1;
	while (s1 > s)
	{
		swp = *s1;
		*s1 = *s;
		*s = swp;
		s1--;
		s++;
	}
}

static void		ltoa_char_processor(char *str, unsigned long n, int base)
{
	unsigned int	mod_result;

	if (n)
	{
		mod_result = n % base;
		*str = mod_result + ((mod_result > 9) ? 'a' - 10 : '0');
		ltoa_char_processor(str + 1, n / base, base);
	}
	else
		*str = '\0';
}

char			*ltoa_base_unsigned(unsigned long n, int base)
{
	char	*str;

	if (base < 1 || base > 16)
		return (ft_strdup(""));
	if (n == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) * 65);
	if (!str)
		return (NULL);
	ltoa_char_processor(str, n, base);
	ft_strrev(str);
	return (str);
}

char			*ltoa_signed(long n)
{
	char	*str;
	char	neg;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	neg = (n < 0);
	if (neg)
		n *= -1;
	str = malloc(sizeof(char) * 32);
	if (!str)
		return (NULL);
	ltoa_char_processor(str, n, 10);
	if (neg)
		ft_strlcat(str, "-", 32);
	ft_strrev(str);
	return (str);
}

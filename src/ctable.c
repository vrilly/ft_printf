/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ctable.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tjans <tjans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 12:53:37 by tjans         #+#    #+#                 */
/*   Updated: 2019/11/29 20:30:29 by tjans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "conversions.h"

t_ctable	g_ctable[] = {
	{'%', &p_sign},
	{'s', &p_str},
	{'d', &p_int},
	{'i', &p_int},
	{'c', &p_char},
	{'u', &p_uint},
	{'p', &p_ptr},
	{'x', &p_hex_lower},
	{'X', &p_hex_upper},
	{0, NULL}
};

t_ctable	*find_conv(char c)
{
	int	i;

	i = 0;
	while (g_ctable[i].conv)
	{
		if (g_ctable[i].c_arg == c)
			return (&(g_ctable[i]));
		i++;
	}
	return (NULL);
}

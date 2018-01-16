/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:28:18 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/11/09 10:34:14 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	res;

	a = 0;
	i = 0;
	while (dest[i] != '\0')
		i = i + 1;
	res = 0;
	while (src[res] != '\0')
		res = res + 1;
	if (size <= i)
		res += size;
	else
		res += i;
	while (src[a] != '\0' && i + 1 < size)
	{
		dest[i] = src[a];
		i = i + 1;
		a = a + 1;
	}
	dest[i] = '\0';
	return (res);
}

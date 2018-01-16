/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:25:47 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/11/07 18:02:07 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;

	if (len == 0)
		return (b);
	str = (unsigned char *)b;
	while (len--)
	{
		*str = (unsigned char)c;
		if (len)
			str++;
	}
	return (b);
}

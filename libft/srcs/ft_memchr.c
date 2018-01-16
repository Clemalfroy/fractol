/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:16:32 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/11/07 15:34:53 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*cpy;

	cpy = (char*)s;
	i = -1;
	while (++i != n)
	{
		if (*cpy == (char)c)
			return (void *)(s);
		cpy++;
		s++;
	}
	return (NULL);
}

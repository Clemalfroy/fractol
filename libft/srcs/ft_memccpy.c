/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:39:32 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/11/07 18:05:09 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned int	i;

	i = -1;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	while (++i != n)
		if ((*s1++ = *s2++) == (unsigned char)c)
			return (s1);
	return (NULL);
}

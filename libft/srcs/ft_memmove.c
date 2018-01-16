/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:58:19 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/11/07 10:11:48 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *s1;
	char *s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (s2 < s1)
		while (len--)
			s1[len] = s2[len];
	else
		ft_memcpy(s1, s2, len);
	return (dst);
}

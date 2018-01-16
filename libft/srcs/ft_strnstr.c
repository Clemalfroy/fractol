/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 12:29:12 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/11/08 09:36:11 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*ptrstr1;
	char	*ptrstr2;
	int		len;

	if (*s2 == '\0')
		return ((char *)s1);
	ptrstr1 = (char *)s1;
	ptrstr2 = (char *)s2;
	len = ft_strlen(ptrstr2);
	i = 0;
	while (ptrstr1[i] != '\0' && (i + len) <= n)
	{
		if (ft_strncmp((char *)s1 + i, (char*)s2, len) == 0)
		{
			return (ptrstr1 + i);
		}
		i++;
	}
	return (NULL);
}

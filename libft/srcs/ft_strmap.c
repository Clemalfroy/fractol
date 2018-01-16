/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 08:29:45 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/11/07 19:31:04 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*cpy;
	int		i;

	i = -1;
	if (!s || !*s || !f)
		return (NULL);
	if ((cpy = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1)) == NULL)
		return (NULL);
	while (s[++i])
		cpy[i] = f(s[i]);
	cpy[i] = '\0';
	return (cpy);
}

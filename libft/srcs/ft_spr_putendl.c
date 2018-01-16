/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spr_putendl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:26:43 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/01 12:26:49 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_spr_putendl(char *s1, char *s2, char *s3, char *s4)
{
	ft_putstr(s1);
	ft_putstr(s2);
	ft_putstr(s3);
	ft_putendl(s4);
}

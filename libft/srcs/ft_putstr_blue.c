/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:57:35 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/01 12:30:58 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_blue(char *str)
{
	write(1, "\033[34;1;5m", 9);
	ft_putstr(str);
	write(1, "\033[0m", 4);
}
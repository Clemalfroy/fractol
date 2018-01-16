/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:28:22 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/09 14:26:00 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		error_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Please enter one argument", 2);
		exit(1);
	}
	if (!ft_strcmp(argv[1], "Julia") || !ft_strcmp(argv[1], "Mandelbrot") ||
			!ft_strcmp(argv[1], "Burningship") ||
			!ft_strcmp(argv[1], "Tricorn") ||
			!ft_strcmp(argv[1], "Fish"))
		;
	else
	{
		ft_putendl_fd("Invalid argument, usage : ./fractol [Julia] [Mandelbrot]"
				" [Burningship] [Tricorn] [Fish]", 2);
		exit(1);
	}
}

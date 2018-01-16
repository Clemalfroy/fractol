/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:36:50 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/09 15:55:23 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	helper(void *mlx, void *win)
{
	mlx_string_put(mlx, win, IMG_X + 10, 20, 0x0FFFFFF, "Q : Julia");
	mlx_string_put(mlx, win, IMG_X + 10, 40, 0x0FFFFFF, "W : Mandelbrot");
	mlx_string_put(mlx, win, IMG_X + 10, 60, 0x0FFFFFF, "E : Burningship");
	mlx_string_put(mlx, win, IMG_X + 10, 80, 0x0FFFFFF, "R : Tricorn");
	mlx_string_put(mlx, win, IMG_X + 10, 100, 0x0FFFFFF, "T : Fish");
	mlx_string_put(mlx, win, IMG_X + 10, 120, 0x0FFFFFF, "+ / - : Zoom");
	mlx_string_put(mlx, win, IMG_X + 10, 180, 0x0FFFFFF, "UP : Move up");
	mlx_string_put(mlx, win, IMG_X + 10, 200, 0x0FFFFFF, "Down : Move down");
	mlx_string_put(mlx, win, IMG_X + 10, 140, 0x0FFFFFF, "Left : Move Left");
	mlx_string_put(mlx, win, IMG_X + 10, 160, 0x0FFFFFF, "Right: Move Right");
	mlx_string_put(mlx, win, IMG_X + 10, 220, 0x0FFFFFF, "I : Increase preci"
			"sion");
	mlx_string_put(mlx, win, IMG_X + 10, 240, 0x0FFFFFF, "D : Decrease precisi"
			"on");
	mlx_string_put(mlx, win, IMG_X + 10, 260, 0x0FFFFFF, "C : Change color");
}

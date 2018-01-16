/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:00:37 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/09 16:25:15 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*ft_burningship(t_param *p)
{
	int			x;
	int			i;
	t_fractale	v;

	while (++p->begin < p->end && (x = -1))
		while (++x < IMG_X && (i = -1))
		{
			v.real_part = 1.5 * (x - WIN_X / 2) / (0.5 * GLA.zoom * WIN_X) +
				GLA.move_x;
			v.imaginary_part = (p->begin - WIN_Y / 2) / (0.5 * GLA.zoom * WIN_Y)
				+ GLA.move_y;
			v.new_real = 0;
			v.new_imaginary = 0;
			while (++i < GLA.max_iterations && (v.new_real * v.new_real +
						v.new_imaginary * v.new_imaginary) <= 4)
			{
				v.old_real = v.new_real;
				v.old_imaginary = v.new_imaginary;
				v.new_real = ABS(v.old_real * v.old_real - v.old_imaginary *
					v.old_imaginary + v.real_part);
				v.new_imaginary = ABS(2 * v.old_real * v.old_imaginary + v.I);
			}
			ft_put_pixel(p->env, x, p->begin, i * GLA.color);
		}
	pthread_exit(NULL);
}

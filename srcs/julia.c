/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:00:37 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/09 16:07:11 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		*ft_dup(t_env *env)
{
	t_env			*new;

	if ((new = malloc(sizeof(t_env))) == NULL)
		exit(1);
	new->mlx = env->mlx;
	new->img = env->img;
	new->win = env->win;
	new->i_img = env->i_img;
	new->bpp = env->bpp;
	new->size_l = env->size_l;
	new->endian = env->endian;
	new->arg = env->arg;
	new->y = env->y;
	new->x = env->x;
	new->julia.c_real = env->julia.c_real;
	new->julia.c_imaginary = env->julia.c_imaginary;
	new->julia.zoom = env->julia.zoom;
	new->julia.move_x = env->julia.move_x;
	new->julia.move_y = env->julia.move_y;
	new->julia.color = env->julia.color;
	new->julia.max_iterations = env->julia.max_iterations;
	return (new);
}

void		ft_print_threads(t_env *env)
{
	pthread_t	t[THREADS];
	int			i;
	t_param		o[THREADS];

	i = -1;
	while (++i < THREADS)
	{
		o[i].env = ft_dup(env);
		o[i].begin = (WIN_Y / THREADS) * i;
		o[i].end = (WIN_Y / THREADS) * (i + 1) + 1;
		if (!ft_strcmp(env->arg, "Julia"))
			pthread_create(t + i, NULL, (void *(*)(void *))ft_julia, O);
		else if (!ft_strcmp(env->arg, "Mandelbrot"))
			pthread_create(t + i, NULL, (void *(*)(void *))ft_mandelbrot, O);
		else if (!ft_strcmp(env->arg, "Burningship"))
			pthread_create(t + i, NULL, (void *(*)(void *))ft_burningship, O);
		else if (!ft_strcmp(env->arg, "Tricorn"))
			pthread_create(t + i, NULL, (void *(*)(void *))ft_tricorn, O);
		else if (!ft_strcmp(env->arg, "Fish"))
			pthread_create(t + i, NULL, (void *(*)(void *))ft_fish, O);
	}
	while (i-- && pthread_join(t[i], NULL) == 0)
		free(o[i].env);
}

void		*ft_julia(t_param *p)
{
	int			x;
	int			i;
	t_fractale	v;

	while (++p->begin < p->end && (x = -1))
		while (++x < IMG_X && (i = -1))
		{
			v.new_real = 1.5 * (x - IMG_X / 2) / (0.5 * GLA.zoom * IMG_X) +
				GLA.move_x;
			v.new_imaginary = (p->begin - IMG_Y / 2) / (0.5 * GLA.zoom * IMG_Y)
				+ GLA.move_y;
			i = -1;
			while (++i < GLA.max_iterations && (v.new_real * v.new_real +
						v.new_imaginary * v.new_imaginary) <= 4)
			{
				v.old_real = v.new_real;
				v.old_imaginary = v.new_imaginary;
				v.new_real = v.old_real * v.old_real - v.old_imaginary
					* v.old_imaginary + GLA.c_real;
				v.new_imaginary = 2 * v.old_real * v.old_imaginary +
					GLA.c_imaginary;
			}
			ft_put_pixel(p->env, x, p->begin, i * GLA.color);
		}
	pthread_exit(NULL);
}

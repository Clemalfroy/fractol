/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:24:57 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/09 15:39:01 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_env(t_env *env, char **argv)
{
	ft_memset(env, 0, sizeof(t_env));
	if ((env->mlx = mlx_init()) == NULL)
		exit(1);
	if ((env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, argv[0])) == NULL)
		exit(1);
	if ((env->img = mlx_new_image(env->mlx, IMG_X, IMG_Y)) == NULL)
		exit(1);
	env->arg = ft_strdup(argv[1]);
	env->i_img = mlx_get_data_addr(env->img, &env->bpp, &env->size_l,
			&env->endian);
	JLA.zoom = 0.5;
	if (!ft_strcmp(env->arg, "Julia"))
		JLA.max_iterations = 150;
	else
		JLA.max_iterations = 75;
	JLA.move_x = 0;
	JLA.move_y = 0;
	JLA.c_real = -0.715;
	JLA.c_imaginary = -0.27015;
	JLA.color = 189;
}

void	ft_put_pixel(t_env *env, int x, int y, int color)
{
	if (y >= WIN_Y || x >= WIN_X || x < 0 || y < 0)
		return ;
	*(int *)&env->i_img[(y * env->size_l) + (x * (env->bpp / 8))] = color;
}

int		main(int argc, char **argv)
{
	t_env	env;

	error_arg(argc, argv);
	init_env(&env, argv);
	mlx_hook(env.win, KEYRELEASE, KEYRELEASEMASK, ft_keyrelease, &env);
	mlx_hook(env.win, KEYPRESS, KEYPRESSMASK, ft_keypress, &env);
	mlx_hook(env.win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_mouse_motion, &env);
	mlx_mouse_hook(env.win, mouse_hook, &env);
	mlx_loop_hook(env.mlx, no_event, &env);
	mlx_loop(env.mlx);
	return (0);
}

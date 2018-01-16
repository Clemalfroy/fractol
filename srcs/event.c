/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:08:35 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/09 16:19:32 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (button == 1 || button == 5)
		JLA.zoom += JLA.zoom * 0.1;
	if (button == 2 || button == 4)
		JLA.zoom += JLA.zoom * -0.1;
	return (0);
}

int		ft_keyrelease(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
	{
		free(env->arg);
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		exit(1);
	}
	return (0);
}

int		ft_keypress(int k, t_env *env)
{
	if (k == KEY_W || k == KEY_Q || k == KEY_E || k == KEY_R || k == KEY_T)
		free(env->arg);
	if (k == KEY_PLUS || k == KEY_MINUS)
		JLA.zoom += k == KEY_PLUS ? 0.1 * JLA.zoom : -0.1 * JLA.zoom;
	else if (k == KEY_C)
		JLA.color = JLA.color < 24772608 ? JLA.color += 1500 : 189;
	else if (k == KEY_I)
		JLA.max_iterations += 2;
	else if (k == KEY_D)
		JLA.max_iterations -= JLA.max_iterations > 2 ? 2 : 0;
	else if (k == KEY_Q && (JLA.zoom = 0.5))
		env->arg = ft_strdup("Julia");
	else if (k == KEY_W && (JLA.zoom = 0.5))
		env->arg = ft_strdup("Mandelbrot");
	else if (k == KEY_E && (JLA.zoom = 0.5))
		env->arg = ft_strdup("Burningship");
	else if (k == KEY_R && (JLA.zoom = 0.5))
		env->arg = ft_strdup("Tricorn");
	else if (k == KEY_T && (JLA.zoom = 0.5))
		env->arg = ft_strdup("Fish");
	k == KEY_UP ? JLA.move_y -= 0.03 / JLA.zoom : 0;
	k == KEY_LEFT ? JLA.move_x -= 0.03 / JLA.zoom : 0;
	k == KEY_RIGHT ? JLA.move_x += 0.03 / JLA.zoom : 0;
	k == KEY_DOWN ? JLA.move_y += 0.03 / JLA.zoom : 0;
	return (0);
}

int		ft_mouse_motion(int x, int y, t_env *env)
{
	if (!ft_strcmp(env->arg, "Julia"))
	{
		if (x > env->x)
			JLA.c_imaginary += 0.005 / JLA.zoom;
		if (x < env->x)
			JLA.c_imaginary -= 0.005 / JLA.zoom;
		if (y > env->y)
			JLA.c_real += 0.005 / JLA.zoom;
		if (y > env->y)
			JLA.c_real -= 0.005 / JLA.zoom;
		env->x = x;
		env->y = y;
	}
	return (0);
}

int		no_event(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_clear_window(env->mlx, env->win);
	env->img = mlx_new_image(env->mlx, IMG_X, IMG_Y);
	ft_print_threads(env);
	helper(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

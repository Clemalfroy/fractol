/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:22:17 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/09 16:22:41 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "utility.h"
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <pthread.h>
# include <semaphore.h>

# define WIN_X 1250
# define IMG_X 1000
# define WIN_Y 600
# define IMG_Y 600
# define GLA p->env->julia
# define JLA env->julia
# define ABS(x) ((x) < 0 ? -(x) : (x))
# define THREADS 16
# define I imaginary_part
# define O o + i

/*
 ** Definition de la structure pour draw Julia;
*/

typedef struct	s_fractale
{
	double		new_real;
	double		old_imaginary;
	double		old_real;
	double		new_imaginary;
	double		real_part;
	double		imaginary_part;
}				t_fractale;

typedef struct	s_julia
{
	double		c_real;
	double		c_imaginary;
	double		zoom;
	double		move_x;
	double		move_y;
	int			color;
	int			max_iterations;
}				t_julia;

/*
 ** Definition de la structure d'environnement;
*/

typedef struct	s_env
{
	void		*mlx;
	void		*win;

	void		*img;
	char		*i_img;
	int			bpp;
	int			size_l;
	int			endian;

	char		*arg;

	int			x;
	int			y;

	t_julia		julia;
}				t_env;

typedef struct	s_param
{
	int			begin;
	int			end;
	t_env		*env;
}				t_param;

/*
 ** Fontion d'affichage sur l'ecran;
*/

void			helper(void *mlx, void *win);
void			ft_print_threads(t_env *env);
void			*ft_julia(t_param *p);
void			*ft_mandelbrot(t_param *p);
void			*ft_burningship(t_param *p);
void			*ft_tricorn(t_param *p);
void			*ft_fish(t_param *p);
void			ft_put_pixel(t_env *env, int x, int y, int color);

/*
 ** Fontion de gestion d'event;
*/

int				no_event(t_env *env);
int				ft_keyrelease(int keycode, t_env *env);
int				ft_keypress(int keycode, t_env *env);
int				ft_mouse_motion(int x, int y, t_env *env);
int				mouse_hook(int button, int x, int y, t_env *env);

/*
 ** Fontion de gestion d'erreur;
*/

void			error_arg(int argc, char **argv);

#endif

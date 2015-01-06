/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 19:08:20 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/06 11:01:55 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	manage_arrows(int keycode, t_env *env)
{
	if (keycode == 65361)
		env->camera->point->x -= 1;
	else if (keycode == 65362)
		env->camera->point->y += 1;
	else if (keycode == 65363)
		env->camera->point->x += 1;
	else if (keycode == 65364)
		env->camera->point->y -= 1;
	else if (keycode == 59)
		env->camera->point->z += 1;
	else if (keycode == 47)
		env->camera->point->z -= 1;
	else
		return (0);
	return (1);
}

static int	manage_wasd(int keycode, t_env *env)
{
	if (keycode == 113)
		env->camera->z_ang += DEGREE;
	else if (keycode == 119)
		env->camera->x_ang -= DEGREE;
	else if (keycode == 101)
		env->camera->z_ang -= DEGREE;
	else if (keycode == 97)
		env->camera->y_ang -= DEGREE;
	else if (keycode == 115)
		env->camera->x_ang += DEGREE;
	else if (keycode == 100)
		env->camera->y_ang += DEGREE;
	else
		return (0);
	return (1);
}

static int	manage_other(int keycode, t_env *env)
{
	if (keycode == 45)
		env->camera->zoom -= 1;
	else if (keycode == 61)
		env->camera->zoom += 1;
	else if (keycode == 49)
		env->camera->z_shift -= 1;
	else if (keycode == 50)
		env->camera->z_shift += 1;
	else if (keycode == 51)
		env->camera->gradient -= 1;
	else if (keycode == 52)
		env->camera->gradient += 1;
	else
		return (0);
	return (1);
}

int			fdf_key_hook(int keycode, void *env_ptr)
{
	t_env	*env;

	env = env_ptr;
	if (keycode == 65307)
		exit(0);
	else if (manage_arrows(keycode, env))
		ft_putstr("Arrow ");
	else if (manage_wasd(keycode, env))
		ft_putstr("WASD ");
	else if (manage_other(keycode, env))
		ft_putstr("Other ");
	else
		return (0);
	write(1, "Key: ", 5);
	ft_putnbr(keycode);
	write(1, "\n", 1);
	ft_putstr("Regen: Camera Map... ");
	trans_fdf_map(env->cam_map, env->map, env->camera);
	ft_putstr("Clear Image... ");
	fdf_clear_img(env->win);
	ft_putstr("Redrawing Image... ");
	fdf_cam_img(env->cam_map, env->win);
	ft_putendl("done.");
	return (0);
}

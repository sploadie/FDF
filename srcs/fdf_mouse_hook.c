/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 19:08:20 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/04 13:59:13 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_mouse_hook(int button, int x, int y, void *env_ptr)
{
	t_env	*env;

	env = env_ptr;
	if (button == 1)
	{
		ft_putstr("Mouse: Left Click @ x: ");
		ft_putnbr(x);
		write(1, ", y: ", 5);
		ft_putnbr(y);
		write(1, "\n", 1);
	}
	else if (button == 7)
	{
		ft_putendl("Scroll Left");
		env->camera->point->x -= 1;
	}
	else if (button == 6)
	{
		ft_putendl("Scroll Right");
		env->camera->point->x += 1;
	}
	else if (button == 5)
	{
		ft_putendl("Scroll Up");
		env->camera->point->y += 1;
	}
	else if (button == 4)
	{
		ft_putendl("Scroll Down");
		env->camera->point->y -= 1;
	}
	else
	{
		write(1, "Mouse: ", 5);
		ft_putnbr(button);
		write(1, "\t@ x: ", 6);
		ft_putnbr(x);
		write(1, ", y: ", 5);
		ft_putnbr(y);
		write(1, "\n", 1);
		return(0);
	}
	ft_putstr("Regen: Camera Map... ");
	trans_fdf_map(env->cam_map, env->map, env->camera);
	ft_putstr("Clear Image... ");
	fdf_clear_img(env->win);
	ft_putstr("Redrawing Image... ");
	fdf_cam_img(env->cam_map, env->win);
	ft_putendl("done.");
	return (0);
}
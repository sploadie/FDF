/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 19:08:20 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/06 11:07:21 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_mouse_hook(int button, int x, int y, void *env_ptr)
{
	t_env	*env;

	env = env_ptr;
	(void)x;
	(void)y;
	if (button == 1)
		ft_putendl("Mouse: Left Click");
	else if (button == 7)
		env->camera->point->x -= 1;
	else if (button == 6)
		env->camera->point->x += 1;
	else if (button == 5)
		env->camera->point->y += 1;
	else if (button == 4)
		env->camera->point->y -= 1;
	else
		return (0);
	ft_putstr("Regen: Camera Map... ");
	trans_fdf_map(env->cam_map, env->map, env->camera);
	ft_putstr("Clear Image... ");
	fdf_clear_img(env->win);
	ft_putstr("Redrawing Image... ");
	fdf_cam_img(env->cam_map, env->win);
	ft_putendl("done.");
	return (0);
}

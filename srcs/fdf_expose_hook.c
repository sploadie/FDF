/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_expose_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 19:08:20 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/04 10:49:38 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_expose_hook(void *env_ptr)
{
	t_env	*env;

	env = env_ptr;
	ft_putendl("Expose hook hit!");

	//Generate initial camera image
	ft_putendl("Implementing camera map to new image...");
	new_fdf_img(env->win);
	fdf_cam_img(env->cam_map, env->win);

	return (0);
}
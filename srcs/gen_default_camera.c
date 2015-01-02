/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_default_camera.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 18:31:04 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/02 19:00:52 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

t_fdf_cam	*gen_default_camera(void)
{
	t_fdf_cam	*neocam;

	neocam = check_malloc(malloc(sizeof(t_fdf_cam)));
	neocam->point = new_3d_point(0, 0, 10);
	neocam->x_ang = 0;
	neocam->y_ang = 0;
	neocam->z_ang = 0;
	return (neocam);
}

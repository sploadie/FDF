/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_3d_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:21:33 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/12/12 18:25:25 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trans_3d_point(t_3d_point *dest, t_3d_point *src, t_fdf_cam *cam)
{
	double		rot_x;
	double		rot_y;
	double		rot_z;
	double		temp;

	rot_x = (double)(src->x - cam->point->x);
	rot_y = (double)(src->y - cam->point->y);
	rot_z = (double)(src->z - cam->point->z);
	temp = rot_y;
	rot_y = (rot_y * cos(cam->x_ang)) - (rot_z * sin(cam->x_ang));
	rot_z = (temp * sin(cam->x_ang)) + (rot_z * cos(cam->x_ang));
	rot_z = (rot_z * cos(cam->y_ang)) - (rot_x * sin(cam->y_ang));
	rot_x = (rot_x * cos(cam->y_ang)) + (rot_z * cos(cam->y_ang));
	temp = rot_x;
	rot_x = (rot_x * cos(cam->z_ang)) - (rot_y * sin(cam->z_ang));
	rot_y = (temp * sin(cam->z_ang)) + (rot_y * cos(cam->z_ang));
	dest->x = (int)rot_x;
	dest->y = (int)rot_y;
	dest->z = (int)rot_z;
}

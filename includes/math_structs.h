/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 19:47:30 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/06 10:25:51 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_STRUCTS_H
# define MATH_STRUCTS_H

typedef struct			s_3d_point
{
	int					x;
	int					y;
	int					z;
	float				origin_z;
}						t_3d_point;

typedef struct			s_fdf_cam
{
	t_3d_point			*point;
	double				x_ang;
	double				y_ang;
	double				z_ang;
	int					z_shift;
	int					gradient;
	int					zoom;
}						t_fdf_cam;

typedef struct			s_fdf_map
{
	t_3d_point			***grid;
	size_t				width;
	size_t				height;
}						t_fdf_map;

#endif

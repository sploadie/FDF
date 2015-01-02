/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 19:47:30 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/02 19:04:51 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_STRUCTS_H
# define MATH_STRUCTS_H

typedef struct			s_3d_point
{
	int					x;
	int					y;
	int					z;
}						t_3d_point;


typedef struct			s_fdf_cam
{
	t_3d_point			*point;
	float				x_ang;
	float				y_ang;
	float				z_ang;
}						t_fdf_cam;

typedef struct			s_fdf_map
{
	t_3d_point			***grid;
	size_t				width;
	size_t				height;
}						t_fdf_map;

#endif

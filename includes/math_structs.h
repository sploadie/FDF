/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 19:47:30 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/12/14 11:25:00 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_STRUCTS_H
# define MATH_STRUCTS_H

# define FDF_MAP_BUF 10

typedef struct			s_3d_point
{
	int					x;
	int					y;
	int					z;
}						t_3d_point;


typedef struct			s_fdf_cam
{
	struct s_3d_point	*point;
	float				x_angle;
	float				y_angle;
	float				z_angle;
}						t_fdf_cam;

typedef struct			s_fdf_map
{
	t_3d_point			***grid;
	size_t				width;
	size_t				height;
}						t_fdf_map;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cam_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 21:02:52 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/04 12:50:22 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_cam_img(t_fdf_map *map, t_fdf_win *win)
{
	size_t		i;
	size_t		j;
	size_t		width;
	size_t		height;
	// t_3d_point	***grid;

	// grid = map->grid;
	width = map->width;
	height = map->height;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
			draw_map_point_lines(j++, i, map, win);
			//draw_3d_point(grid[i][j++], win);
		i++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}

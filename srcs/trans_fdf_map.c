/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_fdf_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:05:59 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/12/14 11:13:04 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf_map	*to_new(t_fdf_map *dest, t_fdf_map *src, t_fdf_cam *cam)
{
	t_3d_point	***grid;
	size_t		i;
	size_t		j;
	size_t		width;
	size_t		height;

	width = src->width;
	height = src->height;
	grid = check_malloc(malloc(sizeof(t_3d_point **) * height));
	i = -1;
	while (++i < height)
	{
		grid[i] = check_malloc(malloc(sizeof(t_3d_point *) * width));
		j = -1;
		while (++j < width)
		{
			grid[i][j] = check_malloc(malloc(sizeof(t_3d_point)));
			trans_3d_point(grid[i][j], src->grid[i][j], cam);
		}
	}
	dest->width = width;
	dest->height = height;
	dest->grid = grid;
	return (dest);
}

static t_fdf_map	*to_copy(t_fdf_map *dest, t_fdf_map *src, t_fdf_cam *cam)
{
	t_3d_point	***grid;
	size_t		i;
	size_t		j;
	size_t		width;
	size_t		height;

	width = src->width;
	height = src->height;
	grid = dest->grid;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			trans_3d_point(grid[i][j], src->grid[i][j], cam);
	}
	dest->width = width;
	dest->height = height;
	dest->grid = grid;
	return (dest);
}

void				trans_fdf_map(t_fdf_map **dest, t_fdf_map *src, t_fdf_cam *cam)
{
	if (!*dest)
		return (to_new(*dest, src, cam));
	return (to_copy(*dest, src, cam));
}

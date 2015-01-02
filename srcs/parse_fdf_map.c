/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:05:01 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/02 20:30:26 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	read_fdf_map_row(t_3d_point **row, int y, size_t width, char *line)
{
	size_t			i;
	size_t			count;

	count = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && (i == 0 || line[i - 1] == ' '))
		{
			if (count == width)
				fdf_error("read_fdf_map_row_a");
			set_3d_point(row[count], count, y, ft_atoi(line + i));
			count++;
		}
		i++;
	}
	if (count != width)
		fdf_error("read_fdf_map_row_b");
}

static void	read_fdf_map(t_fdf_map *map, int map_fd)
{
	int			ret;
	char		*line;
	size_t		i;

	line = NULL;
	i = 0;
	while (i < map->height - 1)
	{
		ret = get_next_line(map_fd, &line);
		if (ret < 1)
			fdf_error("read_fdf_map");
		read_fdf_map_row(map->grid[i], i, map->width, line);
		i++;
	}
}

t_fdf_map	*parse_fdf_map(char *path)
{
	t_fdf_map	*map;
	int			map_fd;

	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		fdf_error("parse_fdf_map");
	map = fdf_map(get_file_width(path), get_file_height(path));
	read_fdf_map(map, map_fd);
	close(map_fd);
	return (map);
}

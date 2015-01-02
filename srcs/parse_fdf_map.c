/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:05:39 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/12/11 18:56:39 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static char		**wary_init(char const *s)
// {
// 	size_t			i;
// 	size_t			beg;
// 	char			**wary;
// 	size_t			wcount;

// 	wcount = 0;
// 	beg = -1;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == ' ')
// 		{
// 			if (beg != i - 1)
// 				wcount++;
// 			beg = i;
// 		}
// 		i++;
// 	}
// 	if (beg != i - 1)
// 		wcount++;
// 	wary = check_malloc(malloc((wcount + 1) * sizeof(int)));
// 	wary[wcount] = NULL;
// 	return (wary);
// }

// int		**int_space_split(char *s)
// {
// 	size_t			i;
// 	size_t			beg;
// 	int				**wary;
// 	size_t			wcount;

// 	wary = wary_init(s);
// 	wcount = 0;
// 	beg = -1;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == ' ')
// 		{
// 			if (beg != i - 1)
// 				wary[wcount++] = ft_atoi(s + beg + 1);
// 			beg = i;
// 		}
// 		i++;
// 	}
// 	if (beg != i - 1)
// 		wary[wcount++] = ft_atoi(s + beg + 1);
// 	return (wary);
// }

// static size_t		get_width(char *s)
// {
// 	size_t			i;
// 	size_t			wcount;

// 	wcount = 0;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
// 			wcount++;
// 		i++;
// 	}
// 	if (!wcount)
// 		fdf_error("Map");
// 	return (wcount);
// }

// static int			**get_row(char *s, size_t width)
// {
// 	size_t			i;
// 	int				*array;
// 	size_t			count;

// 	array = check_malloc(malloc(sizeof(int) * width));
// 	count = 0;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
// 		{
// 			if (count == width)
// 				fdf_error("Map");
// 			array[count++] = ft_atoi(s + i);
// 		}
// 		i++;
// 	}
// 	if (count != width)
// 		fdf_error("Map");
// 	return (array);
// }

// static t_arraylist	*get_grid(int fd, int ret, char *line, size_t width)
// {
// 	t_arraylist	*grid;

// 	grid = check_malloc(arraylist(get_row(line), FDF_MAP_BUF));
// 	free(line);
// 	if (!ret)
// 		return (grid);
// 	while (ret)
// 	{
// 		ret = get_next_line(fd, &line);
// 		if (ret == -1)
// 			fdf_error("Map");
// 		grid->push(grid, get_row(line, width));
// 		free(line);
// 	}
// 	return (grid);
// }

// static void			grid_points(t_3d_point ***grid, t_arlst_iter *iter, size_t width, size_t height)
// {
// 	size_t		i;
// 	int			ret;

// 	ret = 1;
// 	i = 0;
// 	while (ret)
// 	{
// 		grid[i] = get_row(iter->pip(iter, &ret), height - i);
// 		i++;
// 	}
// }

// t_fdf_map			*parse_fdf_map(int	fd)
// {
// 	int			ret;
// 	char		*first;
// 	t_fdf_map	*map;
// 	t_arraylist	*int_grid;

// 	//Grab first line
// 	first = NULL;
// 	ret = get_next_line(fd, &line);
// 	if (ret < 0)
// 		fdf_error(NULL);
// 	//Determine width
// 	map = check_malloc(malloc(sizeof(t_fdf_map)));
// 	map->width = get_width(first);
// 	//Parse first line
// 	//Use arraylist to grab all lines
// 	if (ret)
// 		int_grid = get_grid(fd, ret, first, map->width);
// 	else
// 		int_grid = check_malloc(arraylist(first, FDF_MAP_BUF));
// 	//Get height
// 	map->height = int_grid->size(int_grid);
// 	//Copy arraylist to a 'static' array of 3d points
// 	map->grid = check_malloc(malloc(sizeof(t_3d_point **) * map->height));
// 	grid_points(map->grid, check_malloc(arlst_iter(int_grid)), map->width, map->height);
// 	//Return map
// 	return (map);
// }

static size_t		get_width(char *s)
{
	size_t			i;
	size_t			wcount;

	wcount = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
			wcount++;
		i++;
	}
	if (!wcount)
		fdf_error("Map");
	return (wcount);
}

static int			**get_row(char *s, size_t width)
{
	size_t			i;
	int				*array;
	size_t			count;

	array = check_malloc(malloc(sizeof(int) * width));
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
		{
			if (count == width)
				fdf_error("Map");
			array[count++] = ft_atoi(s + i);
		}
		i++;
	}
	if (count != width)
		fdf_error("Map");
	return (array);
}

static t_arraylist	*get_grid(int fd, int ret, char *line, size_t width)
{
	t_arraylist	*grid;

	grid = check_malloc(arraylist(get_row(line), FDF_MAP_BUF));
	free(line);
	if (!ret)
		return (grid);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			fdf_error("Map");
		grid->push(grid, get_row(line, width));
		free(line);
	}
	return (grid);
}

static void			grid_points(t_3d_point ***grid, t_arlst_iter *iter, size_t width, size_t height)
{
	size_t		i;
	int			ret;

	ret = 1;
	i = 0;
	while (ret)
	{
		grid[i] = get_row(iter->pip(iter, &ret), height - i);
		i++;
	}
}

//Open the map file
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		fdf_error(NULL);

t_fdf_map			*parse_fdf_map(char *path)
{
	int			ret;
	t_fdf_map	*map;

	map = check_malloc(malloc(sizeof(t_fdf_map)));
	map->height = get_file_height(path);
}

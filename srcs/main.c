/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 16:23:47 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/08 09:22:32 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_win	*first_window(void *mlx, int argnum, char **argv)
{
	t_fdf_win	*win;

	if (argnum < 2)
		win = gen_mlx_window(mlx, DEF_TITLE, DEF_X, DEF_Y);
	else if (argnum == 2)
		win = gen_mlx_window(mlx, DEF_TITLE, ft_atoi(argv[1]), ft_atoi(argv[1]));
	else if (argnum == 3)
		win = gen_mlx_window(mlx,
			DEF_TITLE, ft_atoi(argv[1]), ft_atoi(argv[2]));
	else if (argnum == 4)
		win = gen_mlx_window(mlx,
			argv[3], ft_atoi(argv[1]), ft_atoi(argv[2]));
	if (!win)
		fdf_error(NULL);
	return (win);
}

/*
int			real_main(int argc, char **argv)
{
	void		*mlx;
	t_fdf_win	*win;
	t_fdf_map	*map;
	t_fdf_cam	*camera;
	t_fdf_map	*cam_map;

	//Need at least map
	if (argc < 2)
	{
		ft_putstr("Usage: FDF [Map] [Size || X Size] [Y Size] [Title]\n");
		return (0);
	}

	//Get the mlx pointer;
	mlx = mlx_init();
	if (!mlx)
		fdf_error(NULL);

	//Generate the window
	if (argc == 2)
		win = first_window(mlx, argc - 1, NULL);
	else
		win = first_window(mlx, argc - 1, argv + 1);

	//Open the map file
	//Read and parse to new map
	map = parse_fdf_map(argv[1]);

	//Create camera
	camera = gen_default_camera();
	cam_map = NULL;
	trans_fdf_map(&cam_map, map, camera);

	//Generate initial camera image
	new_fdf_img(win);
	fdf_cam_img(cam_map, win);

	//Give window the camera image
	mlx_put_image_to_window (mlx, win->win, win->img, 0, 0);

	//Hooks and loop

	//Exit
	return (0);
}
*/

void		print_debug_map(t_fdf_map *map)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			write(1, "(", 1);
			print_sp_left(ft_itoa(map->grid[i][j]->x), 3);
			write(1, ",", 1);
			print_sp_left(ft_itoa(map->grid[i][j]->y), 3);
			write(1, ",", 1);
			print_sp_left(ft_itoa(map->grid[i][j]->z), 3);
			write(1, ") ", 2);
			// write(1, "\t", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void		print_debug_z_map(t_fdf_map *map)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			print_sp_left(ft_itoa(map->grid[i][j]->z), 5);
			write(1, "  ", 2);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int			main(int argc, char **argv)
{
	void		*mlx;
	t_fdf_win	*win;
	t_fdf_map	*map;
	t_fdf_cam	*camera;
	t_fdf_map	*cam_map;
	t_env		env;

	//Need at least map
	if (argc < 2)
	{
		ft_putstr("Usage: FDF [Map] [Size || X Size] [Y Size] [Title]\n");
		return (0);
	}

	//Get the mlx pointer;
	ft_putendl("Initializing MLX...");
	mlx = mlx_init();
	if (!mlx)
		fdf_error(NULL);

	//Generate the window
	ft_putendl("Creating window...");
	if (argc == 2)
		win = first_window(mlx, argc - 1, NULL);
	else
		win = first_window(mlx, argc - 1, argv + 1);

	//Get Map
	ft_putendl("Parsing map file...");
	map = parse_fdf_map(argv[1]);

	//Print Map
	ft_putendl("Original Map:");
	print_debug_map(map);

	//Gen Camera
	//Gen empty map for camera
	//Transform map -> camera map.
	camera = gen_default_camera();
	cam_map = fdf_map(map->width, map->height);
	trans_fdf_map(cam_map, map, camera);

	//Print Camera Map
	ft_putendl("Camera Map:");
	print_debug_map(cam_map);

	//Set up environment for hooks
	env.win = win;
	env.map = map;
	env.camera = camera;
	env.cam_map = cam_map;

	//Set up hooks and initialize loop
	mlx_key_hook(win->win, fdf_key_hook, &env);
	mlx_mouse_hook(win->win, fdf_mouse_hook, &env);
	mlx_expose_hook(win->win, fdf_expose_hook, &env);
	// mlx_loop_hook(mlx, fdf_loop_hook, &env);
	mlx_loop(mlx);

	sleep(2000);
	return (0);
}

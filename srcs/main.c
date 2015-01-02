/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 16:23:47 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/12/14 11:36:21 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		first_window(void *mlx, int argnum, char **argv)
{
	t_fdf_win	*win;

	if (argnum < 2)
		win = gen_mlx_window(mlx, DEF_TITLE, DEF_X, DEF_Y);
	else if (argnum == 2)
		win = gen_mlx_window(mlx, DEF_TITLE, argv[1], argv[1]);
	else if (argnum == 3)
		win = gen_mlx_window(mlx,
			DEF_TITLE, ft_atoi(argv[1]), ft_atoi(argv[2]));
	else if (argnum == 4)
		win = gen_mlx_window(mlx,
			argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	if (!win)
		fdf_error(NULL);
	return (win);
}

int		main(int argc, char **argv)
{
	void		*mlx;
	t_fdf_win	*win;
	int			map_fd;
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

	//Open the map file
	map_path = argv[1];

	//Read and parse the map -> lines
	map = parse_fdf_map(map_path);

	//Create camera
	camera = gen_default_camera();
	cam_map = NULL;
	trans_fdf_map(&cam_map, map, camera);

	//Generate the window
	if (argc == 2)
		win = first_window(mlx, argc - 1, NULL);
	else
		win = first_window(mlx, argc - 1, argv + 1);

	//Generate initial camera image
	new_fdf_img(win);
	fdf_cam_img(t_fdf_cam, win);

	//Give window the camera image
	mlx_put_image_to_window (mlx, win->win, win->img, 0, 0);

	//Hooks and loop

	//Exit
	return (0);
}
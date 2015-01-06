/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 19:08:20 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/04 17:08:03 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void		debug_z_map(t_fdf_map *map)
// {
// 	size_t		i;
// 	size_t		j;

// 	i = 0;
// 	while (i < map->height)
// 	{
// 		j = 0;
// 		while (j < map->width)
// 		{
// 			print_sp_left(ft_itoa(map->grid[i][j]->z), 5);
// 			write(1, "  ", 2);
// 			j++;
// 		}
// 		write(1, "\n", 1);
// 		i++;
// 	}
// }

int		fdf_key_hook(int keycode, void *env_ptr)
{
	t_env	*env;

	env = env_ptr;
	if (keycode == 65307)
	{
		//Exit if Esc
		ft_putendl("Esc");
		exit(0);
	}
	else if (keycode == 65361)
	{
		ft_putendl("Arrow Left");
		env->camera->point->x -= 1;
	}
	else if (keycode == 65362)
	{
		ft_putendl("Arrow Up");
		env->camera->point->y += 1;
	}
	else if (keycode == 65363)
	{
		ft_putendl("Arrow Right");
		env->camera->point->x += 1;
	}
	else if (keycode == 65364)
	{
		ft_putendl("Arrow Down");
		env->camera->point->y -= 1;
	}
	else if (keycode == 59)
	{
		ft_putendl("Key ;");
		env->camera->point->z += 1;
	}
	else if (keycode == 47)
	{
		ft_putendl("Key /");
		env->camera->point->z -= 1;
	}
	else if (keycode == 113)
	{
		ft_putendl("Key Q");
		env->camera->z_ang += DEGREE;
	}
	else if (keycode == 119)
	{
		ft_putendl("Key W");
		env->camera->x_ang -= DEGREE;
	}
	else if (keycode == 101)
	{
		ft_putendl("Key E");
		env->camera->z_ang -= DEGREE;
	}
	else if (keycode == 97)
	{
		ft_putendl("Key A");
		env->camera->y_ang -= DEGREE;
	}
	else if (keycode == 115)
	{
		ft_putendl("Key S");
		env->camera->x_ang += DEGREE;
	}
	else if (keycode == 100)
	{
		ft_putendl("Key D");
		env->camera->y_ang += DEGREE;
	}
	else if (keycode == 45)
	{
		ft_putendl("Key -/_");
		env->camera->zoom -= 1;
	}
	else if (keycode == 61)
	{
		ft_putendl("Key =/+");
		env->camera->zoom += 1;
	}
	else if (keycode == 49)
	{
		ft_putendl("Key 1");
		env->camera->z_shift -= 1;
	}
	else if (keycode == 50)
	{
		ft_putendl("Key 2");
		env->camera->z_shift += 1;
	}
	else if (keycode == 51)
	{
		ft_putendl("Key 3");
		env->camera->gradient -= 1;
	}
	else if (keycode == 52)
	{
		ft_putendl("Key 4");
		env->camera->gradient += 1;
	}
	else
	{
		write(1, "Key: ", 5);
		ft_putnbr(keycode);
		write(1, "\n", 1);
		return(0);
	}
	ft_putstr("Regen: Camera Map... ");
	trans_fdf_map(env->cam_map, env->map, env->camera);
	// debug_z_map(env->cam_map);
	ft_putstr("Clear Image... ");
	fdf_clear_img(env->win);
	ft_putstr("Redrawing Image... ");
	fdf_cam_img(env->cam_map, env->win);
	ft_putendl("done.");
	return (0);
}
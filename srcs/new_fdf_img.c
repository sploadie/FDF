/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fdf_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 11:32:48 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/03 17:06:24 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_fdf_img(t_fdf_win *win)
{
	win->img = mlx_new_image(win->mlx, win->width, win->height);
	win->img_bits_per_pixel = 0;
	win->img_size_line = 0;
	win->img_endian = 0;
	win->img_data = (int *)mlx_get_data_addr(win->img,
									&(win->img_bits_per_pixel),
									&(win->img_size_line),
									&(win->img_endian));
	// if (win->img_bits_per_pixel != 8)
	// 	fdf_error("new_fdf_img");
	// if (win->img_endian != 1)
	// 	fdf_error("new_fdf_img");
	// if ((unsigned int)win->img_size_line != win->width * 8)
	// 	fdf_error("new_fdf_img");
	ft_putstr("img_bits_per_pixel: ");//FIXME
	ft_putendl(ft_itoa(win->img_bits_per_pixel));//FIXME
	ft_putstr("img_endian: ");//FIXME
	ft_putendl(ft_itoa(win->img_endian));//FIXME
	ft_putstr("img_size_line: ");//FIXME
	ft_putendl(ft_itoa(win->img_size_line));//FIXME
}

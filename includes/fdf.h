/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 16:14:35 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/06 12:58:27 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "arraylist.h"
# include "math_structs.h"

# define DEF_TITLE "FDF Main Window"
# define DEF_X 800
# define DEF_Y 800

# define DEGREE 0.0174532925

typedef struct		s_fdf_win
{
	void			*mlx;
	void			*win;
	char			*title;
	size_t			width;
	size_t			height;
	void			*img;
	int				*img_data;
	int				img_bits_per_pixel;
	int				img_size_line;
	int				img_endian;
}					t_fdf_win;

typedef struct		s_env
{
	t_fdf_win		*win;
	t_fdf_map		*map;
	t_fdf_cam		*camera;
	t_fdf_map		*cam_map;
}					t_env;

void				fdf_error(char *str);
void				*check_malloc(void *ret);
int					get_next_line(int fd, char **line);

t_fdf_win			*gen_mlx_window(void *mlx, char *title, size_t x, size_t y);
void				new_fdf_img(t_fdf_win *win);
void				fdf_cam_img(t_fdf_map *map, t_fdf_win *win);
void				fdf_clear_img(t_fdf_win *win);

size_t				get_file_height(char *path);
size_t				get_file_width(char *path);

t_fdf_map			*fdf_map(size_t width, size_t height);
t_fdf_map			*parse_fdf_map(char *path);

t_3d_point			*new_3d_point(int x, int y, int z);
void				set_3d_point(t_3d_point *point, int x, int y, int z);
void				trans_3d_point(t_3d_point *dest, t_3d_point *src,
	t_fdf_cam *cam);

void				draw_3d_point(t_3d_point *point, t_fdf_win *win);
void				draw_point_line(t_3d_point *p1, t_3d_point *p2,
	t_fdf_win *win);
void				draw_map_point_lines(size_t x, size_t y, t_fdf_map *map,
	t_fdf_win *win);

t_fdf_cam			*gen_default_camera(void);
void				trans_fdf_map(t_fdf_map *dest, t_fdf_map *src,
	t_fdf_cam *cam);

void				print_sp_left(char *str, size_t space);
void				print_sp_right(char *str, size_t space);

int					fdf_expose_hook(void *env);
int					fdf_key_hook(int keycode, void *env);
int					fdf_mouse_hook(int button, int x, int y, void *env);
int					fdf_loop_hook(void *env);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 16:14:35 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/12/14 11:48:47 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include "arraylist.h"
# include "math_structs.h"

# define DEF_TITLE "FDF Main Window"
# define DEF_X 400
# define DEF_Y 400

typedef struct		s_fdf_win
{
	void			*mlx;
	void			*win;
	char			*title;
	size_t			width;
	size_t			height;
	void			*img;
	unsigned int	*img_data;
	int				img_bits_per_pixel;
	int				img_size_line;
	int				img_endian;
}					t_fdf_win;

void				fdf_error(char *str);
void				*check_malloc(void *ret);

t_mlx_win			*gen_mlx_window(void *mlx, char *title, size_t x, size_t y);
size_t				get_file_height(int fd);
t_fdf_map			*parse_fdf_map(int	fd);

#endif

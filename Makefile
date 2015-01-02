# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 16:35:37 by tgauvrit          #+#    #+#              #
#    Updated: 2015/01/02 19:22:40 by tgauvrit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			FDF

CC =			gcc

FLAGS =			-Wall -Werror -Wextra -g

HEADER =		fdf.h get_next_line.h math_structs.h

HEADER_DIR =	-I ./includes/ -I $(FT_LIB_DIR) -I $(AL_LIB_DIR)

MLX_LIBS =		-L/usr/X11/lib -lmlx -lXext -lX11

LIBRARIES =		-L$(FT_LIB_DIR) -l$(FT_LIB_NAME) -L$(AL_LIB_DIR) -l$(AL_LIB_NAME) $(MLX_LIBS)

FT_LIB_NAME =	ft

FT_LIB =		lib$(FT_LIB_NAME).a

FT_LIB_DIR =	./libft/

AL_LIB_NAME =	arylst

AL_LIB =		lib$(AL_LIB_NAME).a

AL_LIB_DIR =	./arraylist/

SRC_DIR =		./srcs/

SRC_COMPILED =	main.o \
				get_next_line.o \
				new_3d_point.o \
				fdf_cam_img.o \
				get_file_height.o \
				get_file_width.o \
				fdf_error.o \
				check_malloc.o \
				gen_mlx_window.o \
				gen_default_camera.o \
				trans_3d_point.o \
				trans_fdf_map.o \
				new_fdf_img.o \
				fdf_map.o \
				parse_fdf_map.o \
				set_3d_point.o

COMPILED =		$(SRC_COMPILED)

all: $(NAME)

$(NAME): $(FT_LIB) $(AL_LIB) $(SRC_COMPILED)
	$(CC) -o $(NAME) $(FLAGS) $(LIBRARIES) $(HEADER_DIR) $(SRC_COMPILED)

$(SRC_COMPILED): %.o: $(SRC_DIR)%.c
	$(CC) -c $(FLAGS) $(HEADER_DIR) $< -o $@

$(FT_LIB):
	@make -C $(FT_LIB_DIR);

$(AL_LIB):
	@make -C $(AL_LIB_DIR);

clean:
	-/bin/rm -f $(COMPILED)

fclean: clean
	-/bin/rm -f $(NAME)

re: fclean all

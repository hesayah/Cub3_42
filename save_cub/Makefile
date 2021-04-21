# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 12:59:53 by hesayah           #+#    #+#              #
#    Updated: 2021/04/18 16:45:59 by hesayah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

INCLUDE = cub3d.h libs/libft/libft.h libs/gnl/get_next_line.h

SRCS =	libs/gnl/get_next_line_utils.c \
		libs/gnl/get_next_line.c \
		cub3d.c \
		srcs/init.c \
		srcs/exit_error.c \
		srcs/parsing/pars_brain.c \
		srcs/parsing/pars_two.c \
		srcs/parsing/pars_three.c \
		srcs/parsing/pars_map.c \
		srcs/parsing/pars_player.c \
		srcs/sprite/sprite.c \
		srcs/img/load_xpm.c \
		srcs/move/move.c \
		srcs/ray_casting/ray_casting.c \
		srcs/drawing/drawing_one.c \
		srcs/drawing/drawing_two.c \
		srcs/save.c \
		
LIBFT = libs/libft

LIB = libs/libft/libft.a libs/mlx/libmlx.a

OBJ = $(SRCS:.c=.o)

GCC = gcc 

FLAGS = -Wall -Wextra -Werror -O3  -g3 -fsanitize=address

MLX = -Llibs/mlx -lmlx -framework OpenGL -framework AppKit 

all: $(NAME)

$(NAME):${OBJ}
	@echo "\033[32m[Compile Lib...]"
	@$(MAKE) -C $ $(LIBFT)
	@echo "\033[32m[Compile CUB3D...]"
	@$(GCC) $(FLAGS) $(MLX) $(LIB) -o $(NAME) ${OBJ}
	@echo "\033[32m[JOB DONE ! YOU CAN RUN THE GAME :D]"

clean:
	@rm -rf $(OBJ)
	@echo "\033[32m[Clean-UP DONE]"

	
fclean: clean
	rm -rf libs/libft/*.o
	rm -rf libs/mlx/*.o
	rm -rf $(NAME)

re: fclean all

0: all clean

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hedi <hedi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 12:59:53 by hesayah           #+#    #+#              #
#    Updated: 2021/04/26 00:06:20 by hedi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

INCLUDE = cub3d.h libs/libft/libft.h libs/gnl/get_next_line.h

SRCS =	libs/gnl/get_next_line_utils.c \
		libs/gnl/get_next_line.c \
		srcs/cub3d.c \
		srcs/init.c \
		srcs/exit_error.c \
		srcs/parsing/pars_brain.c \
		srcs/parsing/pars_two.c \
		srcs/parsing/pars_three.c \
		srcs/parsing/pars_map.c \
		srcs/parsing/pars_player.c \
		srcs/parsing/load_xpm.c \
		srcs/sprite/sprite.c \
		srcs/move/move.c \
		srcs/ray_casting/ray_casting.c \
		srcs/drawing/drawing_one.c \
		srcs/drawing/drawing_two.c \
		srcs/save.c
		
LIBFT_PATH = libs/libft

MLX_PATH = libs/mlx

LIB = libs/libft/libft.a libs/mlx/libmlx.a

OBJ = $(SRCS:.c=.o)

GCC = gcc

FLAGS = -Wall -Wextra -Werror -std=c11 -O3 -g3  -ggdb3 #fsanitize=address

MLX = -Llibs/mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
$(NAME):${OBJ}
	@echo "\033[32m[Compile Lib...]"
	@$(MAKE) -C $ $(LIBFT_PATH)
	@echo "\033[32m[Compile mlx...]"
	@$(MAKE) -C $ $(MLX_PATH)
	@echo "\033[32m[Compile CUB3D...]"
	@$(GCC) -o $(NAME) ${OBJ} $(FLAGS) $(LIB) $(MLX)
	@echo "\033[32m[JOB DONE ! YOU CAN RUN THE GAME :D]"

clean:
	@rm -rf $(OBJ)
	@echo "\033[32m[Clean-UP DONE]"
	
fclean: clean
	@$(MAKE) -C $ $(LIBFT_PATH) fclean
	@$(MAKE) -C $ $(MLX_PATH) clean
	@rm -rf $(NAME)
	@echo "\033[32m[Clean-UP DONE]"

re: fclean all

0: all clean


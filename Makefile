# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 04:57:48 by jonchoi           #+#    #+#              #
#    Updated: 2023/01/16 04:57:55 by jonchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= fdf

CC						= cc
CFLAGS					= -Wall -Wextra -Werror
AR						= ar rcs
RM						= rm -f

SRCS_DIR				= ./srcs/

GNL_DIR					= utils/gnl/
GNL_SRC					= get_next_line.c get_next_line_utils.c\

UTILS_DIR				= utils/
UTILS_SRC				= ft_split.c ft_atoi.c ft_abs.c print_error.c\

INIT_AND_READ_DIR		= init_and_read/
INIT_AND_READ_SRC		= init_coords.c init_fdf.c init_map_info.c read_file.c\

DRAW_DIR				= draw/
DRAW_SRC				= drawing.c draw_line.c rotation.c set_point_coord.c\

KEY_HOOK_DIR			= key_hook/
KEY_HOOK_SRC			= close_win.c key_press.c\

SRC						=	main.c\
							$(addprefix $(INIT_AND_READ_DIR), $(INIT_AND_READ_SRC))\
							$(addprefix $(DRAW_DIR), $(DRAW_SRC))\
							$(addprefix $(KEY_HOOK_DIR), $(KEY_HOOK_SRC))\
							$(addprefix $(GNL_DIR), $(GNL_SRC))\
							$(addprefix $(UTILS_DIR), $(UTILS_SRC))\

SRCS					=	$(addprefix $(SRCS_DIR), $(SRC))
OBJS					=	$(SRCS:.c=.o)

MLX_NAME				= mlx
MLX_DIR					= ./mlx/

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(MLX_DIR) all
	$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX_NAME) \
	-framework OpenGL -framework AppKit $^ -o $@

clean :
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(NAME)

bonus : all

re :
	make fclean
	make all

.PHONY	:	all clean fclean re bonus

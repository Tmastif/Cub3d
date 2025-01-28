# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 15:43:16 by htharrau          #+#    #+#              #
#    Updated: 2025/01/27 18:36:29 by htharrau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

SRCS_DIR	= src/
OBJS_DIR	= obj/
INCS_DIR	= inc/

SRCS		= 0_main.c 
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= MLX42
MLX			= $(MLX_DIR)/build/libmlx42.a

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
LDFLAGS		= -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm

.SILENT:

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT) $(MLX)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm
				echo "$(YELLOW)$(NAME) created"

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				mkdir -p $(OBJS_DIR)
				$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR) -I$(LIBFT_DIR)

$(LIBFT):
				make -C $(LIBFT_DIR)
				echo "$(MAGENTA)Libft created.$(DEFAULT)"

$(MLX):
				cmake -B $(MLX_DIR)/build -S $(MLX_DIR)
				make -C $(MLX_DIR)/build -j4
				echo "$(MAGENTA)Minilibx created.$(DEFAULT)"

clean:
				make -C $(LIBFT_DIR) clean
				echo "$(BLUE)Libft cleaned$(DEFAULT)"
				rm -rf $(MLX_DIR)/build
				echo "$(BLUE)Minilibx cleaned$(DEFAULT)"
				rm -f $(OBJS_DIR)/*.o
				echo "$(BLUE)Object files cleaned$(DEFAULT)"

fclean:			clean
				make -C $(LIBFT_DIR) fclean
				rm $(NAME)
				echo "$(ORANGE)Executable cleaned$(DEFAULT)"

re:				fclean all

debug:			CFLAGS += -fsanitize=address -fno-omit-frame-pointer -g
debug:			re


.PHONY:			all clean fclean re debug


#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
DEFAULT = \033[0m
ORANGE = \033[38;2;255;165;0m
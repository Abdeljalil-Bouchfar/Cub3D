# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 17:01:58 by ressalhi          #+#    #+#              #
#    Updated: 2022/11/10 22:17:25 by ressalhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = #-Wall -Wextra -Werror
SRCS =	main_bonus.c \
		parse/parse.c \
		parse/utils1.c \
		parse/utils2.c \
		utils_bonus.c \
		shared/gnl.c \
		shared/ft_strlen.c \
		shared/ft_strchr.c \
		shared/ft_strdup.c \
		shared/ft_strjoin.c \
		shared/ft_substr.c \
		shared/helpers.c \
		shared/ft_split.c \
		shared/ft_isdigit.c \
		shared/ft_atoi.c \
		shared/ft_calloc.c \
		shared/ft_strlcpy.c \
		shared/ft_strncmp.c \
		shared/memmory_utils.c \
		ft_raycasting_bonus.c \
		ft_moves_bonus.c \
		ft_hook_bonus.c \
		ft_draw_bonus.c \
		mini_map.c

MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all

.PHONY : clean all fclean re bonus

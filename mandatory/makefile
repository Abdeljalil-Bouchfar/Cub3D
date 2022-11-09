# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 17:01:58 by ressalhi          #+#    #+#              #
#    Updated: 2022/11/09 17:59:58 by abouchfa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =	main.c \
		parse/parse.c \
		parse/utils1.c \
		parse/utils2.c \
		utils.c \
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
		shared/ft_strlcpy.c \
		shared/ft_strncmp.c \
		shared/ft_calloc.c \
		shared/memmory_utils.c \
		ft_raycasting.c \
		ft_moves.c \
		ft_hooks.c 
MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(MLX_FLAGS) -o $(NAME)

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all

.PHONY : clean all fclean re bonus

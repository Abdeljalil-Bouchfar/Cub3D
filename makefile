# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 17:01:58 by ressalhi          #+#    #+#              #
#    Updated: 2022/10/23 20:21:58 by ressalhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -g -fsanitize=address #-Wall -Wextra -Werror
SRCS =	main.c \
		parse.c \
		utils.c \
		shared/gnl.c \
		shared/ft_strlen.c \
		shared/ft_strchr.c \
		shared/ft_strdup.c \
		shared/ft_strjoin.c \
		shared/ft_substr.c \
		shared/print_error.c \
		shared/ft_split.c\
		ft_dda.c \
		ft_moves.c \
		ft_animation.c
MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit
#OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all

.PHONY : clean all fclean re bonus

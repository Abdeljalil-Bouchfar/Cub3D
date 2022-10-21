# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdeljalilbouchfar <abdeljalilbouchfar@    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 17:01:58 by ressalhi          #+#    #+#              #
#    Updated: 2022/10/21 11:29:38 by abdeljalilb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = #-g -fsanitize=address #-Wall -Wextra -Werror
SRCS = main.c parse.c utils.c ft_split.c get_next_line.c get_next_line_utils.c ft_dda.c ft_moves.c \
		ft_animation.c
MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean all fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 17:01:58 by ressalhi          #+#    #+#              #
#    Updated: 2022/11/11 14:48:28 by abouchfa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEM = cub3D
NAMEB = cub3D_Bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit

CFILESM = mandatory/main.c \
		mandatory/parse/parse.c \
		mandatory/parse/utils1.c \
		mandatory/parse/utils2.c \
		mandatory/utils.c \
		mandatory/shared/gnl.c \
		mandatory/shared/ft_strlen.c \
		mandatory/shared/ft_strchr.c \
		mandatory/shared/ft_strdup.c \
		mandatory/shared/ft_strjoin.c \
		mandatory/shared/ft_substr.c \
		mandatory/shared/helpers.c \
		mandatory/shared/ft_split.c \
		mandatory/shared/ft_isdigit.c \
		mandatory/shared/ft_atoi.c \
		mandatory/shared/ft_strlcpy.c \
		mandatory/shared/ft_strncmp.c \
		mandatory/shared/ft_calloc.c \
		mandatory/shared/memmory_utils.c \
		mandatory/ft_raycasting.c \
		mandatory/ft_moves.c \
		mandatory/ft_hooks.c 

CFILESB = bonus/main_bonus.c \
		bonus/parse/parse_bonus.c \
		bonus/parse/utils1_bonus.c \
		bonus/parse/utils2_bonus.c \
		bonus/utils_bonus.c \
		bonus/shared/gnl_bonus.c \
		bonus/shared/ft_strlen_bonus.c \
		bonus/shared/ft_strchr_bonus.c \
		bonus/shared/ft_strdup_bonus.c \
		bonus/shared/ft_strjoin_bonus.c \
		bonus/shared/ft_substr_bonus.c \
		bonus/shared/helpers_bonus.c \
		bonus/shared/ft_split_bonus.c \
		bonus/shared/ft_isdigit_bonus.c \
		bonus/shared/ft_atoi_bonus.c \
		bonus/shared/ft_calloc_bonus.c \
		bonus/shared/ft_strlcpy_bonus.c \
		bonus/shared/ft_strncmp_bonus.c \
		bonus/shared/memmory_utils_bonus.c \
		bonus/ft_raycasting_bonus.c \
		bonus/ft_moves_bonus.c \
		bonus/ft_hook_bonus.c \
		bonus/ft_draw_bonus.c \
		bonus/mini_map_bonus.c

OBJSM = $(CFILESM:.c=.o)
OBJSB = $(CFILESB:.c=.o)

all : $(NAMEM)

$(NAMEM): $(OBJSM)
		$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJSM) -o $(NAMEM)

bonus: $(NAMEB)

$(NAMEB): $(OBJSB)
		$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJSB) -o $(NAMEB)
	

clean:
	rm -f $(OBJSM) $(OBJSB)

fclean: clean
	rm -f $(NAMEM) $(NAMEB)

re: fclean all

.PHONY : clean all fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktiyari <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 21:12:20 by ktiyari           #+#    #+#              #
#    Updated: 2024/07/25 21:12:23 by ktiyari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fractol

NAME_BONUS = fractol_bonus

CC = cc #-fsanitize=address -g3
FLAGS = -Wall -Wextra -Werror  -Imlx_linux
LDFLAGS = -Lmlx_linux -lmlx -lXext -lX11 -lm -lz

RM = rm -f

SRC = fractal.c draw.c utils_draw.c utils.c event.c
OBJ = $(SRC:.c=.o)

SRC_B = b_fractal.c b_draw.c b_event.c b_utils.c b_utils_draw.c 
OBJ_B = $(SRC_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) $(LDFLAGS)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
			$(CC) $(FLAGS) $(SRC_B) -o $(NAME_BONUS) $(LDFLAGS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ) $(OBJ_B)

fclean : clean
	$(RM) $(NAME) $(OBJ_B)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmarchau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 12:36:55 by vmarchau          #+#    #+#              #
#    Updated: 2017/12/09 14:37:50 by cmalfroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
INC_LIBFT_PATH = ./libft/includes/
LIB_PATH = ./libft/

NAME = fractol
CC = gcc
CFLAGS = -Werror -Wextra -Wall

SRC_NAME = main.c event.c error.c julia.c mandelbrot.c burningship.c tricorn.c\
		   fish.c helper.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
INC_LIBFT = $(addprefix -I,$(INC_LIBFT_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)

all: $(NAME)

$(NAME): $(OBJ) Makefile
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(LIB) $(INC_LIBFT) $(INC) $(OBJ) -o $(NAME) -lmlx -framework OpenGL -framework AppKit -lpthread
	@echo  "Compilation of : \033[32;1;4;5m$(NAME)\033[0m : Successfull"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC_LIBFT) $(INC) -o $@ -c $<
	@echo "\033[A\033[K\033[A"

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIB_PATH)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all



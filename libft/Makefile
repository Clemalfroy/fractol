# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmarchau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 15:54:42 by vmarchau          #+#    #+#              #
#    Updated: 2017/12/01 12:21:53 by cmalfroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

NAME = libft.a
CC = gcc
CFGLAGS = -Werror -Wextra -Wall

SRC_NAME  = ft_abs.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c\
			ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c\
			ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
			ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
			ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
			ft_nblen.c ft_print_words_tables.c ft_putchar.c ft_putchar_fd.c\
			ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c\
			ft_putstr_fd.c ft_spr_putendl.c ft_spr_putstr.c ft_strcat.c\
			ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
			ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
			ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
			ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
			ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
			ft_swap.c ft_tolower.c ft_toupper.c ft_putstr_red.c ft_putstr_blue.c\
			ft_putstr_cyan.c ft_putstr_green.c ft_putstr_yellow.c ft_putstr_pink.c\
			ft_putendl_cyan.c ft_putendl_green.c ft_putendl_yellow.c ft_putendl_pink.c\
			ft_putendl_red.c ft_putendl_blue.c



OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compilation of : \033[32;1;4;5m$(NAME)\033[0m : Successfull"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(LIB) $(INC) -o $@ -c $<
	@echo "\033[A\033[K\033[A"

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/16 01:49:47 by fdikilu           #+#    #+#              #
#    Updated: 2019/04/05 19:17:16 by fdikilu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = ft_select

SRC_PATH = src

OBJ_PATH = obj

LIB_DIR = libft

LIB = $(LIB_DIR)/libft.a

CFLAGS = -Werror -Wall -Wextra

CPPFLAGS = -Iinclude -Ilibft

LDFLAGS = -Llibft

LDLIBS = -lft -ltermcap

SRC_NAME = \
		action.c \
		arrow_key.c \
		display.c \
		dynamic_search.c \
		init.c \
		move_cursor.c \
		other_key.c \
		set_term.c \
		signal.c \
		tools.c \
		main.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(LIB) $(NAME)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS)  $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

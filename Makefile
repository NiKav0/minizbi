# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 00:43:31 by calmouht          #+#    #+#              #
#    Updated: 2024/02/13 00:47:09 by lhorbax          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wformat=2 -O3 -ffast-math -pedantic -Wunreachable-code -Wfloat-equal -Warray-bounds -Wall -Wextra -Werror
CC = gcc
NAME = minishell
LIBFT = lib/libft.a
OBJ = build/main.o 
SRC := src/main.c
INCLUDE = includes/

build/%.o : src/*/%.c
	$(CC) $< $(CFLAGS) -I$(INCLUDE) -c -o $@

all : build $(NAME)

build :
	mkdir build

$(LIBFT):
	$(MAKE) -C lib

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -I$(INCLUDE) -o $(NAME)

clean:
	$(MAKE) fclean -C lib; rm -rf build/

fclean : clean
	rm -rf $(NAME)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 00:43:31 by calmouht          #+#    #+#              #
#    Updated: 2024/02/13 02:37:12 by lhorbax          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wformat=2 -O3 -ffast-math -pedantic -Wunreachable-code -Wfloat-equal -Warray-bounds -Wall -Wextra -Werror
CC = gcc
NAME = minishell
LIBFT = lib/libft/libft.a
OBJ = build/main.o build/ms_parse.o build/ms_env.o
SRC := src/main.c src/ms_parse.c src/ms_env.c
INCLUDE = includes/

build/%.o : src/%.c
	$(CC) $< $(CFLAGS) -I$(INCLUDE) -c -o $@

all : build $(NAME)

build :
	mkdir build

$(LIBFT):
	$(MAKE) -C lib/libft

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -I$(INCLUDE) -o $(NAME)

clean:
	$(MAKE) fclean -C lib/libft; rm -rf build/

fclean : clean
	rm -rf $(NAME)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 00:43:31 by calmouht          #+#    #+#              #
#    Updated: 2024/05/11 02:37:10 by calmouht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
CC = gcc
NAME = minishell
LIBFT = lib/libft/libft.a
OBJ = build/main.o build/ms_parse.o build/ms_env.o build/ms_cmdgen.o build/ms_cmdrender.o build/ms_env_clone.o \
		build/ms_errors.o build/utility.o build/execution.o build/builtins.o build/ft_echo.o \
		build/ft_env.o build/ft_unset.o build/ft_cd.o build/exits.o build/redirections.o
SRC = src/main.c src/ms_parse.c src/ms_env.c src/ms_cmdgen.c src/ms_cmdrender.c src/ms_env_clone.c \
		src/ms_errors.c src/utility.c src/execution.c src/builtins.c src/ft_echo.c \
		src/ft_env.c src/ft_unset.c src/ft_cd.c src/exits.c src/redirections.c
INCLUDE = includes/minishell.h

# .SILENT:
build/%.o : src/%.c
	$(CC) $< $(CFLAGS) -c -o $@

all : build $(NAME)

build :
	mkdir build

$(LIBFT):
	$(MAKE) -C lib/libft

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -o $(NAME)

clean:
	$(MAKE) fclean -C lib/libft; rm -rf build/

fclean : clean
	rm -rf $(NAME)

re : fclean all

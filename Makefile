# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 10:19:16 by tpereira          #+#    #+#              #
#    Updated: 2022/04/09 12:17:31 by tpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FDF 		= fdf
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g
INC			= -Iincludes -Ilibft
LIB			= libft/libft.a
SRCS		= ./srcs/*.c
MAC			= -lm -lmlx -framework OpenGL -framework AppKit
LINUX		= -lXext -lX11
OS			= $(shell uname -s)

all :
	@make -s -C libft
ifeq ($(OS),Darwin)
	@make -s -C minilibx_macos
	@$(CC) $(CFLAGS) $(SRCS) $(LIB) $(MAC) -o $(FDF)
endif
ifeq ($(OS),Linux)
	@make -s -C MinilibX
	@$(CC) $(SRCS) $(LIB) MinilibX/libmlx_Linux.a $(LINUX) -o $(FDF) 
endif
	@printf "\e[38;5;46m ╔════════════════════════════════════╗\e[0m\n"
	@printf "\e[38;5;46m█▓▒░	     Compiled Libft	    ░▒▓█ \e[0m\n"
	@printf "\e[38;5;46m█▓▒░   MinilibX build successfull   ░▒▓█ \e[0m\n"
	@printf "\e[38;5;46m ╚════════════════════════════════════╝\e[0m\n"

cc: all
	./fdf 42.fdf

clean :
	@make -s clean -C libft
	@make -s clean -C MinilibX
	@rm -rf ./srcs/*.o
	@printf "\e[31;5;200m ╔════════════════════════════════════╗\e[0m\n"
	@printf "\e[31;5;200m░▒▓█         Clean complete  	    █▓▒░\e[0m\n"
	@printf "\e[31;5;200m ╚════════════════════════════════════╝\e[0m\n"

fclean : clean
	@make -s fclean -C libft
	@make -s clean -C MinilibX
	@rm -rf $(FDF)

re :	fclean all
bonus:	all

.PHONY: bonus re fclean clean all
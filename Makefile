# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 10:19:16 by tpereira          #+#    #+#              #
#    Updated: 2022/03/30 20:15:58 by tpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FDF 		= fdf
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g

all :
	@make -s -C libft
	@make -s -C MinilibX
	@gcc $(CFLAGS) ./srcs/*.c libft/libft.a MinilibX/libmlx_Linux.a -o $(FDF) -lXext -lX11
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
	@sleep 1;
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
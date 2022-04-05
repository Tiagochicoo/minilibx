# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 22:20:21 by tpereira          #+#    #+#              #
#    Updated: 2022/04/05 16:50:26 by tpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_PATH = includes
SRCS = $(wildcard ./srcs/*.c)
OBJS =  $(SRCS:.c=.o)
NAME =  libft.a
SO =    libft.so

.c.o:
	$(CC) -g $(CFLAGS) -c $^ -o $(<:.c=.o) -I $(INC_PATH)
all:        $(NAME)
$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)
clean:
	rm -f ./srcs/*.o
soclean:    clean
	rm -f $(SO)
fclean:     clean
	rm -f $(NAME)
	rm -f $(SO)
re:         fclean all
so:         $(OBJS) 
	gcc -shared -o $(SO) $(OBJS)

.PHONY: so bonus re fclean soclean clean all

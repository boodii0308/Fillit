# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 15:53:53 by tebatsai          #+#    #+#              #
#    Updated: 2019/06/26 23:46:06 by tebatsai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = *.c

OBJECTS = *.o

FLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

all:$(NAME)

$(NAME):$(LIBFT) $(OBJECTS)
	gcc $(FLAGS) *.c -o $(NAME) $(LIBFT)
$(OBJECTS): $(LIBFT)
	gcc $(FLAGS) -c *.c
$(LIBFT):
	make -C ./libft/
clean:
	make -C ./libft clean
	/bin/rm -f $(OBJECTS)

fclean: clean
	make -C ./libft fclean
	/bin/rm -rf $(NAME)
re: fclean all

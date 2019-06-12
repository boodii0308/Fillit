# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 15:53:53 by tebatsai          #+#    #+#              #
#    Updated: 2019/05/29 15:54:47 by tebatsai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = *.c

OBJECTS = *.o

all:$(NAME)

$(NAME): $(SRCS)
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

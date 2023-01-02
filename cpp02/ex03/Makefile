# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 13:28:24 by eozmert           #+#    #+#              #
#    Updated: 2023/01/02 16:43:07 by eozmert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed
FILES = main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJECTS = $(FILES:.cpp=.o)

COMP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(COMP) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 13:28:24 by eozmert           #+#    #+#              #
#    Updated: 2023/01/03 14:50:44 by eozmert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamondTrap
FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

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

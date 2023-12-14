# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 14:58:20 by hbui-vu           #+#    #+#              #
#    Updated: 2023/12/14 14:58:20 by hbui-vu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

SRCS = Zombie.cpp zombieHorde.cpp main.cpp

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
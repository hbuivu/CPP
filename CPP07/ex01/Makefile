# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 10:48:05 by hbui-vu           #+#    #+#              #
#    Updated: 2024/01/10 17:54:41 by hbui-vu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Iter

SRCS = main.cpp

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
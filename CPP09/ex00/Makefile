# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 10:48:05 by hbui-vu           #+#    #+#              #
#    Updated: 2024/01/22 01:13:27 by hbui-vu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BitcoinExchange

SRCS = main.cpp BitcoinExchange.cpp

CXXFLAGS = -Wall -Wextra -std=c++98 
#  -Werror

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
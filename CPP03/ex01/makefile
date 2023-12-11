NAME = ClapTrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
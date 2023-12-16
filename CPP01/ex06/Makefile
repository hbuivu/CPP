NAME = harlFilter

SRCS = main.cpp HarlFilter.cpp

CXXFLAGS = -Wall -Wextra -Werror -Wimplicit-fallthrough=0 -std=c++98 

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
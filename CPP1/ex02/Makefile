CFLAGS = -Wall -Werror -Wextra #-std=c++98
CC = g++-11

SRCS = main.cpp         \

OBJS = $(SRCS:.cpp=.o)

NAME = brain

all = $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
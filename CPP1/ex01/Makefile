CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

SRCS = main.cpp         \
		Zombie.cpp      \
		zombieHorde.cpp   \

OBJS = $(SRCS:.cpp=.o)

NAME = zombie

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
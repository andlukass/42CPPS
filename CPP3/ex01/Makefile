CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

SRCS = main.cpp         \
		ClapTrap.cpp      \

NAME = trap

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(NAME)

re: clean all
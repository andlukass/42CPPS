CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

SRCS = main.cpp         \
		Fixed.cpp      \

NAME = fixed

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	@echo "no objects to clean..."

fclean:
	rm -f $(NAME)

re: fclean all
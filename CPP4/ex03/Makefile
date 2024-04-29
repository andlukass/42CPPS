CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

SRCS = main.cpp         \
		AMateria.cpp      \
		Ice.cpp           \
		Character.cpp     \


NAME = rpg

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	@echo "no objects to clean..."

fclean:
	rm -f $(NAME)

re: fclean all
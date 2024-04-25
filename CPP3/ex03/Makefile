CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

SRCS = main.cpp         \
		ClapTrap.cpp      \
		ScavTrap.cpp      \
		FragTrap.cpp      \
		DiamondTrap.cpp      \


NAME = trap

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	@echo "no objects to clean..."

fclean:
	rm -f $(NAME)

re: fclean all
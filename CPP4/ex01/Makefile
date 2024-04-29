CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

SRCS = main.cpp         \
		Animal.cpp        \
		Dog.cpp           \
		Cat.cpp           \
		WrongCat.cpp      \
		WrongAnimal.cpp   \
		Brain.cpp         \

NAME = animal

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	@echo "no objects to clean..."

fclean:
	rm -f $(NAME)

re: fclean all
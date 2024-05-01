CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

SRCS = main.cpp         \
		Animal.cpp        \
		Dog.cpp           \
		Cat.cpp           \
		WrongCat.cpp      \
		WrongAnimal.cpp   \

OBJS = $(patsubst %.cpp,.objs/%.o,$(SRCS))

NAME = animal

all: $(NAME)

.objs/%.o:%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
# '<': right side
# '@': left side

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf .objs

fclean: clean
	rm -f $(NAME)

re: fclean all
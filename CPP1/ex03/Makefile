CFLAGS = -Wall -Werror -Wextra #-std=c++98
CC = g++-11

SRCS = main.cpp         \
		Weapon.cpp       \
		HumanA.cpp       \
		HumanB.cpp       \

OBJS = $(SRCS:.cpp=.o)

NAME = humans

all = $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
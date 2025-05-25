CFLAGS = -I./includes -Wall -Werror -Wextra -std=c++98
CC = c++

HEADERS = includes/easyfind.hpp                 \

SRCS = main.cpp                        \

OBJS = $(patsubst %.cpp,.objs/%.o,$(SRCS))

NAME = easyfind

all: $(NAME)

.objs/%.o:srcs/%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
# '<': right side
# '@': left side

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf .objs

fclean: clean
	rm -f $(NAME)

re: fclean all
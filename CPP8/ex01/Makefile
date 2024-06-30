CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

HEADERS = Span.hpp                     \

SRCS = main.cpp                        \
		Span.cpp                       \

OBJS = $(patsubst %.cpp,.objs/%.o,$(SRCS))

NAME = convert

all: $(NAME)

.objs/%.o:%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
# '<': right side
# '@': left side

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf .objs

fclean: clean
	rm -f *bery
	rm -f $(NAME)

re: fclean all
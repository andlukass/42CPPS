CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

HEADERS = Bureaucrat.hpp Form.hpp

SRCS = main.cpp           \
		Bureaucrat.cpp    \
		Form.cpp          \

OBJS = $(patsubst %.cpp,.objs/%.o,$(SRCS))

NAME = bureaucrat

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
	rm -f $(NAME)

re: fclean all
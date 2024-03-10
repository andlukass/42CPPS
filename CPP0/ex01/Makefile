CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

NAME	= phonebook

SRCS	= main.cpp \
			PhoneBook.cpp #\
			# Contact.cpp \

OBJS = $(SRCS:%.cpp=.build/%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.build/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf .build

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
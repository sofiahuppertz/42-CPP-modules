NAME = phonebook

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Contact.class/Contact.class.cpp \
	PhoneBook.class/PhoneBook.class.cpp \
	main.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
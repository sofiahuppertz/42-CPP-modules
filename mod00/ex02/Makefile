NAME = logs

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp \
	tests.cpp
	
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
NAME = zombieHorde

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = def/zombieHorde.cpp \
	def/Zombie.class.cpp \
	main.cpp 

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	c++ -I./dec $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
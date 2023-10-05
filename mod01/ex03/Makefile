NAME = unnecessary_violence

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = def/Weapon.class.cpp \
	def/HumanA.class.cpp \
	def/HumanB.class.cpp \
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
NAME = zombies

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = definitions/newZombie.cpp \
	definitions/randomChump.cpp \
	definitions/Zombie.class.cpp \
	main.cpp

OBJS = $(SRCS:.cpp=.o)

.SECONDARY : $(OBJS)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) -I./declarations $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: clean fclean re all
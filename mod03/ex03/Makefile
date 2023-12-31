NAME = DiamondTrap

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = def/ClapTrap.class.cpp \
	def/FragTrap.class.cpp \
	def/ScavTrap.class.cpp \
	def/DiamondTrap.class.cpp \
	main.cpp 

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	c++ -I./dec $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

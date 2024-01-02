NAME = Animals

CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98

SRCS = def/Animal.class.cpp \
	def/Cat.class.cpp \
	def/Dog.class.cpp \
	def/WrongAnimal.class.cpp \
	def/WrongCat.class.cpp \
	main.cpp 

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	c++ -I./dec $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

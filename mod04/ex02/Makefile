NAME = Ideas

CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98

SRCS = def/Animal.class.cpp \
	def/Cat.class.cpp \
	def/Dog.class.cpp \
	def/Brain.class.cpp \
	main.cpp 

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	g++ -I./dec $(CPPFLAGS) $(OBJS) -o $(NAME)

re: fclean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

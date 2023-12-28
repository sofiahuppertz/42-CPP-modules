NAME = bsp

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = def/Fixed.class.cpp \
	def/Point.class.cpp \
	def/Bsp.cpp \
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

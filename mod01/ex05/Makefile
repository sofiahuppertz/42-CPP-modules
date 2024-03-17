NAME = harl

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = def/Harl.class.cpp \
	main.cpp

OBJS = $(SRCS:.cpp=.o)

.SECONDARY : $(OBJS)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) -I./dec $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

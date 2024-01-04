NAME = Materials

CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98

SRCS = def/AMateria.class.cpp \
	def/Character.class.cpp \
	def/Cure.class.cpp \
	def/Ice.class.cpp \
	def/ICharacter.class.cpp \
	def/IMateriaSource.class.cpp \
	def/MateriaSource.class.cpp \
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
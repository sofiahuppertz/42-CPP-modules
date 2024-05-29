NAME = template

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	def/ANSIColors.cpp \
		
OBJS = $(SRCS:.cpp=.o)

# ANSI escape codes for colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
NC = \033[0m # No Color

.SECONDARY : $(OBJS)

all : $(NAME)

$(NAME): $(OBJS)
	@echo "${YELLOW}Compiling...${NC}"
	@$(CXX) -I./dec $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "${GREEN}Done${NC}"

%.o: %.cpp
	@echo "${BLUE}Compiling $<...${NC}"
	@$(CXX) $(CXXFLAGS) -I./dec -c $< -o $@

clean:
	@echo "${RED}Deleting object files...${NC}"
	@rm -f $(OBJS)

fclean: clean
	@echo "${RED}Deleting executable...${NC}"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

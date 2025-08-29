COMPILATOR	= c++
FLAGS		= -std=c++98 -Wall -Wextra -Werror
EXECUTABLE	= mutantStack
SRC			= $(wildcard *.cpp)
OBJ			= $(SRC:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(COMPILATOR) $(FLAGS) $(OBJ) -o $(EXECUTABLE)

%.o: %.cpp
	$(COMPILATOR) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re

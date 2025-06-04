NAME        = weaponizer
CXX            = c++
CXX_FLAGS    = -Wall -Wextra -Werror

CXX_FILES    = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
OBJS        = $(CXX_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $^ -o $@

%.o: %.cpp Zombie.hpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
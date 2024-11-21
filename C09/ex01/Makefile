FLAGS = -Wall -Werror -Wextra
COMPILER = cc

INCLUDES = includes
SRC_DIR = srcs/
SCR = $(SRC_DIR)ft_putchar.c $(SRC_DIR)ft_putstr.c
OBJ = $(SCR:.c=.o)
NAME = libft.a


all: $(NAME)

$(NAME): $(OBJ) 
	ar -rcs  $(NAME) $(OBJ)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@ -I$(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)


re: fclean all

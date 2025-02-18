# Nome dell'eseguibile
NAME = push_swap

# Compilatore e flag
CC = gcc 
CFLAGS = -Wall -Werror -Wextra

# Directory della Libft
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)

# Directory dei sorgenti
SRCS_DIR = .

# Trova tutti i file .c nella directory SRCS_DIR
SRC = $(wildcard $(SRCS_DIR)/*.c)

# Genera i file oggetto (.o) nella stessa directory dei sorgenti
OBJ = $(SRC:.c=.o)

# Regola predefinita
all: $(LIBFT_LIB) $(NAME)

# Compilazione dell'eseguibile
$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB)

# Compilazione dei file .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_INC) -c $< -o $@

# Compilazione della libft
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Pulizia dei file oggetto
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Pulizia completa
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Ricompilazione completa
re: fclean all

# Regole per evitare conflitti
.PHONY: all clean fclean re

# Nome dell'eseguibile
NAME = fdf

# Compilatore e flag
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Percorsi
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = $(MLX_DIR)

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)

# Directory dei sorgenti (puoi cambiarla se i file .c sono in una sottodirectory)
SRCS_DIR = .

# Trova tutti i file .c nella directory SRCS_DIR
SRC = $(wildcard $(SRCS_DIR)/*.c)

# Genera i file oggetto (.o) nella stessa directory dei sorgenti
OBJ = $(SRC:.c=.o)

# Regola predefinita
all: $(LIBFT_LIB) $(MLX_LIB) $(NAME)

# Regola per compilare l'eseguibile
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lX11 -lXext -lm

# Regola per compilare i file oggetto
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_INC) -I$(LIBFT_INC) -c $< -o $@

# Regola per compilare la MiniLibX
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Regola per compilare la libft
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Regola per pulire i file oggetto
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Regola per pulire tutto (oggetti e eseguibile)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Regola per ricompilare tutto
re: fclean all

# Regola per evitare conflitti con file chiamati "clean" o "fclean"
.PHONY: all clean fclean re

# Definisce le variabili
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

# I file sorgente
CLIENT_SRC = client.c
SERVER_SRC = server.c

# I file oggetto
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

# I nomi degli eseguibili
CLIENT = client
SERVER = server

# La regola di default (costruire entrambi gli eseguibili)
all: $(CLIENT) $(SERVER)

# Regola per il client
$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)

# Regola per il server
$(SERVER): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)

# Regola per la compilazione del client
$(CLIENT_OBJ): $(CLIENT_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(CLIENT_SRC)

# Regola per la compilazione del server
$(SERVER_OBJ): $(SERVER_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SERVER_SRC)

# Regola per la libreria libft.a
$(LIBFT):
	make -C $(LIBFT_DIR)

# Pulisce i file oggetto e gli eseguibili
clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	make -C $(LIBFT_DIR) clean

# Pulisce tutto (inclusi gli eseguibili)
fclean: clean
	rm -f $(CLIENT) $(SERVER)
	make -C $(LIBFT_DIR) fclean

# Ricostruisce tutto
re: fclean all

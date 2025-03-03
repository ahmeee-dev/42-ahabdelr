## Nome dell'eseguibile
NAME = philo

# Compilatore e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

# File sorgenti (usando la wildcard per includere tutti i .c)
SRCS = $(wildcard *.c)

# File oggetto
OBJS = $(SRCS:.c=.o)

# Regola predefinita: creare l'eseguibile
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Regola per creare gli oggetti .o a partire dai file .c
%.o: %.c philo_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia degli oggetti e dell'eseguibile
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

# Regola per generare il file di dipendenza
.PHONY: clean fclean re

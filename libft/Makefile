PROGRAM = a
CC = gcc
FLAGS = -Wall -Wextra -Werror
CFILES = $(wildcard *.c)
OFILES = $(CFILES:*.c=*.o)

all: $(PROGRAM)

$(PROGRAM): $(OFILES)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(PROGRAM)

re: fclean all

.PHONY: all clean fclean

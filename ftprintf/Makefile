# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 16:11:57 by ahabdelr          #+#    #+#              #
#    Updated: 2024/12/19 10:27:36 by ahabdelr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
CDIR = srcs/
HDIR = includes
LIBFT = libft
CFILES = $(wildcard $(CDIR)*.c)
OFILES = $(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OFILES) 
	make -C libft
	mv libft/libft.a $@
	ar rcs $@ $^

$(CDIR)%.o: $(CDIR)%.c
	$(CC) -I $(HDIR) $(FLAGS) -c $< -o $@

bonus: $(OFILES)
	make bonus -C libft
	mv libft/libft.a $(NAME)
	ar rcs $(NAME) $^

clean:
	cd srcs && rm -rf *.o
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
	make re -C libft

.PHONY: all clean fclean re
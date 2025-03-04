.PHONY: mandatory bonus all clean fclean

all: mandatory

mandatory:
	$(MAKE) -C mandatory
	mv mandatory/philo .

bonus:
	$(MAKE) -C bonus
	mv bonus/philo_bonus .

clean:
	$(MAKE) -C mandatory clean
	$(MAKE) -C bonus clean
	rm -f mandatory_executable philo_bonus

fclean: clean
	rm -f philo philo_bonus

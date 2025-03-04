.PHONY: mandatory bonus all clean fclean

all: mandatory

mandatory:
	$(MAKE) -C mandatory

bonus:
	$(MAKE) -C bonus

clean:
	$(MAKE) -C mandatory clean
	$(MAKE) -C bonus clean

fclean: clean
	$(MAKE) -C mandatory fclean
	$(MAKE) -C bonus fclean
	rm -f philo philo_bonus


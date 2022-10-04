NAME = philo

SRCS = main.c philo.c data.c utils.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -pthread

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -rf *.dSYM

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
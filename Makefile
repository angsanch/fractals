##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Make cat
##

CC=gcc

CFLAGS=-Wall -Werror -Wextra

C_FILES =

O_FILES = $(C_FILES:.c=.o)

NAME=fractals

$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) -o $(NAME) src/$(NAME).c $(O_FILES) lib/libmy.a

all: $(NAME)

clean:
	rm -f $(O_FILES) test_$(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib/libmy.a

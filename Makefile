##
## EPITECH PROJECT, 2023
## test
## File description:
## test
##

all:	libmy.a
	gcc my_ls.c -o my_ls -Wall -Wextra -L./lib/my -lmy -I./include -g3

libmy.a:
	make compile -C ./lib/my

clean:
	rm libmy.a
	rm lib/my/libmy.a

fclean: clean

re: fclean libmy.a

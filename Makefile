##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## t1
##

SRC		=	make_map.c	\
			main.c	\
			calc_up_and_down.c	\
			movement.c	\
			movement_x.c	\
			check_o.c	\
			my_h.c	\
			make_struct.c	\
			defeat.c	\
			free.c	\
			error.c	\

OBJ		=	$(SRC.c=.o)

LIB	=	-L lib/my/ -l my

VAL	=	--leak-check=full --track-origins=yes

CFLAGS  =	-W -Wall -I./include/ -lncurses

NAME    =   my_sokoban

all:	$(NAME)

$(NAME):
	make -C lib/my/
	gcc -o $(NAME) $(CFLAGS) $(SRC) $(LIB) -lm

clean:
	rm -f $(OBJ)
	make -C ./lib/my clean

fclean: clean
	rm -rf $(NAME)

re:	fclean all

valgrind:
	make -C lib/my/
	gcc -g -o $(NAME) $(CFLAGS) $(SRC) $(LIB) -lm
	valgrind $(VAL) ./my_sokoban map.txt
	rm -f vgcore.*

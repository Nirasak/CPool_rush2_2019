##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	step4.c	\
		detect_language.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	rush2

CFLAGS	=	-W -Wall -I include/

LDFLAGS	=	-L ./ -lmy

all: $(NAME)

$(NAME):	$(OBJ)
	cd lib/my/ && make
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~
	cd lib/my/ && make clean

fclean: clean
	rm -f $(NAME)
	cd lib/my/ && make fclean

re: fclean all

.PHONY: all clean fclean re

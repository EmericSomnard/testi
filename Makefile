##
## EPITECH PROJECT, 2024
## ex00
## File description:
## Makefile
##

SRC	= lib/string.c	\
  
OBJ	=	$(SRC:.c=.o)

COPIES	=	*~

NAME	=	libstring.a

MAKE	=	make

CFLAGS	=	-std=gnu17 -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(COPIES)
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:     fclean all
	rm -f $(OBJ)

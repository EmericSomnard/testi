##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile cs
##

SRC = ./src/Hostname.cpp\
	  ./src/Krell.cpp\
	  ./src/main.cpp\
	  ./src/Username.cpp\
	  ./src/Textual.cpp\
	  ./src/Data.cpp\
	  ./src/Graphics/CPU.cpp\
	  ./src/Graphics/Display.cpp\
	  ./src/Graphics/Ram.cpp\
	  ./src/Graphics/HostUserName.cpp\
	  ./src/Date.cpp\

COPIES	=	*~

OBJ = $(SRC:.cpp=.o)

OUTPUT = GKrellM

NAME = $(OUTPUT)

CPPFLAGS = -std=c++20 -Wall -Wextra -lncurses
LIBS = -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio

$(NAME): $(OBJ)
	g++ $(CPPFLAGS) -o $(OUTPUT) $(OBJ) $(LIBS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUTPUT)

re: fclean all

.PHONY: all clean fclean re
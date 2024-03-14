##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

BUILD = $(shell stack path --local-install-root)

all:
	stack build
	cp $(shell stack path --local-install-root)/bin/my-project-exe ./
	mv my-project-exe wolfram

clean:
	stack clean
	rm -f wolfram
	rm -f my-project.cabal
	rm -f stack.yaml.lock

fclean:	clean

re:     fclean all

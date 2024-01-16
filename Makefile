##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Makefile for my lib
##

SRC	=	src/emulate.c
SRC	+=	src/main.c
SRC	+=	src/graphics.c
SRC	+=	src/rom.c
SRC	+=	src/events.c
SRC	+=	src/cpu.c

OBJ	=	$(SRC:.c=.o)

NAME	=	Chip_8

CC	=	gcc -g3

CFLAGS	=	-I include
CFLAGS	+=	-W -Wall -Wextra -Wpedantic

LIB	=	-L lib/my -lmy
LIB	+=	-lcsfml-graphics
LIB	+=	-lcsfml-system
LIB	+=	-lcsfml-window

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C lib/my
	@make clean -C lib/my
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@make fclean -C lib/my
	@rm -f $(NAME)

re: fclean all

.PHONY:	clean fclean re all

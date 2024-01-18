##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Makefile for my lib
##

SRC	=	src/main.c
SRC	+=	src/emulator/cpu.c
SRC	+=	src/emulator/emulate.c
SRC	+=	src/emulator/rom.c
SRC	+=	src/display/graphics.c
SRC	+=	src/input/events.c
SRC	+=	src/instructions/opcode_00E0.c

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

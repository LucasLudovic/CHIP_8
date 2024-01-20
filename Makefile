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
SRC	+=	src/instructions/opcode_00EE.c
SRC	+=	src/instructions/opcode_0NNN.c
SRC	+=	src/instructions/opcode_1NNN.c
SRC	+=	src/instructions/opcode_2NNN.c
SRC	+=	src/instructions/opcode_3XKK.c
SRC	+=	src/instructions/opcode_4XKK.c
SRC	+=	src/instructions/opcode_5XY0.c
SRC	+=	src/instructions/opcode_6XKK.c
SRC	+=	src/instructions/opcode_7XKK.c
SRC	+=	src/instructions/opcode_8XY0.c
SRC	+=	src/instructions/opcode_8XY1.c

OBJ	=	$(SRC:.c=.o)

NAME	=	Chip_8

CC	=	gcc

CFLAGS	=	-I include
CFLAGS	+=	-W -Wall -Wextra -Wpedantic

CPPFLAGS = -g3

LDFLAGS	=	-L lib/my -lmy
LDFLAGS	+=	-lcsfml-graphics
LDFLAGS	+=	-lcsfml-system
LDFLAGS	+=	-lcsfml-window

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C lib/my
	@make clean -C lib/my
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@make fclean -C lib/my
	@rm -f $(NAME)

re: fclean all

.PHONY:	clean fclean re all

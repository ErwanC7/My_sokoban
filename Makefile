##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile of my_sokoban
##

MAIN	=	sources/main.c \
			sources/my_sokoban.c

SRC	=	sources/open_path.c \
		sources/double_str.c \
		sources/gameplay.c \
		sources/movement.c \
		sources/save.c \
		sources/get_lines_cols.c \
		sources/check.c

TST	=	tests/test_open_path.c \
		tests/test_double_str.c \
		tests/test_check.c \
		tests/test_get_lines_cols.c \
		tests/test_gameplay.c \
		tests/tests_movements/test_right.c \
		tests/tests_movements/test_left.c \
		tests/tests_movements/test_up.c \
		tests/tests_movements/test_down.c

OBJ	=	$(SRC:.c=.o)

OBJ2	=	$(MAIN:.c=.o)

NAME	=	my_sokoban

NAME2	=	unit_tests

all :	$(NAME)

$(NAME) :	$(OBJ2) $(OBJ)
	gcc -o $(NAME) $(OBJ2) $(OBJ) -lncurses -Wall -Wextra

clean :
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean :	clean
		rm -f $(NAME)

re :	fclean all

unit_tests :	fclean
		gcc -o $(NAME2) $(SRC) $(TST) --coverage -lcriterion -lncurses

tests_run :	unit_tests
		./unit_tests
		gcovr --exclude tests/
		gcovr -b --exclude tests/


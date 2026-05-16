SRC=main.c	\
	grid.c	\
	parse.c	\
	validate.c

OBJ=$(SRC:.c=.o)

NAME=bsq

all:$(NAME)

$(NAME):$(OBJ)
	cc -Wall -Wextra -Werror -o $(NAME) $(OBJ)

$(OBJ):$(SRC)
	cc -Wall -Wextra -Werror -c $(SRC)

clean:
	rm -f $(NAME)
fclean:
	rm -f $(OBJ)
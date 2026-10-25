NAME = libftprintf.a
COMPLIER = cc
FLAGS  = -Wall -Wextra -Werror

HEADER_PATH = ./include
SRC = ./src/ft_printf.c ./src/parser.c ./src/printf_utils.c ./src/handlers/handle_string.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		ar rcs $(NAME) $(OBJ)

src/%.o : src/%.c
		$(COMPLIER) $(FLAGS) -I$(HEADER_PATH) -c $< -o $@

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : clean

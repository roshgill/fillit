#Makefile is a form of automation that makes compilation of a group of files more efficient

NAME = fillit

CFILES = main.c parse.c validate.c savepieces.c fillmap.c

FLAGS = -Wall -Werror -Wextra -g -O0

GCC = gcc

LIBFT = libft

all: $(NAME)

$(NAME):
	 @make -C $(LIBFT)

	 $(GCC) $(FLAGS) $(CFILES) -L $(LIBFT) -lft -o $(NAME)

clean:
	 @rm -rf $(NAME)
	@make clean -C $(LIBFT)

fclean:	clean
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean all re
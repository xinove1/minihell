NAME= minishell

LIBFT= ./libft

CC=gcc

CFLAGS=-Wall -Wextra -Werror -lreadline

RM=rm -f

BUILTINS= echo.c pwd.c cd.c

PARSER= parser.c cmd_args_count.c parse_cmd_args.c

SRC= main.c utils.c

SRC_ALL= $(addprefix src/, $(SRC)) \
		 $(addprefix src/builtins/, $(BUILTINS)) \
		 $(addprefix src/parser/, $(PARSER)) \

OBJ= $(notdir $(SRC_ALL:.c=.o))

$(NAME): $(SRC_ALL) src/minihell.h
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -c $(SRC_ALL)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a  -o $(NAME)

all: $(NAME)

clean:
	@make -C $(LIBFT) clean
	@$(RM) $(OBJ)

fclean:
	@make -C $(LIBFT) fclean
	@$(RM) $(NAME) $(OBJ)

re: fclean all

.PHONY: clean fclean

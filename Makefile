NAME= minishell

LIBFT = ./libft

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC= main.c

BONUS=

BONUS_NAME =

BONUS_OBJ = $(BONUS:.c=.o)

OBJ=$(SRC:.c=.o)

$(NAME): $(addprefix src/, $(SRC)) src/minihell.h
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -c $(addprefix src/, $(SRC))
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a  -o $(NAME)

all: $(NAME)

$(BONUS_NAME): $(addprefix src/, $(BONUS)) src/minihell.h
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -c $(addprefix src/, $(BONUS))
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT)/libft.a  -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

clean:
	@make -C $(LIBFT) clean
	@$(RM) $(OBJ) $(BONUS_OBJ)

fclean:
	@make -C $(LIBFT) fclean
	@$(RM) $(NAME) $(BONUS_NAME) $(OBJ) $(BONUS_OBJ)

re: fclean all

.PHONY: clean fclean

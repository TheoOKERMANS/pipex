LIBFT = -L libft/ -lft

SRC = pipex.c err.c cmd.c path.c free.c
BONUS = pipex_bonus.c path_bonus.c free_bonus.c err_bonus.c cmd_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = pipex

$(NAME):
	make -C ./libft
	$(CC) -o $(NAME) $(FLAGS) $(addprefix mandatory/, $(SRC)) $(LIBFT) -g

all: $(NAME)

clean:
	rm -f $(addprefix mandatory/, $(OBJ))
	rm -f $(addprefix bonus/, $(OBJ_BONUS))
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

bonus: fclean
	make -C ./libft
	$(CC) -o $(NAME) $(FLAGS) $(addprefix bonus/, $(BONUS)) $(LIBFT) -g
	
re: fclean all
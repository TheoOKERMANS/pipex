NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_convert_hex.c ft_putstrtab_fd.c ft_putinttab_fd.c ft_put2dinttab_fd.c
SRC_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
SRC_PRINTF = ft_printf.c hex.c
SRC_GNL = get_next_line.c get_next_line_utils.c

OBJ= $(SRC:.c=.o)
OBJ_BONUS= $(SRC_BONUS:.c=.o)
OBJ_PRINTF= $(SRC_PRINTF:.c=.o)
OBJ_GNL= $(SRC_GNL:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

$(NAME):
	$(CC) $(FLAGS) -c $(SRC) $(SRC_BONUS) $(SRC_PRINTF) $(SRC_GNL)
	ar rc $(NAME) $(OBJ) $(OBJ_BONUS) $(OBJ_PRINTF) $(OBJ_GNL)

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	rm -f $(OBJ_PRINTF)
	rm -f $(OBJ_GNL)

fclean: clean
	rm -f $(NAME)
	
re: fclean all
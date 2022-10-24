SRC = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_convert_hex.c \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c \
ft_printf.c \
hex.c \
get_next_line.c \
get_next_line_utils.c \
ft_put2dinttab_fd.c \
ft_putinttab_fd.c \
ft_putstrtab_fd.c \
t_str.c \
smart_split.c

OBJ= $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a

#-----------TXT-----------
TXT_NC=\033[0;30m
TXT_RED=\033[0;31m
TXT_GREEN=\033[0;32m
TXT_ORANGE=\033[0;33m
TXT_BLUE=\033[0;34m
TXT_PURPLE=\033[0;35m
TXT_CYAN=\033[0;36m
TXT_LIGHT_GRAY=\033[0;37m

TXT_NC=\033[0m
TXT_TITLE=\033[0m
TXT_COMPILING=\033[1;35m
TXT_DELETING=\033[1;31m
TXT_DONE=\033[0;32m
#--------------------------

$(NAME):
	@make print_separator --no-print-directory
	@make title --no-print-directory
	@make compilation --no-print-directory
	@make print_separator --no-print-directory

all: $(NAME)

clean:
	@make print_separator --no-print-directory
	@make title --no-print-directory
	@make deleting_o --no-print-directory
	@make print_separator --no-print-directory

fclean:
	@make print_separator --no-print-directory
	@make title --no-print-directory
	@make deleting_o --no-print-directory
	@make deleting_res --no-print-directory
	@make print_separator --no-print-directory
	
re: 
	@make print_separator --no-print-directory
	@make title --no-print-directory
	@make deleting_o --no-print-directory
	@make deleting_res --no-print-directory
	@make compilation --no-print-directory
	@make print_separator --no-print-directory


title:
	@make print_in_column param1="$(NAME)" param2="$(TXT_TITLE)" --no-print-directory
	@printf "\n"

compilation:
	@make print_in_column param1="Compiling files..." param2="$(TXT_COMPILING)" --no-print-directory
	@printf "\n"
	@for file in $(SRC) ; do \
		make print_in_column_removing_line param1="$$file" param2="$(TXT_LIGHT_GRAY)" --no-print-directory ; \
		$(CC) $(FLAGS) -c $$file ; \
	done
	@make print_in_column_removing_line param1="DONE" param2="$(TXT_DONE)" --no-print-directory
	@printf "\n"
	@make print_in_column param1="Compiling library..." param2="$(TXT_COMPILING)" --no-print-directory
	@printf "\n"
	@make print_in_column param1="$(NAME)" param2="$(TXT_LIGHT_GRAY)" --no-print-directory
	@ar rc $(NAME) $(OBJ)
	@make print_in_column_removing_line param1="DONE" param2="$(TXT_DONE)" --no-print-directory
	@printf "\n"

deleting_o:
	@make print_in_column param1="Deleting files..." param2="$(TXT_DELETING)" --no-print-directory
	@printf "\n"
	@printf "$(TXT_NC)"
	@for file in $(OBJ) ; do \
		make print_in_column_removing_line param1="$$file" param2="$(TXT_LIGHT_GRAY)" --no-print-directory ; \
		rm -f $$file ; \
	done
	@make print_in_column_removing_line param1="DONE" param2="$(TXT_DONE)" --no-print-directory
	@printf "\n"

deleting_res:
	@make print_in_column param1="Deleting library..." param2="$(TXT_DELETING)" --no-print-directory
	@printf "\n"
	@make print_in_column param1="$(NAME)" param2="$(TXT_LIGHT_GRAY)" --no-print-directory
	@rm -f $(NAME)
	@make print_in_column_removing_line param1="DONE" param2="$(TXT_DONE)" --no-print-directory
	@printf "\n"

.ONESHELL:
print_in_column:
	@column_size=`tput cols`
	@column_size=`expr $$column_size - 4`
	@len=$(shell printf '%s' '$(param1)' | wc -c)
	@spacetoprint=`expr $$column_size - $$len`
	@midspace=`expr $$spacetoprint / 2`
	@restspace=`expr $$spacetoprint - $$midspace`
	@printf "$(TXT_NC)|"
	@if [ $$len -lt $$column_size ]
	then
		for i in `seq 0 $$restspace`
		do
			printf " "
		done
		printf "$(param2)$(param1)"
		for i in `seq 0 $$midspace`
		do
			printf " "
		done
	else
		printf "$(param2)$(param1)" | cut -c1-$$column_size | tr -d '\n'
	fi
	@printf "$(TXT_NC)|"

print_in_column_removing_line:
	@column_size=`tput cols`
	@column_size=`expr $$column_size - 4`
	@len=$(shell printf '%s' '$(param1)' | wc -c)
	@spacetoprint=`expr $$column_size - $$len`
	@midspace=`expr $$spacetoprint / 2`
	@restspace=`expr $$spacetoprint - $$midspace`
	@printf "\r\033[K$(TXT_NC)|"
	@if [ $$len -lt $$column_size ]
	then
		for i in `seq 0 $$restspace`
		do
			printf " "
		done
		printf "$(param2)$(param1)"
		for i in `seq 0 $$midspace`
		do
			printf " "
		done
	else
		printf "$(param2)$(param1)" | cut -c1-$$column_size | tr -d '\n'
	fi
	@printf "$(TXT_NC)|"

print_separator:
	@column_size=`tput cols`
	@column_size=`expr $$column_size - 4`
	@printf "$(TXT_NC)|"
	for i in `seq 0 $$column_size`
	do
		printf "="
	done
	@printf "=|\n"
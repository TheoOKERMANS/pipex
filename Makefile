SRC = pipex.c \
err.c \
cmd.c \
path.c \
free.c

BONUS = pipex_bonus.c \
path_bonus.c \
free_bonus.c \
err_bonus.c \
cmd_bonus.c

OBJ = $(SRC:.c=.o)
SRC_FOLDER = mandatory/
BONUS_FOLDER = bonus/
OBJ_BONUS = $(BONUS:.c=.o)
LIBFT = -L libft/ -lft
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
NAME = pipex

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
#-------------------------

$(NAME):
	@make -C ./libft --no-print-directory
	@printf "\n"
	@make print_separator --no-print-directory
	@make title --no-print-directory
	@make compilation --no-print-directory
	@make print_separator --no-print-directory

all: $(NAME)

clean:
	@make clean -C ./libft --no-print-directory
	@printf "\n"
	@make print_separator --no-print-directory
	@make title --no-print-directory
	@make deleting_o --no-print-directory
	@make deleting_o_bonus --no-print-directory
	@make print_separator --no-print-directory

fclean:
	@make fclean -C ./libft --no-print-directory
	@printf "\n"
	@make print_separator --no-print-directory
	@make title --no-print-directory
	@make deleting_o --no-print-directory
	@make deleting_o_bonus --no-print-directory
	@make deleting_res --no-print-directory
	@make print_separator --no-print-directory

bonus: fclean
	@make -C ./libft --no-print-directory
	@printf "\n"
	@make print_separator --no-print-directory
	@make title --no-print-directory
	@make compilation_bonus --no-print-directory
	@make print_separator --no-print-directory
	
re: 
	@make re -C ./libft --no-print-directory
	@printf "\n"
	@make print_separator --no-print-directory
	@make title --no-print-directory
	@make deleting_o --no-print-directory
	@make deleting_o_bonus --no-print-directory
	@make deleting_res --no-print-directory
	@make compilation --no-print-directory
	@make print_separator --no-print-directory

title:
	@make print_in_column param1="$(NAME)" param2="$(TXT_TITLE)" --no-print-directory
	@printf "\n"

compilation:
	@make print_in_column param1="Compiling files..." param2="$(TXT_COMPILING)" --no-print-directory
	@printf "\n"
	@for file in $(addprefix $(SRC_FOLDER), $(SRC)) ; do \
		make print_in_column_removing_line param1="$$file" param2="$(TXT_LIGHT_GRAY)" --no-print-directory ; \
		$(CC) $(FLAGS) -c $$file ; \
	done
	@make print_in_column_removing_line param1="DONE" param2="$(TXT_DONE)" --no-print-directory
	@printf "\n"
	@make print_in_column param1="Compiling program..." param2="$(TXT_COMPILING)" --no-print-directory
	@printf "\n"
	@make print_in_column param1="$(NAME)" param2="$(TXT_LIGHT_GRAY)" --no-print-directory
	@$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT) -g
	@for file in $(OBJ) ; do \
		mv $$file $(SRC_FOLDER) ; \
	done
	@make print_in_column_removing_line param1="DONE" param2="$(TXT_DONE)" --no-print-directory
	@printf "\n"

compilation_bonus:
	@make print_in_column param1="Compiling bonus files..." param2="$(TXT_COMPILING)" --no-print-directory
	@printf "\n"
	@for file in $(addprefix $(BONUS_FOLDER), $(BONUS)) ; do \
		make print_in_column_removing_line param1="$$file" param2="$(TXT_LIGHT_GRAY)" --no-print-directory ; \
		$(CC) $(FLAGS) -c $$file ; \
	done
	@make print_in_column_removing_line param1="DONE" param2="$(TXT_DONE)" --no-print-directory
	@printf "\n"
	@make print_in_column param1="Compiling program..." param2="$(TXT_COMPILING)" --no-print-directory
	@printf "\n"
	@make print_in_column param1="$(NAME)" param2="$(TXT_LIGHT_GRAY)" --no-print-directory
	@$(CC) -o $(NAME) $(FLAGS) $(OBJ_BONUS) $(LIBFT) -g
	@for file in $(OBJ_BONUS) ; do \
		mv $$file $(BONUS_FOLDER) ; \
	done
	@make print_in_column_removing_line param1="DONE" param2="$(TXT_DONE)" --no-print-directory
	@printf "\n"

deleting_o:
	@make print_in_column param1="Deleting files..." param2="$(TXT_DELETING)" --no-print-directory
	@printf "\n"
	@printf "$(TXT_NC)"
	@for file in $(OBJ) ; do \
		make print_in_column_removing_line param1="$$file" param2="$(TXT_LIGHT_GRAY)" --no-print-directory ; \
		rm -f $(addprefix $(SRC_FOLDER), $$file) ; \
	done
	@make print_in_column_removing_line param1="DONE" param2="$(TXT_DONE)" --no-print-directory
	@printf "\n"

deleting_o_bonus:
	@make print_in_column param1="Deleting bonus files..." param2="$(TXT_DELETING)" --no-print-directory
	@printf "\n"
	@printf "$(TXT_NC)"
	@for file in $(OBJ_BONUS) ; do \
		make print_in_column_removing_line param1="$$file" param2="$(TXT_LIGHT_GRAY)" --no-print-directory ; \
		rm -f $(addprefix $(BONUS_FOLDER), $$file) ; \
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
	@for i in `seq 0 $$column_size`
	do
		printf "="
	done
	@printf "=|\n"
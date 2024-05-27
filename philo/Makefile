NAME		= philo
CFLAGS		= -Wall -Wextra -Werror
CC		= gcc
SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c =.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)

re : fclean all

clean :
	rm -f *.o

fclean : 
	rm -rf $(NAME)

.PHONY : all fclean clean re
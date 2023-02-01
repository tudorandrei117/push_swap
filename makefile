
NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = utils4.c operations1.c operations2.c operations3.c pushswap.c main.c utils.c utils2.c short_sorter.c pushlower.c utils3.c

all:			$(NAME)

$(NAME):		
				$(CC) $(SRC) -o $(NAME) 

clean:
				$(RM) $(NAME)

fclean: 		clean
				

re:		fclean	$(NAME)
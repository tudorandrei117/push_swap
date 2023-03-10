
NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = operations/operations1.c operations/operations2.c operations/operations3.c\
		 under5sorter/pushlower.c under5sorter/short_sorter.c\
			stackutils/atol_atoi.c stackutils/basic_utils.c stackutils/checker.c stackutils/list_utils.c\
				push_swap.c algo/mainalgo.c algo/cost_utils.c algo/push.c algo/utils.c\

all:			$(NAME)

$(NAME):		
				$(CC) $(SRC) -o $(NAME) 

clean:
				$(RM) $(NAME)

fclean: 		clean
				

re:		fclean	$(NAME)
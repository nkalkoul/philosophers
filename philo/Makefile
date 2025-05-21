SRCS =	philo.c utils.c parsing.c routine.c
CC =	cc -Wall -Werror -Wextra -g3

NAME =	philo
OBJS =	$(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS)  -o $(NAME)
	@echo "done !"

%.o : %.c
	@$(CC) -c $< -o $@
	#echo "compiling: $<"

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
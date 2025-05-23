SRCS =	philo.c \
		$(addprefix parsing/, utils.c parsing.c) \
		$(addprefix routine/, routine.c routine_utils.c routine_utils2.c) 
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


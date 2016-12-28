CC =	gcc
NAME = ft_select
FLAGS =	-I includes/ -Wall -Werror -Wextra
SRCS = srcs/free.c srcs/list.c srcs/main.c srcs/manage_term.c \
	srcs/manage_variable.c srcs/move.c srcs/print.c srcs/signal.c \
	srcs/specific_move.c srcs/move_list.c srcs/init.c
OBJS = $(SRCS:%.c=%.o)

all: lib $(NAME)

lib:
	@make -C libft/

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -lncurses -lm $^ libft/libft.a -o $@

clean:
	@rm -f $(OBJS)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY:clean fclean re

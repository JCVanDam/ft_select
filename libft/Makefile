# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/18 15:22:51 by maxpetit          #+#    #+#              #
#    Updated: 2016/08/14 15:23:09 by maxpetit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean mrproper
NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	ft_strlcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c \
	ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
	ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	ft_lst_push_back.c ft_lst_reverse.c ft_lst_reverse_fun.c ft_strrchr_r.c \
	ft_strlen_tab.c get_next_line.c ft_lst_clear.c ft_putstr_str.c \
	ft_putendpath.c ft_countchr.c ft_print_tab.c ft_strdup_tab.c \
	ft_free_tab.c ft_tab_srch_idx.c ft_padding.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

%.o: %.c
	gcc $(FLAGS) -c $^ -I includes -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

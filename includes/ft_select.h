/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:57:29 by maxpetit          #+#    #+#             */
/*   Updated: 2016/12/28 16:47:53 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stddef.h>
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define HEIGHT (*data).height
# define WIDTH (*data).width
# define SIZE_LST (*data).size_lst
# define SIZE_LST_MOD (*data).size_lst_mod
# define NB_COL (*data).nb_col
# define COL_PAD (*data).col_pad
# define MIN (*data).min
# define NAME (*list).name
# define NUM (*data).cur_elem->num
# define DISPLAY (*data).cur_elem->display
# define FLG_VIDEO (*data).cur_elem->flags_reverse_video
# define CUR_POSX (*data).posx
# define CUR_POSY (*data).posy
# define CUR_COL (*data).cur_col
# define COL_H (*data).last_col_h
# define FD (*data).fd
# define SIZE_NOT_ENOUGH (*data).size_not_enough
# define CUR_ELEM (*data).cur_elem
# define OFF_UNDERLIGNE "ue"
# define ENTER_UNDERLIGNE "us"
# define OFF_APPARENCE_MODE "me"
# define ENTER_REVERSE_MODE "mr"

typedef struct termios	t_termios;
typedef struct		s_arg
{
	char			*name;
	int				flags_reverse_video;
	int				display;
	int				num;
	struct s_arg	*next;
	struct s_arg	*previous;
}					t_arg;
typedef struct		s_data_shell
{
	int				height;
	int				width;
	int				size_lst;
	int				size_lst_mod;
	int				nb_col;
	int				posx;
	int				posy;
	int				cur_col;
	int				last_col_h;
	int				*col_pad;
	int				min;
	int				size_not_enough;
	int				fd;
	t_arg			*cur_elem;
}					t_data_shell;

/*
**list.c
*/
void				ft_add_lst(t_arg **lst, t_arg *new_elem);
t_arg				*ft_create_elem(char *av);
t_arg				*ft_create_lst(t_data_shell *data, char **av);
void				ft_delete_elem(t_data_shell *data);
int					ft_check_alone(t_data_shell *data);
/*
**move_list.c
*/
void				ft_mv_forward(t_data_shell *data, int inc);
void				ft_mv_back(t_data_shell *data, int inc);
/*
**main.c
*/
int					fputchar(int c);
int					ft_read_key(t_data_shell *data);
t_data_shell		*ft_get_data(t_data_shell *data);
int					ft_select(t_data_shell *data);
/*
**init.c
*/
void				ft_init_pos(t_data_shell *data);
int					ft_init_screen();
/*
**manage_term.c
*/
int					ft_getterm_size(t_data_shell *data);
void				ft_chg_term_behavior(t_data_shell *data, int mode);
void				ft_exit_screen();
void				ft_clear_term(t_data_shell *data);
/*
**manage_variable.c
*/
int					ft_count_column(t_data_shell *data, int i, int j, int k);
int					ft_ret_min(t_data_shell *data, t_arg *list);
int					ft_check_width(t_data_shell *data, int j);
int					ft_get_fd(int fd);
/*
**print.c
*/
void				ft_reverse_video(t_data_shell *data);
void				ft_display(t_data_shell *data, t_arg *list, int i, int *j);
void				ft_print_list(t_data_shell *data, t_arg *list);
void				ft_print_elem(t_data_shell *data, char *capability_name);
void				ft_print_selection(t_data_shell *data);
/*
**move.c
*/
void				ft_move(t_data_shell *data, char *buf);
void				ft_mv_right(t_data_shell *data);
void				ft_mv_left(t_data_shell *data);
void				ft_mv_top(t_data_shell *data);
void				ft_mv_bottom(t_data_shell *data);
/*
**specific_move.c
*/
void				ft_rjmp(t_data_shell *data);
void				ft_ljmp(t_data_shell *data);
void				ft_rjmp_exeption(t_data_shell *data);
/*
**signal.c
*/
void				ft_handle_sigcont(t_data_shell *data);
void				ft_handel_sigtstp(t_termios *cpy);
void				ft_set_signals();
void				ft_handle_sig(int sig);
/*
**free.c
*/
void				ft_free(t_data_shell *data);
#endif

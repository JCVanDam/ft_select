/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:13:46 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/11 12:23:56 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_handle_sigcont(t_data_shell *data)
{
	ft_getterm_size(data);
	ft_chg_term_behavior(data, 1);
	ft_clear_term(data);
	ft_init_screen();
	if (ft_count_column(data, 0, -1, -1))
		ft_print_list(data, data->cur_elem);
	else
		write(2, "Size to small", 13);
}

void	ft_handel_sigtstp(t_termios *cpy)
{
	char	cp[3];

	signal(SIGTSTP, SIG_DFL);
	cp[0] = cpy->c_cc[VSUSP];
	cp[1] = '\n';
	cp[2] = '\0';
	ioctl(isatty(STDOUT_FILENO), TIOCSTI, &cp);
}

void	ft_handle_sig(int sig)
{
	t_data_shell		*data;

	data = ft_get_data(NULL);
	if (sig == SIGINT || sig == SIGQUIT || sig == SIGTERM)
	{
		ft_chg_term_behavior(data, 0);
		exit(-1);
	}
	else if (sig == SIGWINCH)
	{
		ft_getterm_size(data);
		ft_clear_term(data);
		ft_init_screen();
		ft_init_pos(data);
		if (ft_count_column(data, 0, -1, -1))
			ft_print_list(data, data->cur_elem);
		else
			write(2, "Size to small", 13);
	}
	else if (sig == SIGTSTP)
		ft_chg_term_behavior(data, 2);
	else if (sig == SIGCONT)
		ft_handle_sigcont(data);
}

void	ft_set_signals(void)
{
	signal(SIGINT, &ft_handle_sig);
	signal(SIGQUIT, &ft_handle_sig);
	signal(SIGTERM, &ft_handle_sig);
	signal(SIGTSTP, &ft_handle_sig);
	signal(SIGCONT, &ft_handle_sig);
	signal(SIGWINCH, &ft_handle_sig);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:30:05 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/11 12:24:46 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_getterm_size(t_data_shell *data)
{
	if (tgetent(NULL, getenv("TERM")) < 0)
		return (0);
	HEIGHT = tgetnum("li");
	WIDTH = tgetnum("co");
	return (1);
}

void	ft_chg_term_behavior(t_data_shell *data, int mode)
{
	t_termios			term;
	static t_termios	*cpy;

	if (mode == 1)
	{
		tcgetattr(STDIN_FILENO, &term);
		cpy = (t_termios *)ft_memalloc(sizeof(t_termios) * 1);
		cpy = ft_memcpy(cpy, &term, sizeof(t_termios) * 1);
		term.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(STDIN_FILENO, TCSADRAIN, &term);
	}
	else
	{
		ft_clear_term(data);
		ft_exit_screen();
		tcsetattr(STDIN_FILENO, TCSADRAIN, cpy);
		if (mode == 2)
			ft_handel_sigtstp(cpy);
	}
}

void	ft_clear_term(t_data_shell *data)
{
	int i;

	i = HEIGHT;
	while (--i >= 0)
	{
		tputs(tgoto(tgetstr("cm", NULL), 0, i), 1, &fputchar);
		tputs(tgetstr("dl", NULL), 1, &fputchar);
	}
}

void	ft_exit_screen(void)
{
	tputs(tgetstr("ve", NULL), 1, &fputchar);
	tputs(tgetstr("cl", NULL), 1, &fputchar);
}

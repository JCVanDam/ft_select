/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 12:28:30 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/11 13:08:34 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_mv_right(t_data_shell *data)
{
	if (CUR_COL + 1 == NB_COL || ((CUR_COL == NB_COL - 2) && CUR_POSY >= COL_H))
		ft_rjmp(data);
	else
	{
		ft_mv_forward(data, HEIGHT + 1);
		CUR_POSX += (COL_PAD[CUR_COL] + 1);
		CUR_COL++;
	}
}

void	ft_mv_left(t_data_shell *data)
{
	if (CUR_COL == 0)
		ft_ljmp(data);
	else
	{
		ft_mv_back(data, HEIGHT + 1);
		CUR_POSX -= (COL_PAD[CUR_COL - 1] + 1);
		CUR_COL--;
	}
}

void	ft_mv_top(t_data_shell *data)
{
	int tmp;

	if (CUR_POSY == 0)
	{
		tmp = (CUR_COL == NB_COL - 1) ? COL_H : HEIGHT;
		tmp = (CUR_COL == 0 && NB_COL == 1) ? COL_H : tmp;
		ft_mv_forward(data, tmp);
		CUR_POSY = --tmp;
	}
	else if (CUR_POSY > 0)
	{
		ft_mv_back(data, 2);
		CUR_POSY--;
	}
}

void	ft_mv_bottom(t_data_shell *data)
{
	if ((CUR_COL != NB_COL - 1) && (CUR_POSY == HEIGHT - 1))
		ft_mv_back(data, HEIGHT);
	else if ((CUR_COL == NB_COL - 1) && CUR_POSY == COL_H - 1)
		ft_mv_back(data, COL_H);
	if ((CUR_POSY == HEIGHT - 1)
		|| ((CUR_COL == NB_COL - 1) && CUR_POSY == COL_H - 1))
		CUR_POSY = 0;
	else
	{
		ft_mv_forward(data, 2);
		CUR_POSY++;
	}
}

void	ft_move(t_data_shell *data, char *buf)
{
	ft_print_elem(data, OFF_UNDERLIGNE);
	ft_print_elem(data, OFF_APPARENCE_MODE);
	if (DISPLAY && FLG_VIDEO)
		ft_print_elem(data, ENTER_REVERSE_MODE);
	if (buf[2] == 67)
		ft_mv_right(data);
	else if (buf[2] == 68)
		ft_mv_left(data);
	else if (buf[2] == 65)
		ft_mv_top(data);
	else if (buf[2] == 66)
		ft_mv_bottom(data);
	ft_print_elem(data, OFF_APPARENCE_MODE);
	ft_print_elem(data, ENTER_UNDERLIGNE);
	if (FLG_VIDEO)
		ft_print_elem(data, ENTER_REVERSE_MODE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 10:53:32 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/11 12:57:07 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_rjmp_exeption(t_data_shell *data)
{
	if ((CUR_POSY == COL_H - 1 && CUR_COL == NB_COL - 1))
	{
		ft_mv_forward(data, 2);
		CUR_POSY = 0;
		CUR_POSX = 0;
		CUR_COL = 0;
	}
	else if (CUR_POSY == HEIGHT - 1)
	{
		ft_mv_forward(data, 2);
		CUR_POSY = 0;
		CUR_POSX += (COL_PAD[CUR_COL++] + 1);
	}
}

void	ft_rjmp(t_data_shell *data)
{
	int tmp;

	if (((CUR_POSY == COL_H - 1 && CUR_COL == NB_COL - 1))
		|| (CUR_POSY == HEIGHT - 1))
		ft_rjmp_exeption(data);
	else
	{
		if (CUR_COL != 0)
		{
			tmp = (CUR_COL + 1 == NB_COL) ? NB_COL - 1 : NB_COL - 2;
			ft_mv_back(data, tmp * HEIGHT);
		}
		else
			ft_mv_forward(data, 2);
		CUR_POSX = 0;
		CUR_POSY++;
		CUR_COL = 0;
	}
}

void	ft_ljmp(t_data_shell *data)
{
	int	tmp;

	tmp = (CUR_POSY > COL_H) ? NB_COL - 1 : NB_COL;
	while (CUR_COL + 1 < tmp)
		CUR_POSX += (COL_PAD[CUR_COL++] + 1);
	if (CUR_POSY == 0)
	{
		ft_mv_back(data, 2);
		CUR_POSY = COL_H - 1;
	}
	else if ((CUR_COL + 1 == NB_COL
		|| ((CUR_COL == NB_COL - 2) && CUR_POSY >= COL_H)) && (CUR_COL == 0))
	{
		ft_mv_back(data, 2);
		CUR_POSY--;
	}
	else
	{
		ft_mv_forward(data, --tmp * HEIGHT);
		CUR_POSY--;
	}
}

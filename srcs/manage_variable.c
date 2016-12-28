/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 14:18:18 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/11 13:08:35 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_check_width(t_data_shell *data, int j)
{
	int	i;
	int max;

	i = -1;
	max = 0;
	while (++i <= j)
		max += COL_PAD[i];
	if (++max >= WIDTH)
	{
		SIZE_NOT_ENOUGH = 1;
		return (0);
	}
	SIZE_NOT_ENOUGH = 0;
	return (1);
}

int		ft_count_column(t_data_shell *data, int i, int j, int k)
{
	size_t	max;
	t_arg	*tmp;

	tmp = CUR_ELEM;
	max = 0;
	NB_COL = (SIZE_LST_MOD % HEIGHT) ? SIZE_LST_MOD / HEIGHT + 1 :
	SIZE_LST_MOD / HEIGHT;
	NB_COL = (SIZE_LST_MOD == HEIGHT + 1) ? NB_COL - 1 : NB_COL;
	if (!(COL_PAD = (int *)ft_memalloc(sizeof(int) * NB_COL + 1)))
		return (-1);
	while (++i && ++k < SIZE_LST)
	{
		max = (ft_strlen((*tmp).name) < max) ? max : ft_strlen((*tmp).name);
		if (i == HEIGHT || k == SIZE_LST - 1)
		{
			COL_PAD[++j] = max;
			max = 0;
			i = 0;
		}
		tmp = tmp->next;
	}
	if (!ft_check_width(data, j))
		return (0);
	return (1);
}

int		ft_ret_min(t_data_shell *data, t_arg *list)
{
	int len;
	int min;

	len = -1;
	min = 0;
	while (++len + 1 < SIZE_LST)
	{
		if (DISPLAY)
			min = (min > list->num) ? list->num : min;
		list = list->next;
	}
	return (min);
}

int		ft_get_fd(int fd)
{
	static int save;

	if (fd != -1)
	{
		save = fd;
		return (0);
	}
	else
		return (save);
}

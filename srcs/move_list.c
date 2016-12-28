/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 13:02:39 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/02 13:04:28 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_mv_forward(t_data_shell *data, int inc)
{
	int	i;

	i = 1;
	while (i < inc)
	{
		CUR_ELEM = CUR_ELEM->next;
		if (DISPLAY)
			i++;
	}
}

void	ft_mv_back(t_data_shell *data, int inc)
{
	int	i;

	i = 1;
	while (i < inc)
	{
		CUR_ELEM = CUR_ELEM->previous;
		if (DISPLAY)
			i++;
	}
}

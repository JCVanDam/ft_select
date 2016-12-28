/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 11:31:15 by maxpetit          #+#    #+#             */
/*   Updated: 2016/08/31 13:52:10 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_free(t_data_shell *data)
{
	int		size;
	int		len;
	t_arg	*tmp;

	len = -1;
	size = SIZE_LST;
	while (data->cur_elem->num != MIN)
		data->cur_elem = data->cur_elem->next;
	while (++len + 1 < size)
	{
		tmp = CUR_ELEM->next;
		free(CUR_ELEM);
		CUR_ELEM = tmp;
	}
	free(COL_PAD);
	COL_PAD = NULL;
}

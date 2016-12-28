/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 13:12:07 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/11 11:57:10 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_init_pos(t_data_shell *data)
{
	CUR_POSX = 0;
	CUR_POSY = 0;
	CUR_COL = 0;
	tputs(tgoto(tgetstr("cm", NULL), CUR_POSX, CUR_POSY), 1, &fputchar);
	while (CUR_ELEM->num != MIN)
		CUR_ELEM = CUR_ELEM->next;
}

int		ft_init_screen(void)
{
	tputs(tgetstr("cl", NULL), 1, &fputchar);
	tputs(tgetstr("vi", NULL), 1, &fputchar);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:51:58 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/11 12:28:37 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_reverse_video(t_data_shell *data)
{
	if (!FLG_VIDEO)
	{
		FLG_VIDEO = 1;
		ft_print_elem(data, ENTER_REVERSE_MODE);
		ft_print_elem(data, OFF_UNDERLIGNE);
		if (ft_check_alone(data))
		{
			ft_mv_bottom(data);
			ft_print_elem(data, OFF_APPARENCE_MODE);
			ft_print_elem(data, ENTER_UNDERLIGNE);
		}
	}
	else
	{
		FLG_VIDEO = 0;
		ft_print_elem(data, OFF_APPARENCE_MODE);
		ft_print_elem(data, ENTER_UNDERLIGNE);
	}
}

void	ft_display(t_data_shell *data, t_arg *list, int i, int *j)
{
	int k;
	int len;

	k = -1;
	len = -1;
	while (++len + 1 < SIZE_LST)
	{
		if (list->display)
		{
			tputs(tgoto(tgetstr("cm", NULL), i, ++(*j)), 1, &fputchar);
			tputs(tgetstr(OFF_UNDERLIGNE, NULL), 1, &fputchar);
			tputs(tgetstr(OFF_APPARENCE_MODE, NULL), 1, &fputchar);
			if (list == CUR_ELEM)
				tputs(tgetstr(ENTER_UNDERLIGNE, NULL), 1, &fputchar);
			if (list->flags_reverse_video)
				tputs(tgetstr(ENTER_REVERSE_MODE, NULL), 1, &fputchar);
			ft_putstr_fd(NAME, FD);
			if (*j + 1 == HEIGHT)
			{
				i += COL_PAD[++k] + 1;
				*j = -1;
			}
		}
		list = list->next;
	}
}

void	ft_print_list(t_data_shell *data, t_arg *list)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (list->num != MIN)
		list = list->next;
	ft_display(data, list, i, &j);
	if (j == -1)
		COL_H = HEIGHT;
	else
		COL_H = j + 1;
}

void	ft_print_elem(t_data_shell *data, char *capability_name)
{
	if (DISPLAY)
	{
		tputs(tgoto(tgetstr("cm", NULL), CUR_POSX, CUR_POSY), 1, &fputchar);
		if (!ft_strcmp(capability_name, "ue"))
			tputs(tgetstr("ue", NULL), 1, &fputchar);
		else if (!ft_strcmp(capability_name, "us"))
			tputs(tgetstr("us", NULL), 1, &fputchar);
		else if (!ft_strcmp(capability_name, "mr"))
			tputs(tgetstr("mr", NULL), 1, &fputchar);
		else if (!ft_strcmp(capability_name, "me"))
			tputs(tgetstr("me", NULL), 1, &fputchar);
		ft_putstr_fd(CUR_ELEM->name, ft_get_fd(-1));
	}
}

void	ft_print_selection(t_data_shell *data)
{
	int len;

	len = -1;
	while (CUR_ELEM->num != MIN)
		CUR_ELEM = CUR_ELEM->next;
	while (++len + 1 < SIZE_LST)
	{
		if (DISPLAY && FLG_VIDEO)
		{
			tputs(tgetstr(OFF_UNDERLIGNE, NULL), 1, &fputchar);
			tputs(tgetstr(OFF_APPARENCE_MODE, NULL), 1, &fputchar);
			ft_putstr(CUR_ELEM->name);
			write(1, " ", 1);
		}
		CUR_ELEM = CUR_ELEM->next;
	}
}

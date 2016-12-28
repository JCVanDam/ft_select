/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:06:31 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/11 12:28:36 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_add_lst(t_arg **lst, t_arg *new_elem)
{
	t_arg *tmp;

	tmp = *lst;
	if (!(*lst))
	{
		new_elem->previous = NULL;
		(*lst) = new_elem;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		new_elem->previous = tmp;
		tmp->next = new_elem;
	}
}

t_arg	*ft_create_elem(char *av)
{
	t_arg		*new;
	static int	num;

	if (!(new = (t_arg *)ft_memalloc(sizeof(t_arg))))
		return (NULL);
	(*new).name = av;
	(*new).flags_reverse_video = 0;
	(*new).num = num++;
	(*new).display = 1;
	(*new).next = NULL;
	return (new);
}

t_arg	*ft_create_lst(t_data_shell *data, char **av)
{
	int		i;
	t_arg	*lst;
	t_arg	*rabbit;
	t_arg	*turtle;

	i = -1;
	lst = NULL;
	while (av[++i])
	{
		rabbit = ft_create_elem(av[i]);
		ft_add_lst(&lst, rabbit);
	}
	SIZE_LST = i + 1;
	SIZE_LST_MOD = SIZE_LST;
	turtle = lst;
	rabbit = lst;
	while (rabbit->next)
		rabbit = rabbit->next;
	turtle->previous = rabbit;
	rabbit->next = turtle;
	lst = turtle;
	return (lst);
}

void	ft_delete_elem(t_data_shell *data)
{
	DISPLAY = 0;
	MIN = ft_ret_min(data, CUR_ELEM);
	tputs(tgetstr("cl", NULL), 1, &fputchar);
	if (CUR_POSY == COL_H - 1 && CUR_COL == NB_COL - 1)
	{
		CUR_POSY = (COL_H == 1) ? HEIGHT - 1 : CUR_POSY - 1;
		CUR_POSX = (COL_H == 1) ? CUR_POSX - (COL_PAD[CUR_COL - 1] + 1)
		: CUR_POSX;
		while (!DISPLAY)
			CUR_ELEM = CUR_ELEM->previous;
	}
	else
		while (!DISPLAY)
			CUR_ELEM = CUR_ELEM->next;
	COL_H--;
	if (COL_H == 0)
	{
		NB_COL--;
		CUR_COL = (CUR_COL == 0) ? CUR_COL : CUR_COL - 1;
		COL_H = HEIGHT;
	}
	SIZE_LST_MOD--;
	ft_print_list(data, CUR_ELEM);
}

int		ft_check_alone(t_data_shell *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++i < SIZE_LST)
	{
		if (DISPLAY)
			j++;
		CUR_ELEM = CUR_ELEM->next;
	}
	if (j == 1)
		return (0);
	return (1);
}

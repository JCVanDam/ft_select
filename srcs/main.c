/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:00:43 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/11 12:59:45 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				fputchar(int c)
{
	int fd;

	fd = ft_get_fd(-1);
	write(fd, &c, 1);
	return (c);
}

int				ft_read_key(t_data_shell *data)
{
	char	buf[4];
	int		i;

	i = 0;
	while (42)
	{
		ft_memset(buf, '\0', 4);
		read(0, buf, 3);
		if (buf[0] == 27 && buf[2] && !SIZE_NOT_ENOUGH)
			ft_move(data, buf);
		else if (buf[0] == 32 && !buf[1] && !SIZE_NOT_ENOUGH)
			ft_reverse_video(data);
		else if (buf[0] == 127 && !buf[1] && !SIZE_NOT_ENOUGH && ++i)
		{
			if (i + 1 == SIZE_LST)
				return (1);
			ft_delete_elem(data);
		}
		else if (buf[0] == 27 && !buf[1])
			return (0);
		else if (buf[0] == '\n' && !SIZE_NOT_ENOUGH)
			return (1);
	}
	return (0);
}

t_data_shell	*ft_get_data(t_data_shell *data)
{
	static t_data_shell	*cpy;

	if (data)
	{
		cpy = data;
		return (NULL);
	}
	return (cpy);
}

int				ft_select(t_data_shell *data)
{
	int i;

	ft_getterm_size(data);
	ft_init_screen();
	if (ft_count_column(data, 0, -1, -1))
		ft_print_list(data, data->cur_elem);
	else
		write(2, "Size to small", 13);
	ft_init_pos(data);
	ft_get_data(data);
	ft_chg_term_behavior(data, 1);
	i = ft_read_key(data);
	ft_chg_term_behavior(data, 0);
	ft_exit_screen(data);
	if (i)
		ft_print_selection(data);
	return (0);
}

int				main(int ac, char **av, char **envp)
{
	t_data_shell	data;
	char			*tmp;

	if (!*envp || ft_tab_srch_idx(envp, "TERM=") == -1)
		write(2, "You need to send an environnement\n", 33);
	else if (ac > 1 && av)
	{
		tmp = ttyname(STDIN_FILENO);
		if ((data.fd = open(tmp, O_WRONLY)) < 0)
			return (0);
		ft_get_fd(data.fd);
		ft_set_signals();
		data.cur_elem = ft_create_lst(&data, &av[1]);
		ft_select(&data);
		ft_free(&data);
		free(tmp);
	}
	return (0);
}

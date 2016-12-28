/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:39:55 by maxpetit          #+#    #+#             */
/*   Updated: 2016/07/20 16:55:42 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_checkback(char *str, int *i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (str[j])
	{
		if (str[j] == '\n')
		{
			if (!k)
				*i = j;
			k++;
		}
		j++;
	}
	return (k);
}

int		ft_belong_list(t_list **list, int fd, char *buff, int ret)
{
	size_t		stop;
	char		*str_tmp;

	stop = (*list) ? (*list)->content_size : 0;
	while (*list)
	{
		if ((*list)->content_size == (size_t)fd)
		{
			if (ret != 0)
			{
				str_tmp = ft_strjoin((*list)->content, buff);
				free((*list)->content);
				(*list)->content = str_tmp;
			}
			return (1);
		}
		*list = (*list)->next;
		if ((*list)->content_size == stop)
			return (0);
	}
	return (0);
}

void	ft_new_el(int const fd, char *buff, t_list **list)
{
	char	*str;
	t_list	*stick;
	t_list	*tmp;

	str = ft_strdup(buff);
	tmp = ft_lstnew(str, BUFF_SIZE + 1);
	((char *)tmp->content)[BUFF_SIZE + 1] = '\0';
	tmp->content_size = fd;
	stick = (*list) ? *list : tmp;
	if (*list)
	{
		while ((*list)->next != stick)
			*list = (*list)->next;
	}
	*list = tmp;
	(*list)->next = stick;
	tmp = stick;
	while (stick->next != tmp)
		stick = stick->next;
	stick->next = *list;
	free(str);
}

int		get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				i;
	int				ret;
	static t_list	*list;
	char			*str_tmp;

	i = 0;
	if ((ret = read(fd, buff, BUFF_SIZE)) < 0)
		return (-1);
	buff[ret] = '\0';
	if (!ft_belong_list(&list, fd, buff, ret))
		ft_new_el(fd, buff, &list);
	if (ret == BUFF_SIZE)
		return (get_next_line(fd, line));
	if (((char *)STR_LIST)[0] == '\0')
		return (0);
	*line = LINE_FEED ? RECOVER_PART_STR : RECOVER_ALL_STR;
	str_tmp = LINE_FEED ? CUT_STR : "\0";
	free(STR_LIST);
	STR_LIST = str_tmp;
	return (1);
}

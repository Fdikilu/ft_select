/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 01:50:36 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/05 18:51:39 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	up(t_list *lst_arg)
{
	int			len;
	int			pos;
	t_arg		*tmp;
	t_select	*select;

	len = ft_lstlen(lst_arg) - 1;
	pos = pos_cursor(lst_arg);
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 0;
	select = get_select();
	if (pos % select->nb_line == 0)
		pos += (select->nb_line - 1);
	else
		pos--;
	if (pos > len)
		pos = len;
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 1;
}

void	down(t_list *lst_arg)
{
	int			len;
	int			pos;
	t_arg		*tmp;
	t_select	*select;

	len = ft_lstlen(lst_arg);
	pos = pos_cursor(lst_arg);
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 0;
	select = get_select();
	if (pos % select->nb_line == select->nb_line - 1)
		pos -= select->nb_line - 1;
	else
		pos++;
	if (pos > len - 1)
		pos = len - (len % select->nb_line);
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 1;
}

void	tab_down(t_list *lst_arg)
{
	int		len;
	int		pos;
	t_arg	*tmp;

	len = ft_lstlen(lst_arg);
	pos = pos_cursor(lst_arg);
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 0;
	pos++;
	pos %= len;
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 1;
}

void	left(t_list *lst_arg)
{
	int			len;
	int			pos;
	t_arg		*tmp;
	t_select	*select;

	len = ft_lstlen(lst_arg);
	pos = pos_cursor(lst_arg);
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 0;
	select = get_select();
	if (pos >= select->nb_line)
		pos -= select->nb_line;
	else
	{
		if (pos < (len % select->nb_line))
			pos = len - (len % select->nb_line) + pos;
		else
			pos = (len - (len % select->nb_line) + pos) - select->nb_line;
	}
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 1;
}

void	right(t_list *lst_arg)
{
	int			len;
	int			pos;
	t_arg		*tmp;
	t_select	*select;

	len = ft_lstlen(lst_arg);
	pos = pos_cursor(lst_arg);
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 0;
	select = get_select();
	pos += select->nb_line;
	if (pos >= len)
		pos %= select->nb_line;
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 1;
}

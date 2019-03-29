/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 01:50:36 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/29 08:14:00 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_select.h>

void	up(t_list *lst_arg)
{
	int		len;
	int		pos;
	t_arg	*tmp;

	len = ft_lstlen(lst_arg) - 1;
	pos = pos_cursor(lst_arg);
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 0;
	pos--;
	if (pos < 0)
		pos = len;
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 1;
}

void	down(t_list *lst_arg)
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

void	left(t_list *lst_arg)//ca marche GIGA pas
{
	int		len;
	int		pos;
	int		nb_line;
	t_arg	*tmp;

	len = ft_lstlen(lst_arg);
	pos = pos_cursor(lst_arg);
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 0;
	nb_line = get_size(len, lst_arg);
	pos -= nb_line;
	if (pos < 0)
	{
		pos = len - (len % nb_line) - (pos + nb_line);
	//	pos = len + pos;
	}
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 1;
}

void	right(t_list *lst_arg)
{
	int		len;
	int		pos;
	int		nb_line;
	t_arg	*tmp;

	len = ft_lstlen(lst_arg);
	pos = pos_cursor(lst_arg);
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 0;
	nb_line = get_size(len, lst_arg);
	pos += nb_line;
	if (pos >= len)
		pos %= nb_line;
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 1;
}

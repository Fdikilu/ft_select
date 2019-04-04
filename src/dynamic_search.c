/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:47:01 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/04 12:33:23 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int	change_focus(int last_pos, char *to_cmp, t_list *lst_arg)
{
	int		pos;
	t_arg	*tmp;

	pos = pos_cursor(lst_arg);
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 0;
	while (lst_arg && last_pos--)
		lst_arg = lst_arg->next;
	while (lst_arg)
	{
		tmp = lst_arg->content;
		if (ft_strncmp(tmp->arg, to_cmp, ft_strlen(to_cmp)) == 0)
		{
			((t_arg *)lst_arg->content)->has_focus = 1;
			return (1);
		}
		lst_arg = lst_arg->next;
	}
	return (0);
}

char		*d_search(char *buff, int *i, char *to_cmp)
{
	t_select	*select;

	select = get_select();
	if ((buff[0] >= 33 && buff[0] <= 126) && (*i < 256))
	{
		to_cmp[*i] = buff[0];
		to_cmp[*i + 1] = '\0';
		(*i)++;
		if (!change_focus(0, to_cmp, select->lst_arg))
		{
			*i = 0;
			ft_strclr(to_cmp);
			((t_arg *)select->lst_arg->content)->has_focus = 1;
		}
	}
	return (to_cmp);
}

void		change_focus_on_tab(t_list *lst_arg)
{
	int			pos;
	t_arg		*tmp;
	t_select	*select;

	select = get_select();
	if (!ft_strlen(select->to_cmp))
		return ;
	pos = pos_cursor(lst_arg);
	if (!change_focus(pos + 1, select->to_cmp, lst_arg))
	{
		tmp = n_arg_lst(pos, &lst_arg);
		tmp->has_focus = 1;
		if (!change_focus(0, select->to_cmp, lst_arg))
		{
			tmp = n_arg_lst(pos, &lst_arg);
			tmp->has_focus = 1;
		}
	}
}

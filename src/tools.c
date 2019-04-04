/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:26:26 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/04 19:52:43 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_select	*get_select(void)
{
	static t_select	*select = NULL;

	if (!select)
		select = init_select();
	return (select);
}

int			pos_cursor(t_list *lst_arg)
{
	int		pos;

	pos = 0;
	while (lst_arg)
	{
		if (((t_arg *)lst_arg->content)->has_focus)
			return (pos);
		pos++;
		lst_arg = lst_arg->next;
	}
	return (pos);
}

t_arg		*n_arg_lst(int n, t_list **lst)
{
	t_list	*elem;

	elem = *lst;
	while (n--)
		elem = elem->next;
	return (elem->content);
}

int			max_length_arg(t_list *lst_arg)
{
	int		max_length;

	max_length = 0;
	while (lst_arg)
	{
		if (ft_strlen(((t_arg *)lst_arg->content)->arg) > max_length)
			max_length = ft_strlen(((t_arg *)lst_arg->content)->arg);
		lst_arg = lst_arg->next;
	}
	max_length += 1;
	return (max_length);
}

int			get_size(int ac)
{
	int				nb_col;
	int				nb_line;
	int				max_length;
	t_select		*select;

	select = get_select();
	max_length = max_length_arg(select->lst_arg);
	nb_col = select->size.ws_col / max_length;
	if ((nb_col <= 0))
		return (0);
	nb_line = ((ac / nb_col) + 1);
	if (nb_line >= select->size.ws_row)
		return (0);
	else
		return (nb_line);
}

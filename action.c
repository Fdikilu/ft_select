/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 02:03:20 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/03 14:07:08 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <term.h>
#include <ft_select.h>

void		to_select(t_list *lst_arg)
{
	int		pos;
	t_arg	*tmp;

	pos = pos_cursor(lst_arg);
	tmp = n_arg_lst(pos, &lst_arg);
	if (tmp->is_selected)
		tmp->is_selected = 0;
	else
		tmp->is_selected = 1;
	tmp->has_focus = 0;
	pos++;
	pos %= ft_lstlen(lst_arg);
	tmp = n_arg_lst(pos, &lst_arg);
	tmp->has_focus = 1;
}

void		to_return(t_list *lst_arg)
{
	t_select	*select;

	select = get_select();
	erase();
	while (lst_arg)
	{
		if (((t_arg *)lst_arg->content)->is_selected)
		{
			ft_putstr(((t_arg *)lst_arg->content)->arg);
			ft_putchar(' ');
		}
		lst_arg = lst_arg->next;
	}
	ft_lstclr(&(select->lst_arg));
	free((void *)select);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	default_term_mode();
	exit(0);
}

static void	del_elem(t_list *previous, t_list **curent, t_list *next)
{
	free((void *)(*curent)->content);
	free((void *)(*curent));
	if (previous)
	{
		*curent = previous;
		(*curent)->next = next;
	}
	else
		*curent = next;
}

void		del(t_list **lst_arg)
{
	t_list	*start;
	t_list	*tmp;

	tmp = NULL;
	start = *lst_arg;
	while (*lst_arg)
	{
		if (((t_arg *)(*lst_arg)->content)->has_focus)
		{
			del_elem(tmp, lst_arg, (*lst_arg)->next);
			if (tmp)
				*lst_arg = start;
			return ;
		}
		tmp = *lst_arg;
		*lst_arg = (*lst_arg)->next;
	}
}

void		quit(void)
{
	t_select	*select;

	select = get_select();
	erase();
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	default_term_mode();
	ft_lstclr(&(select->lst_arg));
	free((void *)select);
	exit(0);
}

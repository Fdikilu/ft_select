/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 02:03:20 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/28 05:25:04 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <ft_select.h>

void	to_select(t_list *lst_arg)
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

void	to_return(t_list *lst_arg)
{
	while (lst_arg)
	{
		if (((t_arg *)lst_arg->content)->is_selected)
		{
			ft_putstr(((t_arg *)lst_arg->content)->arg);
			ft_putchar(' ');// a changer un espace en trop a la fin
		}
		lst_arg = lst_arg->next;
	}
	quit(lst_arg);
}

/*
** void	suppr(t_list *lst_arg)
*/

void	quit(t_list *lst_arg)
{
	char	*cursor;

	ft_lstclr(&lst_arg);
	cursor = tgetstr("ve", NULL);
	tputs(cursor, 1, my_putchar);
	default_term_mode();
	exit(1);
}

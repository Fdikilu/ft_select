/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 00:14:45 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/03 13:53:48 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <ft_select.h>

static void	display_arg(t_arg *elem, int max_length)
{
	if (elem->is_selected)
		tputs(tgetstr("mr", NULL), 1, my_putchar);
	if (elem->has_focus)
		tputs(tgetstr("us", NULL), 1, my_putchar);
	ft_putstr_fd(elem->arg, STDIN_FILENO);
	tputs(tgetstr("me", NULL), 1, my_putchar);
	tputs(tgetstr("ue", NULL), 1, my_putchar);
	while (max_length > ft_strlen(elem->arg))
	{
		ft_putchar_fd(' ', STDIN_FILENO);
		max_length--;
	}
}

void		display(t_list *lst_arg)
{
	int		max_length;
	int		i;
	int		j;
	t_select	*select;
	t_arg	*tmp;

	max_length = max_length_arg(lst_arg);
	select = get_select();
	i = 0;
	while (i < select->nb_line)
	{
		j = i;
		tputs(tgetstr("dC", NULL), 1, my_putchar);
		while (j < ft_lstlen(select->lst_arg))
		{
			tmp = n_arg_lst(j, &lst_arg);
			display_arg(tmp, max_length);
			j += select->nb_line;
		}
		ft_putstr_fd("\r\n", STDIN_FILENO);
		i++;
	}
}

void		move_for_erase(int nb_line)
{
	while (nb_line--)
		tputs(tgetstr("up", NULL), 1, my_putchar);
}

void		erase(void)
{
	tputs(tgetstr("cd", NULL), 1, my_putchar);
}

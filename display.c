/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 00:14:45 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/27 04:30:20 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_select.h>

static void	display_arg(t_arg *elem, int max_length)
{
	if (elem->is_selected)
		ft_putstr_fd("\033[7m", STDIN_FILENO);
	if (elem->has_focus)
		ft_putstr_fd("\033[4m", STDIN_FILENO);
	ft_putstr_fd(elem->arg, STDIN_FILENO);
	ft_putstr_fd("\033[0m", STDIN_FILENO);
	while (max_length > ft_strlen(elem->arg))
	{
		ft_putchar_fd(' ', STDIN_FILENO);
		max_length--;
	}
}

void		display(t_list *lst_arg)
{
	int		lstlen;
	int		max_length;
	int		nb_par_col;
	int		i;
	int		j;
	t_arg	*tmp;

	lstlen = ft_lstlen(lst_arg);
	max_length = max_length_arg(lst_arg);
	nb_par_col = get_size(lstlen, lst_arg);
	i = 0;
	while (i < nb_par_col)
	{
		j = i;
		while (j < lstlen)
		{
			tmp = n_arg_lst(j, &lst_arg);
			display_arg(tmp, max_length);
			j += nb_par_col;
		}
		ft_putstr_fd("\r\n", STDIN_FILENO);
		i++;
	}
}

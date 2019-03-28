/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:26:26 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/28 05:23:36 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <ft_select.h>

int		my_putchar(int c)
{
	write(0, &c, 1);
	return (1);
}

int		pos_cursor(t_list *lst_arg)
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

t_arg	*n_arg_lst(int n, t_list **lst)
{
	t_list	*elem;

	elem = *lst;
	while (n--)
		elem = elem->next;
	return (elem->content);
}

int		max_length_arg(t_list *lst_arg)
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

int		get_size(int ac, t_list *lst_arg)
{
	int				nb_col;
	int				max_length;
	struct winsize	size;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &size) == -1)
		return (0);
	max_length = max_length_arg(lst_arg);
	nb_col = size.ws_col / max_length;
	return ((ac / nb_col) + 1);
}

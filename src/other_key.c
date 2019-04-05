/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:53:20 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/05 18:05:26 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		key_is_space(const char *buff, t_list **lst_arg)
{
	char		*space;
	t_select	*select;

	space = "\x20";
	if (!(ft_memcmp(buff, space, ft_strlen(space)) == 0))
		return (0);
	to_select(*lst_arg);
	select = get_select();
	ft_strclr(select->to_cmp);
	return (1);
}

int		key_is_return(const char *buff, t_list **lst_arg)
{
	char	*ret;

	ret = "\x0a";
	if (!(ft_memcmp(buff, ret, ft_strlen(ret)) == 0))
		return (0);
	to_return(*lst_arg);
	return (1);
}

int		key_is_delete_or_backspace(const char *buff, t_list **lst_arg)
{
	int			pos;
	t_arg		*tmp;
	char		*delete;
	char		*backspace;
	t_select	*select;

	delete = "\x1b\x5b\x33\x7e";
	backspace = "\x7f";
	if ((ft_memcmp(buff, delete, ft_strlen(delete)) == 0) ||
		ft_memcmp(buff, backspace, ft_strlen(backspace)) == 0)
	{
		pos = pos_cursor(*lst_arg);
		del(lst_arg);
		if (!(*lst_arg))
			quit();
		if (pos == ft_lstlen(*lst_arg))
			pos = ft_lstlen(*lst_arg) - 1;
		tmp = n_arg_lst(pos, lst_arg);
		tmp->has_focus = 1;
		erase();
		select = get_select();
		ft_strclr(select->to_cmp);
		return (1);
	}
	return (0);
}

int		key_is_escape(const char *buff, t_list **lst_arg)
{
	char	*escape;

	(void)lst_arg;
	escape = "\x1b";
	if (!(ft_memcmp(buff, escape, ft_strlen(escape)) == 0)
		|| ft_strlen((char *)buff) != 1)
		return (0);
	quit();
	return (1);
}

int		key_is_tab(const char *buff, t_list **lst_arg)
{
	char		*tab;
	t_select	*select;

	tab = "\x09";
	if (ft_memcmp(buff, tab, ft_strlen(tab)) != 0)
		return (0);
	select = get_select();
	if (ft_strlen(select->to_cmp) == 0)
		tab_down(*lst_arg);
	else
		change_focus_on_tab(*lst_arg);
	return (1);
}

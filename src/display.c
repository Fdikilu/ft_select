/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 00:14:45 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/04 20:26:31 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <sys/stat.h>
#include <ft_select.h>

static void	set_color(char *name)
{
	struct stat	s_st;

	if (lstat(name, &s_st) == -1)
	{
		ft_putstr_fd("\033[32m", STDIN_FILENO);
		return ;
	}
	if (S_ISDIR(s_st.st_mode))
		ft_putstr_fd("\033[34m", STDIN_FILENO);
	else if (S_ISCHR(s_st.st_mode))
	{
		ft_putstr_fd("\033[34m", STDIN_FILENO);
		ft_putstr_fd("\033[46m", STDIN_FILENO);
	}
	else if (S_ISBLK(s_st.st_mode))
	{
		ft_putstr_fd("\033[34m", STDIN_FILENO);
		ft_putstr_fd("\033[43m", STDIN_FILENO);
	}
	else if (S_ISFIFO(s_st.st_mode))
		ft_putstr_fd("\033[33m", STDIN_FILENO);
	else if (S_ISLNK(s_st.st_mode))
		ft_putstr_fd("\033[35m", STDIN_FILENO);
	else if (S_ISSOCK(s_st.st_mode))
		ft_putstr_fd("\033[31m", STDIN_FILENO);
}

static void	display_arg(t_arg *elem, int max_length)
{
	t_select	*select;

	select = get_select();
	if (elem->is_selected)
		tputs(tgetstr("mr", NULL), 1, my_putchar);
	if (elem->has_focus)
		tputs(tgetstr("us", NULL), 1, my_putchar);
	if ((ft_strlen(select->to_cmp) > 0) &&
		(ft_strncmp(elem->arg, select->to_cmp, ft_strlen(select->to_cmp)) == 0))
		tputs(tgetstr("md", NULL), 1, my_putchar);
	set_color(elem->arg);
	ft_putstr_fd(elem->arg, STDIN_FILENO);
	ft_putstr_fd("\033[0m", STDIN_FILENO);
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
	int			max_length;
	int			i;
	int			j;
	t_arg		*tmp;
	t_select	*select;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 05:56:25 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/01 07:29:29 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <ft_select.h>

t_select			*init_select(void)
{
	t_select	*select;

	if (!(select = (t_select *)malloc(sizeof(*select))))
		return (NULL);
	tcgetattr(STDIN_FILENO, &select->attr_to_restore);
	ioctl(STDIN_FILENO, TIOCGWINSZ, &(select->size));
	select->lst_arg = NULL;
	return (select);
}

static t_arg	*create_content(char *av)
{
	t_arg	*content;
	
	if (!(content = (t_arg *)malloc(sizeof(t_arg))))
		return(NULL);
	content->is_selected = 0;
	content->has_focus = 0;
	content->arg = av;
	return (content);
}

t_list			*init_arg(char **av)
{
	t_arg	*content;
	t_list	*elem;
	t_list	*list_arg;

	av++;
	list_arg = NULL;
	while (*av)
	{
		if (!(content = create_content(*av)))
		{
			ft_lstclr(&list_arg);
			return (NULL);
		}
		if (!(elem = ft_lstnew(content, sizeof(*content))))
		{
			free((void *)content);
			ft_lstclr(&list_arg);
			return (NULL);
		}
		if (!list_arg)
			list_arg = elem;
		else
			ft_lstaddend(&list_arg, elem);
		av++;
	}
	return (list_arg);
}

void			init_signals(void)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		signal(i, &signal_handler);
		i++;
	}
}

void			init_key(int (*key[8]) (const char *, t_list **))
{
	key[0] = key_is_up_arrow;
	key[1] = key_is_down_arrow;
	key[2] = key_is_left_arrow;
	key[3] = key_is_right_arrow;
	key[4] = key_is_space;
	key[5] = key_is_return;
	key[6] = key_is_delete_or_backspace;
	key[7] = key_is_escape;
	key[8] = NULL;
}

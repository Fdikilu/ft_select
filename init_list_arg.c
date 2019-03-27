/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 02:54:07 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/19 04:39:53 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_select.h>

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
/*
int		main(int ac, char **av)
{
	t_list	*test;
	t_list	*tmp;

	tmp = test;
	if (!(test = init_arg(av)))
		return (0);
	while (test)
	{

		ft_putstr(((t_arg *)test->content)->arg);
		ft_putchar('\n');
		test = test->next;
	}
	ft_lstclr(&tmp);
	return (0);
}*/

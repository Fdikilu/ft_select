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

t_list_arg	*init_arg(char **av)
{
	t_list_arg	*tmp;
	t_list_arg	*list_arg;

	av++;
	tmp = list_arg;
	while (*av)
	{
		if (!(list_arg = (t_list_arg *)malloc(sizeof(t_list_arg))))
		{
			//free list
			return (NULL);
		}
		list_arg->is_selected = 0;
		list_arg->has_focus = 0;
		list_arg->arg = *av;
		list_arg->next = NULL;
		list_arg = list_arg->next;
		av++;
	}
	return (tmp);
}

int		main(int ac, char **av)
{
	t_list_arg	*test;

	if (!(test = init_arg(av)))
		return (0);
	ft_putstr("WESH\n");
	while (test)
	{

	//	ft_putnbr(test->is_selected);
		ft_putstr("Pouet");
		ft_putchar('\n');
		test = test->next;
	}
	return (0);
}

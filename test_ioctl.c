/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ioctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:08:55 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/27 04:48:14 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <term.h>
#include <ft_select.h>

int		my_putchar(int c)
{
	write(0, &c, 1);
	return (1);
}

int		main(int ac, char **av)
{
	char			*test;
	char			*up;
	int				i;
	char			buff[256];
	int				nb_ligne;
	t_list			*lst_arg;
	t_list			*tmp;

	raw_term_mode();
	lst_arg = init_arg(av);
	tmp = lst_arg;
	tmp = tmp->next;
	tmp = tmp->next;
	tmp = tmp->next;
	((t_arg *)lst_arg->content)->has_focus = 1;
	test = tgetstr("dl", NULL);
	up = tgetstr("cm", NULL);
	i = 5;
	while (i--)
	{
		display(lst_arg);
		read(0, buff, 256);
		nb_ligne = get_size(ac, lst_arg);
		tputs(tgoto(up, 0, 3), 1, my_putchar);
		if (i == 3)
			((t_arg *)tmp->content)->has_focus = 1;
		while (nb_ligne--)
			tputs(test, 1, my_putchar);
	}
	default_term_mode();
	return (0);
}

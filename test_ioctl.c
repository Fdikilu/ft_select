/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ioctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:08:55 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/03 13:28:19 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <ft_select.h>

int		my_putchar(int c)
{
	write(0, &c, 1);
	return (1);
}

int		main(int ac, char **av)
{
	int				j;
	char			buff[10];
	char			*term_type;
	t_select		*select;
	int				(*key[9]) (const char *buff, t_list **lst_arg);


	if (ac == 1)
		return (1);
	if (!(term_type = getenv("TERM")))
		return (0);
	if (tgetent(NULL, term_type) <= 0)
		return (0);
	raw_term_mode();
	init_signals();
	init_key(key);
	select = get_select();
	if (!(select->lst_arg = init_arg(av)))
	{
		default_term_mode();
		free((void *)select);
		return (0);
	}
	select->nb_line = get_size(ft_lstlen(select->lst_arg));
	((t_arg *)select->lst_arg->content)->has_focus = 1;
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	while (1)
	{
		j = 0;
		display(select->lst_arg);
		move_for_erase(select->nb_line);
		ft_strclr(buff);
		read(0, buff, 10);
		while (key[j])
		{
			if ((key[j])(buff, &(select->lst_arg)))
				break ;
			j++;
		}
	}
	return (0);
}

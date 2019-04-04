/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:26:42 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/04 20:44:14 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <ft_select.h>

int			my_putchar(int c)
{
	write(0, &c, 1);
	return (1);
}

static void	loop(t_select *select)
{
	int				i;
	int				j;
	char			buff[10];
	int				(*key[9]) (const char *buff, t_list **lst_arg);

	init_key(key);
	i = 0;
	while (1)
	{
		j = 0;
		display(select->lst_arg);
		move_for_erase(select->nb_line);
		ft_strclr(buff);
		read(0, buff, 10);
		while (key[j])
			if ((key[j++])(buff, &(select->lst_arg)))
			{
				if (ft_memcmp(buff, "\x09", ft_strlen("\x09")) != 0)
					i = 0;
				break ;
			}
		ft_strcpy(select->to_cmp, d_search(buff, &i, select->to_cmp));
	}
}

int			main(int ac, char **av)
{
	char			*term_type;
	t_select		*select;

	if (ac == 1)
		return (1);
	if (!(term_type = getenv("TERM")))
		return (0);
	if (tgetent(NULL, term_type) <= 0)
		return (0);
	raw_term_mode();
	init_signals();
	select = get_select();
	av++;
	if (!(select->lst_arg = init_arg(av)))
	{
		default_term_mode();
		free((void *)select);
		return (0);
	}
	select->nb_line = get_size(ft_lstlen(select->lst_arg));
	((t_arg *)select->lst_arg->content)->has_focus = 1;
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	loop(select);
	return (0);
}

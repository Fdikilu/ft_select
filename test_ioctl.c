/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ioctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:08:55 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/30 03:19:22 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <ft_select.h>

int		main(int ac, char **av)
{
	char			*test;
	char			*ret_def;
	char			*clear;
	int				i;
	int				j;
	char			buff[10];
	int				nb_ligne;
	t_list			*lst_arg;
	int				(*key[9]) (const char *buff, t_list *lst_arg);


	if (ac == 1)
		return (1);
	raw_term_mode();
	init_key(key);
	lst_arg = init_arg(av);
	((t_arg *)lst_arg->content)->has_focus = 1;
	test = tgetstr("vi", NULL);
	clear = tgetstr("dl", NULL);
	ret_def = tgetstr("ve", NULL);
	tputs(test, 1, my_putchar);
	i = 5;
	while (1)
	{
		j = 0;
		display(lst_arg);
		nb_ligne = get_size(ft_lstlen(lst_arg), lst_arg);
		ft_putstr("\033[");//remonter le curseur juste en desous du prompt
		ft_putnbr(nb_ligne);
		ft_putstr("A");// done
		ft_strclr(buff);
		read(0, buff, 10);
		while (key[j])
		{
			if ((key[j])(buff, lst_arg))
				break ;
			j++;
		}
		nb_ligne = 4;
		while (nb_ligne--)
			tputs(clear, 1, my_putchar);
	}
	tputs(ret_def, 1, my_putchar);
	default_term_mode();
	return (0);
}

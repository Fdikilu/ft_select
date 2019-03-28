/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ioctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:08:55 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/28 05:40:03 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <ft_select.h>

int		main(int ac, char **av)
{
	char			*test;
	char			*ret_def;
	int				i;
	int				j;
	char			buff[10];
	int				nb_ligne;
	t_list			*lst_arg;
	t_list			*tmp;
	int				(*key[9]) (const char *buff, t_list *lst_arg);


	raw_term_mode();
	init_key(key);
	lst_arg = init_arg(av);
	tmp = lst_arg;
	tmp = tmp->next;
	tmp = tmp->next;
	tmp = tmp->next;
	((t_arg *)lst_arg->content)->has_focus = 1;
	test = tgetstr("vi", NULL);
	ret_def = tgetstr("ve", NULL);
	tputs(test, 1, my_putchar);
	i = 5;
	while (1)
	{
		j = 0;
		display(lst_arg);
		nb_ligne = get_size(ft_lstlen(lst_arg), lst_arg);
		ft_putstr("\033[");
		ft_putnbr(nb_ligne);
		ft_putstr("A");
		ft_strclr(buff);
		read(0, buff, 10);
		while (key[j])
		{
			if ((key[j])(buff, lst_arg))
				break ;
			j++;
		}
		while (nb_ligne--)
			tputs(test, 1, my_putchar);
	}
	tputs(ret_def, 1, my_putchar);
	default_term_mode();
	return (0);
}

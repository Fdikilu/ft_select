/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ioctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:08:55 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/19 02:56:24 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <stdio.h>
#include <curses.h>
#include <term.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <ft_select.h>

int		main(int ac, char **av)
{
	int				ret_ioctl;
	int				nb_col;
	int				nb_par_ligne;
	int				max_length_arg;
	int				i;
	int				j;
	int				k;
	struct winsize	size;

	if ((ret_ioctl = ioctl(0, TIOCGWINSZ, &size)) == -1)
	{
		perror("ioctl");
		return(0);
	}
	printf("largeur: %d\nhauteur: %d\n", size.ws_col, size.ws_row);
	i = 1;
	max_length_arg = 0;
	while (i < ac)
	{
		if (ft_strlen(av[i]) > max_length_arg)
			max_length_arg = ft_strlen(av[i]);
		i++;
	}
	max_length_arg += 2;
	nb_col = size.ws_col / max_length_arg;
	printf("nombre d'arguments: %d\nnombre de col dispo: %d\n", ac - 1, nb_col);
	nb_par_ligne = ((ac - 1) / nb_col) + 1;
	printf("nombre de ligne par col: %d\n", nb_par_ligne);
	i = 1;
	while (i <= nb_par_ligne)
	{
		j = i;
		while (j < ac)
		{
			ft_putstr(av[j]);
			k = max_length_arg;
			while (k > ft_strlen(av[j]))
			{
				ft_putchar(' ');
				k--;
			}
			j += nb_par_ligne;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}

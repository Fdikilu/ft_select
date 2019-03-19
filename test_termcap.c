/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_termcap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:07:00 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/06 21:45:31 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "ft_select.h"
#include "libft/libft.h"

int		my_putstr(int c)
{
	write(1, &c, 1);
	return (1);
}

int		main(int ac, char **av)
{
	int				fd_test;
	int				ret_read;
	int				ret_getent;
	int				ret_setattr;
	char			buff[10];
	char			*term_type;
	char			*test;
	char			*test_vs;
	char			*reset;
	int				nbleft;
	struct termios	term_p;

	/*
	**
	** Initialisation de Termcap ; info charge en mem
	*/
	raw_term_mode();
	/* Fin initialisation */

	test = "\x1b\x5b\x33\x7e";
	read(0, buff, 10);
	if (ft_memcmp(buff, test, ft_strlen(test)) == 0)
		printf("YATA!!!!!!!\r\n");
	printf("%d | %d | %d | %d | %d\r\n", buff[0], buff[1], buff[2], buff[3], buff[4]);
//	ft_putstr("\033[7m"); reverse video
/*	while (1)
	{
		ft_strclr(buff);
		read(0, buff, 10);
		if (ft_strncmp(test, buff, ft_strlen(test)) == 0 || buff[0] == 'a')
		{
			ft_putstr("wesh");
			tputs(test, 10, my_putstr);
			break;
		}
	}*/
	default_term_mode();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tiocsti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 05:20:08 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/01 03:04:23 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <ft_select.h>
/*
int		main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*pseudo_term;
	char	*test;
	struct termios	t_test;

//	if (!(pseudo_term = ttyname(0)))
//		return (0);
	raw_term_mode();
//	fd = open(pseudo_term, O_RDONLY | O_NONBLOCK);
	test = "kill -SIGKILL 31200\r";
	i = 0;
	tcgetattr(0, &t_test);
	while (test[i])
	{
		if (ioctl(0, TIOCSTI, &t_test.c_cc[VSUSP]) == -1)
		{
			perror("ioctl()");
			return (0);
		}
		i++;
	}
	default_term_mode();
	close(fd);
	return (0);
}*/

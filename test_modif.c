/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_modif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:37:40 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/03 21:27:11 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

int		main(void)
{
	int				fd;
	int				ret_getattr;
	int				ret_setattr;
	char			buff[10];
	struct termios	term_p;

	fd = open(ttyname(0), O_RDONLY);

	/* recup les param associe a l'objet reference par fd et stock ds termios */
	if ((ret_getattr = tcgetattr(fd, &term_p)) == -1)
	{
		perror("tcgetattr");
		close(fd);
		return (0);
	}

	/* Modif du param du term en positionnant les bit de la struct termios */
	term_p.c_lflag &= ~(ECHO | ICANON);
	term_p.c_oflag &= ~OPOST;
	term_p.c_cc[VMIN] = 1;
	term_p.c_cc[VTIME] = 0;
	/* Fin de modif Mode raw activated */

	/* fixe les param du term en lisant la struct termios */
	if ((ret_setattr = tcsetattr(fd, TCSANOW , &term_p)) == -1)
	{
		perror("tcgetattr");
		close(fd);
		return (0);
	}
	while (1)
	{
		printf("1");
		ft_strclr(buff);
		read(0, buff, 10);
		if (ft_strlen(buff) == 1)
		{		
			return (0);
		}
		ft_putnbr(ft_strlen(buff));
		ft_putchar(buff[0]);
		ft_putchar(buff[1]);
		ft_putchar(buff[2]);
	}
	close(fd);
	return (0);
}

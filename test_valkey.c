/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valkey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 02:48:37 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/06 18:18:51 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <curses.h>
#include <stdio.h>
#include "ft_select.h"
#include "libft/libft.h"


int		main(void)
{
	char	buff[5];
	int		fd;
	int		ret;
	int		i;

	raw_term_mode();
	fd = open(ttyname(0), O_RDONLY);
	printf("key up: %d\r\n", KEY_UP);
	printf("key down: %d\r\n", KEY_DOWN);
	printf("key left: %d\r\n", KEY_LEFT);
	printf("key right: %d\r\n", KEY_RIGHT);
//	while (*(unsigned int *)buff != ESCAPE)
//	{
		ft_strclr(buff);
		ret = read(fd, buff, 5);
		printf("Valeur de l'input: %u\r\n", *(unsigned int *)buff);
		printf("%d | %d | %d", buff[0], buff[1], buff[2]);
/*		if (*(unsigned int *)buff == KEY_UP)
			printf("YOUR PRESS UP ARROW\n");
		if (*(unsigned int *)buff == KEY_DOWN)
			printf("YOUR PRESS DOWN ARROW\n");
		if (*(unsigned int *)buff == KEY_RIGHT)
			printf("YOUR PRESS RIGHT ARROW\n");
		if (*(unsigned int *)buff == KEY_LEFT)
			printf("YOUR PRESS LEFT ARROW\n");
		if (*(unsigned int *)buff == ESCAPE)
			printf("YOUR PRESS ESCAPE\n");*/
//	}
	close(fd);
	default_term_mode();
	return (0);
}
/*
 *	espace
 *	fleche
 *	entre
 *	delete et backspace mm comportement
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signaux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:50:05 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/30 04:14:21 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <ft_select.h>
/*
void		ft_sigint(int sig)
{
	if (sig == SIGWINCH)
		printf("la fenetre a changer de taille\n");
	else if (sig == SIGKILL || sig == SIGINT || sig == SIGTERM || sig == SIGQUIT)
		printf("Ceci est un test de changement de signal: %d\n", sig);
	else if (sig == SIGTSTP)//signal de ctrl z pour mettre en arriere plan
		printf("Du coup ca part pas en arriere plan\n");
}

int		main(void)
{
	char	*path_term;
	char	buff[3];
	sig_t	test;

	printf("fd 0 est lie a un term: %d\npath du term: %s\n", SIGINT, ttyname(0));
	printf("Sortie de ttyslot %d\n", ttyslot());
	if ((test = signal(SIGINT, &ft_sigint)) == SIG_ERR)
	{
		perror("signal");
		return (errno);
	}
	if ((test = signal(SIGWINCH, &ft_sigint)) == SIG_ERR)
	{
		perror("signal");
		return (errno);
	}
	printf("Changement du signal SIGINT\n");
	while (1)
	{
		ft_strclr(buff);
		read(0, buff, 3);
		if (buff[0] == 'b')
			exit(0);
		if (buff[0] == 'a')
			if (signal(SIGINT, SIG_DFL) == SIG_ERR)
				return (errno);
	}
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 22:21:31 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/28 05:00:20 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_select.h"

static void	signal_handler(int sig)
{
	//free les eventuelle trucs a free
	default_term_mode();
	exit(0);
}

int			change_sigint(void)
{
	if (signal(SIGINT, &signal_handler) == SIG_ERR)
	{
//		default_term_mode(); en fonction de comment je gere la suite
		return (0);
	}
	return (1);
}

int			default_sigint(void)
{
	if (signal(SIGINT, SIG_DFL) == SIG_ERR)
	{
//		defaul_term_mode();
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 22:21:31 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/31 08:04:57 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <ft_select.h>


// if (signal(SIGINT, SIG_DFL) == SIG_ERR)

static void	sig_tstp(void)
{

}

static void	sig_cont(void)
{

}

static void	sig_winch(void)
{
	struct winsize	size;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
	erase(size.ws_row);
}

static void	sig_done(void)
{
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	default_term_mode();
	exit(0);
}

void		signal_handler(int sig)
{
	if (sig == SIGTSTP)
		sig_tstp();
	else if (sig == SIGCONT)
		sig_cont();
	else if (sig == SIGWINCH)
		sig_winch();
	else if (sig == SIGKILL || sig == SIGINT || sig == SIGQUIT || sig == SIGTERM)
		sig_done();
}

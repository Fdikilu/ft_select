/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 22:21:31 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/01 08:58:47 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <term.h>
#include <signal.h>
#include <ft_select.h>

static void	sig_tstp(void)
{
	t_select	*select;

	select = get_select();
	erase(select->size.ws_row);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	default_term_mode();
	if (signal(SIGTSTP, SIG_DFL) == SIG_ERR)
		perror("signal");
	ioctl(STDIN_FILENO, TIOCSTI, &select->attr_to_restore.c_cc[VSUSP]);
}

static void	sig_cont(void)
{
	t_select	*select;

	select = get_select();
	ioctl(STDIN_FILENO, TIOCGWINSZ, &(select->size));
	init_signals();
	raw_term_mode();
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	display(select->lst_arg);
	move_for_erase(select->nb_line);
}

static void	sig_winch(void)
{
	t_select	*select;

	select = get_select();
	erase(select->size.ws_row);
	ioctl(STDIN_FILENO, TIOCGWINSZ, &(select->size));
	select->nb_line = get_size(ft_lstlen(select->lst_arg));//
	display(select->lst_arg);
	move_for_erase(select->nb_line);
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
		quit();
}

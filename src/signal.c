/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 22:21:31 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/03 14:05:28 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <signal.h>
#include <ft_select.h>

static void	sig_tstp(void)
{
	t_select	*select;

	if (!ttyname(1))
		return ;
	select = get_select();
	erase();
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	default_term_mode();
	signal(SIGTSTP, SIG_DFL);
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
	int			old_nb_line;
	t_select	*select;

	erase();
	select = get_select();
	old_nb_line = select->nb_line;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &(select->size));
	select->nb_line = get_size(ft_lstlen(select->lst_arg));
	display(select->lst_arg);
	move_for_erase(select->nb_line);
}

void		signal_handler(int sg)
{
	if (sg == SIGTSTP)
		sig_tstp();
	else if (sg == SIGCONT)
		sig_cont();
	else if (sg == SIGWINCH)
		sig_winch();
	else if (sg == SIGKILL || sg == SIGINT || sg == SIGQUIT || sg == SIGTERM)
		quit();
}

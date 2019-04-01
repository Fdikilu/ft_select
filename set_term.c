/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_term.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:17:18 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/01 07:34:45 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		raw_term_mode(void)
{
	struct termios	tattr;

	if (tcgetattr(STDIN_FILENO, &tattr) == -1)
		return (0);
	tattr.c_lflag &= ~(ECHO | ICANON);
	tattr.c_oflag &= ~(OPOST);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr) == -1)
		return (0);
	return (1);
}

void	default_term_mode(void)
{
	struct termios	tattr;

	if (tcgetattr(STDIN_FILENO, &tattr) == -1)
		return ;
	tattr.c_lflag |= (ECHO | ICANON);
	tattr.c_oflag |= (OPOST);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
}

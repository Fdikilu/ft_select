/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:53:20 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/27 02:53:08 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_select.h"

int		key_is_space(const char *buff)
{
	char	*space;

	space = "\x20";
	if (!(ft_memcmp(buff, space, ft_strlen(space)) == 0))
		return (0);
	return (1);
}

int		key_is_return(const char *buff)
{
	char	*ret;

	ret = "\x0a";
	if (!(ft_memcmp(buff, ret, ft_strlen(ret)) == 0))
		return (0);
	return (1);
}

int		key_is_delete_or_backspace (const char *buff)
{
	char	*delete;
	char	*backspace;

	delete = "\x1b\x5b\x33\x7e";
	backspace = "\x7f";
	if ((ft_memcmp(buff, delete, ft_strlen(delete)) == 0) ||
		ft_memcmp(buff, backspace, ft_strlen(delete)) == 0)
		return (1);
	return (0);
}

int		key_is_escape(const char *buff)
{
	char	*escape;

	escape = "\x1b";
	if (!(ft_memcmp(buff, escape, ft_strlen(escape)) == 0))
		return (0);
	return (1);
}

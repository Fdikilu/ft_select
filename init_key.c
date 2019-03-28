/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 03:42:14 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/28 05:13:37 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_select.h>

void	init_key(int (*key[8]) (const char *, t_list *))
{
	key[0] = key_is_up_arrow;
	key[1] = key_is_down_arrow;
	key[2] = key_is_left_arrow;
	key[3] = key_is_right_arrow;
	key[4] = key_is_space;
	key[5] = key_is_return;
	key[6] = key_is_delete_or_backspace;
	key[7] = key_is_escape;
	key[8] = NULL;
}
/*
int		main(void)
{
	int		(*key[8]) (const char *, t_list *);

	init_key(key);
	return (0);
}*/

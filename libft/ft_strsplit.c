/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:37:55 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/21 15:43:59 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_word(char *s, char c)
{
	if (!s)
		return (0);
	while (*s && *s == c)
		s++;
	if (!(*s))
		return (0);
	while (*s && *s != c)
		s++;
	return (1 + nb_word(s, c));
}

static int	nb_char(char *s, char c)
{
	int		nb;

	nb = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		nb++;
	}
	return (nb);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nb_w;
	int		nb_c;
	char	**tab;

	nb_w = nb_word((char *)s, c);
	if (!s || !(tab = (char **)malloc(sizeof(char *) * (nb_w + 1))))
		return (NULL);
	i = 0;
	tab[nb_w] = 0;
	while (i < nb_w)
	{
		nb_c = nb_char((char *)s, c);
		if (!(tab[i] = ft_strnew(nb_c)))
		{
			ft_tabfree(tab);
			return (NULL);
		}
		while (*s && *s == c)
			s++;
		ft_strncpy(tab[i], (char *)s, nb_c);
		s += nb_c;
		i++;
	}
	return (tab);
}

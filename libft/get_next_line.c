/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:29:05 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/16 20:37:15 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_save	*new_save(int fd)
{
	t_save			*new;

	new = NULL;
	if (!(new = (t_save *)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->rest = ft_strnew(0)))
		return (NULL);
	new->fd = fd;
	return (new);
}

static t_save	*check_l_save(t_list **l_save, int fd)
{
	t_list		*tmp;
	t_save		*tmpsave;

	tmp = NULL;
	if (!(*l_save))
	{
		if (!(tmpsave = new_save(fd)))
			return (NULL);
		if (!(*l_save = ft_lstnew(tmpsave, sizeof(t_save))))
			return (NULL);
		free((void *)tmpsave);
		return ((*l_save)->content);
	}
	tmp = *l_save;
	while (tmp)
	{
		if (((t_save *)tmp->content)->fd == fd)
			return (tmp->content);
		tmp = tmp->next;
	}
	if (!(tmpsave = new_save(fd)))
		return (NULL);
	ft_lstadd(l_save, ft_lstnew(tmpsave, sizeof(t_save)));
	free((void *)tmpsave);
	return ((*l_save)->content);
}

static int		rest_in_line(char **line, char **ctmp, char *rest)
{
	char	*next;

	if (!rest || !(*rest))
		return (0);
	next = ft_strsub(ft_strchr(rest, '\n'), 1, ft_strlen(rest)
		- ft_strclen(rest, '\n'));
	if (next)
	{
		(rest)[ft_strclen(rest, '\n')] = '\0';
		if (!(*line = ft_strdup(rest)))
			return (0);
		rest = ft_strcpy(rest, next);
		free((void *)next);
		return (1);
	}
	else
	{
		if (!(*ctmp = ft_strdup(rest)))
			return (0);
		ft_strclr(rest);
		return (0);
	}
}

static char		*is_processing(char (*buf)[BUFF_SIZE + 1], \
	int ret, char **ctmp, char **tmp)
{
	if (!(*ctmp))
		*ctmp = ft_strnew(0);
	if (!((*buf)[ret] = '\0') && ((size_t)ret == ft_strclen(*buf, '\n')))
	{
		if (!(*ctmp = ft_strjoin_free(*ctmp, *buf)))
			return (NULL);
	}
	else
	{
		ft_strdel(tmp);
		*tmp = ft_strsub(ft_strchr(*buf, '\n'), 1, ret - 1);
		(*buf)[ft_strclen(*buf, '\n')] = '\0';
		return (ft_strjoin_free(*ctmp, *buf));
	}
	return (NULL);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	t_save			*tmp;
	char			*ctmp;
	static t_list	*l_save = NULL;
	char			buf[BUFF_SIZE + 1];

	ctmp = NULL;
	if (!line || !(tmp = check_l_save(&l_save, fd)))
		return (-1);
	if (rest_in_line(line, &ctmp, tmp->rest))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		if ((*line = is_processing(&buf, ret, &ctmp, &tmp->rest)))
			return (1);
		else if (!((size_t)ret == ft_strclen(buf, '\n')))
			return (-1);
	if (!(*line = ctmp))
		*line = "";
	if ((ft_strlen(*line)) > 0)
		return (1);
	(!ret) ? ft_strdel(&tmp->rest) : 0;
	return ((ret == 0) ? 0 : -1);
}

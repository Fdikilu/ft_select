/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:49:59 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/28 05:24:17 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <libft.h>

/*
** liste a affich avec les if necessaire pour l'affichage des select et focus
*/
typedef struct	s_arg
{
	int			is_selected;
	int			has_focus;
	char		*arg;
}				t_arg;

/*
** set terminal
*/
int				raw_term_mode(void);
void			default_term_mode(void);

/*
** Termcap
*/
int		my_putchar(int c);

/*
** gestion des input
*/
int				key_is_up_arrow(const char *buff, t_list *lst_arg);
int				key_is_down_arrow(const char *buff, t_list *lst_arg);
int				key_is_left_arrow(const char *buff, t_list *lst_arg);
int				key_is_right_arrow(const char *buff, t_list *lst_arg);
int				key_is_space(const char *buff, t_list *lst_arg);
int				key_is_return(const char *buff, t_list *lst_arg);
int				key_is_delete_or_backspace(const char *buff, t_list *lst_arg);
int				key_is_escape(const char *buff, t_list *lst_arg);
void			init_key(int (*key[8]) (const char *buff, t_list *lst_arg));

/*
** gestion des signaux
*/
int				change_sigint(void);
int				default_sigint(void);

/*
** set and display arg
*/
int				max_length_arg(t_list *lst_arg);
int				get_size(int ac, t_list *lst_arg);
void			display(t_list *lst_arg);
t_arg			*n_arg_lst(int n, t_list **lst);
t_list			*init_arg(char **av);

/*
** move cursor
*/
int				pos_cursor(t_list *lst_arg);
void			up(t_list *lst_arg);
void			down(t_list *lst_arg);
void			left(t_list *lst_arg);
void			right(t_list *lst_arg);

/*
** action
*/
void			to_select(t_list *lst_arg);
void			to_return(t_list *lst_arg);
void			quit(t_list *lst_arg);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:49:59 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/02 17:53:28 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <libft.h>
#include <termios.h>
#include <sys/ioctl.h>

/*
** structure static pour gerer les signaux
*/
typedef struct		s_select
{
	struct winsize	size;
	int				nb_line;
	struct termios	attr_to_restore;
	t_list			*lst_arg;
}					t_select;

/*
** liste a affich avec les if necessaire pour l'affichage des select et focus
*/
typedef struct		s_arg
{
	int				is_selected;
	int				has_focus;
	char			*arg;
}					t_arg;

/*
** set terminal
*/
int					raw_term_mode(void);
void				default_term_mode(void);

/*
** set select
*/
t_select			*init_select(void);
t_select			*get_select(void);
void				set_size(struct winsize *size);

/*
** gestion des input
*/
int					key_is_up_arrow(const char *buff, t_list **lst_arg);
int					key_is_down_arrow(const char *buff, t_list **lst_arg);
int					key_is_left_arrow(const char *buff, t_list **lst_arg);
int					key_is_right_arrow(const char *buff, t_list **lst_arg);
int					key_is_space(const char *buff, t_list **lst_arg);
int					key_is_return(const char *buff, t_list **lst_arg);
int					key_is_delete_or_backspace(const char *buff, t_list **lst_arg);
int					key_is_escape(const char *buff, t_list **lst_arg);
void				init_key(int (*key[8]) (const char *buff, t_list **lst_arg));

/*
** gestion des signaux
*/
void				init_signals(void);
void				signal_handler(int sig);

/*
** set and display arg
*/
t_list				*init_arg(char **av);
int					max_length_arg(t_list *lst_arg);
t_arg				*n_arg_lst(int n, t_list **lst);
int					get_size(int ac);
void				display(t_list *lst_arg);
void				move_for_erase(int nb_line);
void				erase(void);

/*
** move cursor
*/
int					pos_cursor(t_list *lst_arg);
void				up(t_list *lst_arg);
void				down(t_list *lst_arg);
void				left(t_list *lst_arg);
void				right(t_list *lst_arg);

/*
** action
*/
void				to_select(t_list *lst_arg);
void				to_return(t_list *lst_arg);
void				del(t_list **lst_arg);
void				quit(void);

int					my_putchar(int c);

#endif

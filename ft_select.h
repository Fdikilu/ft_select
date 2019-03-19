/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:49:59 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/19 03:02:02 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

/* liste a affich avec les if necessaire pour l'affichage des select et focus */
typedef struct			s_list_arg
{
	int					is_selected;
	int					has_focus;
	char				*arg;
	struct s_list_arg	*next;
}						t_list_arg;

/* set terminal */
int		raw_term_mode(void);
void	default_term_mode(void);

/* gestion des input */
int		key_is_up_arrow(const char *buff);
int		key_is_down_arrow(const char *buff);
int		key_is_left_arrow(const char *buff);
int		key_is_right_arrow(const char *buff);
int		key_is_space(const char *buff);
int		key_is_return(const char *buff);
int		key_is_delete_or_backspace(const char *buff);
int		key_is_escape(const char *buff);

/* gestion des signaux */
int		change_sigint(void);
int		default_sigint(void);

#endif

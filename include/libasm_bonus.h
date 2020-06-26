/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:34:39 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/06/24 14:40:30 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

/*
**	Define chain list
*/

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

/*
**	Define .s functions
*/

int					ft_list_size(t_list *list);
int					ft_atoi_base(char const *str, char const *base);
void				ft_list_push_front(t_list **list, void *data);
void				ft_list_remove_if(t_list **list,
void *data_ref, int (*cmp)(), void (*free_fct)(void*));
void				ft_list_sort(t_list **list, int (*cmp)());
#endif

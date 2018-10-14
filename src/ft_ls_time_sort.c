/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_time_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:31:48 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/12 18:31:49 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

static void	ft_ls_stm(t_list *lst, int (*func) (t_list *list_i, t_list *list_j))
{
	t_list	*list_i;
	t_list	*list_j;

	list_i = lst;
	if (list_i->next)
	{
		while (list_i->next->data.flname)
		{
			list_j = list_i->next;
			while (list_j->data.flname)
			{
				if (func(list_i, list_j) < 0)
					ft_relink_data(list_i, list_j);
				list_j = list_j->next;
			}
			list_i = list_i->next;
		}
	}
}

void		ft_ls_time_sort_modificator(t_list *lst)
{
	if (g_flag & FLAG_c)
		ft_ls_stm(lst, ft_ls_time_sort_c);
	else if (g_flag & FLAG_U)
		ft_ls_stm(lst, ft_ls_time_sort_up_u);
	else if (g_flag & FLAG_u)
		ft_ls_stm(lst, ft_ls_time_sort_u);
	else
		ft_ls_stm(lst, ft_ls_time_sort);
}

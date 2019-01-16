/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 17:25:06 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/27 17:25:09 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

#define LST list_i->data.sbuf
#define LST_NEXT list_j->data.sbuf

void	ft_relink_data(t_list *cur_d, t_list *next_d)
{
	char			*temp_n;
	struct stat		*temp_sbuf;

	temp_n = cur_d->data.flname;
	cur_d->data.flname = next_d->data.flname;
	next_d->data.flname = temp_n;
	temp_n = cur_d->data.patch;
	cur_d->data.patch = next_d->data.patch;
	next_d->data.patch = temp_n;
	temp_sbuf = cur_d->data.sbuf;
	cur_d->data.sbuf = next_d->data.sbuf;
	next_d->data.sbuf = temp_sbuf;
}

void	ft_ls_sort_mod_size(t_list *lst)
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
				if ((LST->st_size - LST_NEXT->st_size) < 0)
					ft_relink_data(list_i, list_j);
				else if ((LST->st_size - LST_NEXT->st_size) == 0)
				{
					if (ft_strcmp(list_i->data.patch, list_j->data.patch) > 0)
						ft_relink_data(list_i, list_j);
				}
				list_j = list_j->next;
			}
			list_i = list_i->next;
		}
	}
}

void	ft_ls_sort(t_list *lst, int (*func)(const char *, const char *))
{
	t_list	*list_i;
	t_list	*list_j;

	list_i = lst;
	if (list_i && list_i->next)
	{
		while (list_i->next->data.flname)
		{
			list_j = list_i->next;
			while (list_j->data.flname)
			{
				if (func(list_i->data.patch, list_j->data.patch) > 0)
					ft_relink_data(list_i, list_j);
				list_j = list_j->next;
			}
			list_i = list_i->next;
		}
	}
}

void	ft_ls_sort_rev(t_list *lst, int (*func)(const char *, const char *))
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
				if (func(list_i->data.patch, list_j->data.patch) < 0)
					ft_relink_data(list_i, list_j);
				list_j = list_j->next;
			}
			list_i = list_i->next;
		}
	}
}

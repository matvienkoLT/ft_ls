/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort_time_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:33:45 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/12 20:33:45 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

#define LST			list_i->data.sbuf
#define LST_NEXT	list_j->data.sbuf

int	ft_ls_time_sort(t_list *list_i, t_list *list_j)
{
	long long int r;

	r = LST->st_mtimespec.tv_sec - LST_NEXT->st_mtimespec.tv_sec;
	if (r == 0)
	{
		r = LST->st_mtimespec.tv_nsec - LST_NEXT->st_mtimespec.tv_nsec;
		if (r == 0)
			return (ft_strcmp(list_j->data.patch, list_i->data.patch));
	}
	return (r);
}

int	ft_ls_time_sort_up_u(t_list *list_i, t_list *list_j)
{
	long long int	r;

	r = LST->st_birthtimespec.tv_sec - LST_NEXT->st_birthtimespec.tv_sec;
	if (r == 0)
	{
		r = LST->st_birthtimespec.tv_nsec - LST_NEXT->st_birthtimespec.tv_nsec;
		if (r == 0)
			return (ft_strcmp(list_j->data.patch, list_i->data.patch));
	}
	return (r);
}

int	ft_ls_time_sort_u(t_list *list_i, t_list *list_j)
{
	long long int	r;

	r = LST->st_atimespec.tv_sec - LST_NEXT->st_atimespec.tv_sec;
	if (r == 0)
	{
		r = LST->st_atimespec.tv_nsec - LST_NEXT->st_atimespec.tv_nsec;
		if (r == 0)
			return (ft_strcmp(list_j->data.patch, list_i->data.patch));
	}
	return (r);
}

int	ft_ls_time_sort_c(t_list *list_i, t_list *list_j)
{
	long long int r;

	r = LST->st_ctimespec.tv_sec - LST_NEXT->st_ctimespec.tv_sec;
	if (r == 0)
	{
		r = LST->st_ctimespec.tv_nsec - LST_NEXT->st_ctimespec.tv_nsec;
		if (r == 0)
			return (ft_strcmp(list_j->data.patch, list_i->data.patch));
	}
	return (r);
}

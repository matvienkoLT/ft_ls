/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dircurrent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 17:24:36 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/27 17:24:40 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

t_list		*create_list(void)
{
	t_list	*node;

	node = (t_list*)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data.flname = NULL;
	node->data.patch = NULL;
	node->data.sbuf = NULL;
	node->behind = NULL;
	node->next = NULL;
	return (node);
}

static void	ft_ls_recursion(t_list *lst)
{
	t_list	*list;

	list = lst;
	while (list->data.flname)
	{
		if (S_ISDIR(list->data.sbuf->st_mode) &&
		(ft_strcmp(".", list->data.flname) != 0 ||
		(ft_strcmp("..", list->data.flname) == 0)))
			ft_ls_dir_open(list);
		list = list->next;
	}
}

void		ft_ls_sort_n_print(t_lst_type *lst, int *dir_c)
{
	ft_ls_type_sort(lst->lst_error_begin);
	ft_ls_type_sort(lst->lst_file_begin);
	ft_ls_type_sort(lst->lst_dir_begin);
	ft_ls_errno_printer(lst->lst_error_begin);
	ft_ls_file_printer(lst->lst_file_begin, 0);
	ft_mem_cleaner(lst->lst_file_begin);
	ft_ls_dir_printer(lst->lst_dir_begin, *dir_c);
}

void		ft_ls_type_sort(t_list *lst)
{
	if (g_flag & FLAG_r)
		ft_ls_sort_rev(lst, ft_strcmp);
	else if (g_flag & FLAG_t)
		ft_ls_time_sort_modificator(lst);
	else if (g_flag & FLAG_S)
		ft_ls_sort_mod_size(lst);
	else
		ft_ls_sort(lst, ft_strcmp);
}

int			ft_current_dir(char *str)
{
	t_list *lst;

	if (!(lst = create_list()))
		return (-1);
	if (ft_dcontent(str, lst) == -1)
	{
		ft_mem_cleaner(lst);
		return (-1);
	}
	ft_ls_type_sort(lst);
	if (!(g_flag & FLAG_l))
		ft_ls_printer(lst, 0);
	else
		ft_ls_file_printer(lst, 1);
	if (g_flag & FLAG_R)
		ft_ls_recursion(lst);
	ft_mem_cleaner(lst);
	return (0);
}

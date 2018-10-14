/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 21:06:03 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/28 21:06:04 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

int		err_file_not_found(void)
{
	write(2, "ls: : No such file or directory\n", 32);
	return (-1);
}

void	bad_file_descriptor(char *str)
{
	ft_printf("ft_ls: %s : %s\n", str, strerror(errno));
}

void	ft_ls_dir_open(t_list *list)
{
	if (ft_strcmp("..", list->data.flname) != 0)
	{
		ft_printf("\n%s:\n", list->data.patch);
		ft_current_dir(list->data.patch);
	}
}

void	ft_ls_mod_d(int argc, int *i, char **argv)
{
	if (g_flag & FLAG_d && *i == argc)
	{
		*i = *i - 1;
		*argv = ".";
	}
}

int		ft_ls_aligment_size(t_list *lst)
{
	int val;
	int temp;

	val = 0;
	while (lst->data.flname)
	{
		if (val < (temp = ft_dgt_quntt(lst->data.sbuf->st_nlink)))
			val = temp;
		lst = lst->next;
	}
	return (val);
}

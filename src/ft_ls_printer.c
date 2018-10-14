/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 19:24:43 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/27 19:24:43 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_ls_link_printer(struct stat *sb, char *path)
{
	char	*link_name;
	ssize_t	r;

	if ((link_name = ft_strnew(sb->st_size)))
	{
		if ((r = readlink(path, link_name, sb->st_size + 1)) > 0)
			ft_printf(" -> %s", link_name);
	}
	free(link_name);
}

void	ft_ls_printer(t_list *lst, int align_r)
{
	(void)align_r;
	while (lst->data.flname)
	{
		if (g_flag & FLAG_s)
			ft_ls_printer_mod_s(lst, align_r);
		if (g_flag & FLAG_G)
			ft_printf("{yellow}%s\n{blue}", lst->data.flname);
		else
			ft_printf("%s\n", lst->data.flname);
		lst = lst->next;
	}
}

void	ft_ls_errno_printer(t_list *lst)
{
	t_list	*s_pnt;

	s_pnt = lst;
	while (s_pnt->data.flname)
	{
		ft_printf("ft_ls: %s : %s\n", s_pnt->data.flname, strerror(errno));
		s_pnt = s_pnt->next;
	}
	ft_mem_cleaner(lst);
}

void	ft_ls_file_printer(t_list *lst, int sw)
{
	int	prmt[4];

	if (g_flag & FLAG_l)
		ft_column_sz(lst, prmt, sw);
	else
	{
		if (g_flag & FLAG_s)
			prmt[0] = ft_ls_aligment_size(lst);
		ft_ls_printer(lst, 0);
	}
}

void	ft_ls_dir_printer(t_list *lst, int dir_c)
{
	t_list	*s_pnt;

	s_pnt = lst;
	(void)dir_c;
	while (s_pnt->data.flname)
	{
		if (dir_c > 1)
			ft_printf("%s:\n", s_pnt->data.patch);
		ft_current_dir(s_pnt->data.patch);
		s_pnt = s_pnt->next;
		if (s_pnt && s_pnt->data.flname)
			ft_printf("\n");
	}
	ft_mem_cleaner(lst);
}

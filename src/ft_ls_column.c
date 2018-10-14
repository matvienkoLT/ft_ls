/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:20:03 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/03 16:20:04 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

#define PATCH		lst->data.patch
#define SBUF        lst->data.sbuf
#define LS_MINOR    minor(lst->data.sbuf->st_rdev)
#define LS_MAJOR    major(lst->data.sbuf->st_rdev)
#define LLI         long long int

static void	ft_max_value(int *plst, t_list *lst)
{
	int temp;

	if (plst[0] < (temp = ft_dgt_quntt(SBUF->st_nlink)))
		plst[0] = temp;
	if (plst[1] < (temp = (int)ft_strlen(getpwuid(SBUF->st_uid)->pw_name)))
		plst[1] = temp;
	if (plst[2] < (temp = (int)ft_strlen(getgrgid(SBUF->st_gid)->gr_name)))
		plst[2] = temp;
	if (plst[3] < (temp = ft_dgt_quntt(SBUF->st_size)))
		plst[3] = temp;
}

static void	ft_ls_pwd_description(t_list *lst, int *prmt, int f_type)
{
	struct passwd	*pwd;
	struct group	*grp;

	if (!(g_flag & FLAG_g))
	{
		if ((pwd = getpwuid(lst->data.sbuf->st_uid)))
			ft_printf("%-*s  ", prmt[1], pwd->pw_name);
	}
	if (!(g_flag & FLAG_o))
	{
		if ((grp = getgrgid(lst->data.sbuf->st_gid)))
			ft_printf("%-*s  ", prmt[2], grp->gr_name);
	}
	if ((g_flag & FLAG_g) && (g_flag & FLAG_o))
		ft_printf("  ");
	if (!f_type)
		ft_printf("%*lli", prmt[3], lst->data.sbuf->st_size);
	else
		ft_printf("  %lli, %lli", (LLI)LS_MAJOR, (LLI)LS_MINOR);
}

static void	ft_ls_tb_crtr(t_list *lst, int *prmt, int sw)
{
	int f_type;

	while (lst->data.flname)
	{
		if (g_flag & FLAG_s)
			ft_ls_printer_mod_s(lst, prmt[0]);
		f_type = ft_ls_file_type(lst->data.sbuf->st_mode);
		ft_ls_permission(lst->data.sbuf->st_mode);
		ft_putchar(listxattr(PATCH, 0, 0, XATTR_NOFOLLOW) > 0 ? '@' : ' ');
		ft_printf(" %*i ", prmt[0], lst->data.sbuf->st_nlink);
		ft_ls_pwd_description(lst, prmt, f_type);
		ft_ls_display_time(lst);
		if (sw == 1)
			ft_printf(" %s", lst->data.flname);
		else
			ft_printf(" %s", lst->data.patch);
		if (S_ISLNK(lst->data.sbuf->st_mode))
			ft_ls_link_printer(lst->data.sbuf, lst->data.patch);
		ft_printf("\n");
		lst = lst->next;
	}
}

void		ft_column_sz(t_list *lst, int *prmt, int sw)
{
	t_list			*plst;
	long long int	sz_block;

	plst = lst;
	sz_block = 0;
	ft_memset(&(*prmt), 0, (sizeof(int) * 4));
	if (plst->data.flname)
	{
		while (plst->data.flname)
		{
			ft_max_value(&(*prmt), plst);
			sz_block += plst->data.sbuf->st_blocks;
			plst = plst->next;
		}
		if (sw == 1)
			ft_printf("total %lli\n", sz_block);
		ft_ls_tb_crtr(lst, prmt, sw);
	}
}

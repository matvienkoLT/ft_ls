/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_arg_dfl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:57:43 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/28 18:57:44 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

#define LST_ERR  lst.lst_error
#define LST_DIR  lst.lst_dir
#define LST_FILE lst.lst_file
#define LST_TEMP lst.temp_d
#define ST_MODE  lst->temp_d.sbuf->st_mode

static void	ft_init_poiter(t_lst_type *lst)
{
	lst->lst_dir = create_list();
	lst->lst_error = create_list();
	lst->lst_file = create_list();
	lst->lst_dir_begin = lst->lst_dir;
	lst->lst_error_begin = lst->lst_error;
	lst->lst_file_begin = lst->lst_file;
	lst->temp_d.flname = NULL;
	lst->temp_d.patch = NULL;
}

static void	ft_ls_add_lst(t_list **lst, char *argv)
{
	(*lst)->data.flname = ft_strdup(argv);
	(*lst)->next = create_list();
	(*lst)->next->behind = (*lst);
	*(lst) = (*lst)->next;
}

static void	ft_ls_tmp_p_lst(t_list **lst, t_dirarg *tmp)
{
	(*lst)->data.patch = tmp->patch;
	(*lst)->data.flname = tmp->flname;
	(*lst)->data.sbuf = tmp->sbuf;
	(*lst)->next = create_list();
	(*lst)->next->behind = (*lst);
	*(lst) = (*lst)->next;
}

static void	ft_ls_dcsn_tp(t_lst_type *lst, char *argv, int *dir_c)
{
	char	*temp;

	if ((temp = ft_strrchr(argv, '/')))
		lst->temp_d.flname = ft_strdup(temp + 1);
	else
		lst->temp_d.flname = ft_strdup(argv);
	lst->temp_d.patch = ft_strdup(argv);
	if ((((S_ISLNK(ST_MODE) && !(g_flag & FLAG_l)) ||
		(S_ISDIR(ST_MODE))) && !(g_flag & FLAG_d))
		&& stat(argv, lst->temp_d.sbuf) != EPERM)
	{
		ft_ls_tmp_p_lst(&lst->lst_dir, &lst->temp_d);
		*(dir_c) += 1;
	}
	else
		ft_ls_tmp_p_lst(&lst->lst_file, &lst->temp_d);
}

int			ft_ls_arg_dfl(int i, int argc, char **argv)
{
	t_lst_type	lst;
	int			k;
	int			dir_c;

	ft_init_poiter(&lst);
	dir_c = 0;
	ft_ls_mod_d(argc, &i, &argv[i - 1]);
	while (i < argc)
	{
		lst.temp_d.sbuf = (struct stat*)malloc(sizeof(struct stat));
		if (argv[i][0] == '\0')
			return (err_file_not_found());
		if ((k = lstat(argv[i], lst.temp_d.sbuf)) == -1)
		{
			ft_ls_add_lst(&lst.lst_error, argv[i]);
			free(lst.temp_d.sbuf);
		}
		else
			ft_ls_dcsn_tp(&lst, argv[i], &dir_c);
		i++;
	}
	ft_ls_sort_n_print(&lst, &dir_c);
	return (0);
}

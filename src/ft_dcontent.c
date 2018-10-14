/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcontent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 17:24:25 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/17 13:42:45 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

static char		*ft_patch_crt(char *patch, char *dir_name)
{
	char *temp;
	char *res_str;

	temp = ft_strjoin(patch, "/");
	res_str = ft_strjoin(temp, dir_name);
	free(temp);
	return (res_str);
}

static t_list	*ft_next_data(t_list *lst, struct dirent *dr, char *str)
{
	if (!(lst->data.flname = ft_strdup(dr->d_name)))
		return (NULL);
	if (!(lst->data.patch = ft_patch_crt(str, dr->d_name)))
		return (NULL);
	if (!(lst->data.sbuf = (struct stat*)malloc(sizeof(struct stat))))
		return (NULL);
	if ((lstat(lst->data.patch, lst->data.sbuf)) == -1)
		return (NULL);
	lst->next = create_list();
	lst->next->behind = lst;
	lst = lst->next;
	return (lst);
}

int				ft_dcontent(char *str, t_list *list)
{
	DIR				*odir;
	t_list			*lst;
	struct dirent	*dir;

	lst = list;
	if ((odir = opendir(str)) == NULL)
	{
		bad_file_descriptor(str);
		return (-1);
	}
	while ((dir = readdir(odir)) != NULL)
	{
		if (dir->d_name[0] == '.' && !(g_flag & FLAG_a))
			continue;
		if (!(lst = ft_next_data(lst, dir, str)))
		{
			ft_mem_cleaner(lst);
			return (-1);
		}
	}
	closedir(odir);
	return (0);
}

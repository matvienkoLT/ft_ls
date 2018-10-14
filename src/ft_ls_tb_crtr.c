/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_tb_crtr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:36:43 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/04 18:36:44 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

int			ft_ls_file_type(mode_t b)
{
	int mode;
	int status;

	mode = b & S_IFMT;
	if (S_IFIFO == mode)
		write(1, "f", 1);
	else if (S_IFBLK == mode)
	{
		write(1, "b", 1);
		status = 1;
	}
	else if (S_IFLNK == mode)
		write(1, "l", 1);
	else if (S_IFSOCK == mode)
		write(1, "s", 1);
	else if (S_IFDIR == mode)
	{
		write(1, "d", 1);
		status = 1;
	}
	else if (S_IFCHR == mode)
		write(1, "c", 1);
	else
		write(1, "-", 1);
	return (0);
}

static void	ft_ls_permission_p(mode_t b, char *str)
{
	if (b & S_ISUID)
	{
		if (b & S_IXUSR)
			str[2] = 's';
		else
			str[2] = 'S';
	}
	else
	{
		if (b & S_IXUSR)
			str[2] = 'x';
		else
			str[2] = '-';
	}
}

static void	ft_ls_permission_th(mode_t b, char *str)
{
	if (b & S_ISGID)
	{
		if (b & S_IXGRP)
			str[5] = 's';
		else
			str[5] = 'S';
	}
	else
	{
		if (b & S_IXGRP)
			str[5] = 'x';
		else
			str[5] = '-';
	}
}

static void	ft_ls_permission_fr(mode_t b, char *str)
{
	if (b & S_IROTH)
		str[6] = 'r';
	else
		str[6] = '-';
	if (b & S_IWOTH)
		str[7] = 'w';
	else
		str[7] = '-';
	if (b & S_ISVTX)
	{
		if (b & S_IXOTH)
			str[8] = 't';
		else
			str[8] = 'T';
	}
	else
	{
		if (b & S_IXOTH)
			str[8] = 'x';
		else
			str[8] = '-';
	}
	str[9] = '\0';
}

void		ft_ls_permission(mode_t b)
{
	char str[10];

	if (b & S_IRUSR)
		str[0] = 'r';
	else
		str[0] = '-';
	if (b & S_IWUSR)
		str[1] = 'w';
	else
		str[1] = '-';
	ft_ls_permission_p(b, &(*str));
	if (b & S_IRGRP)
		str[3] = 'r';
	else
		str[3] = '-';
	if (b & S_IWGRP)
		str[4] = 'w';
	else
		str[4] = '-';
	ft_ls_permission_th(b, &(*str));
	ft_ls_permission_fr(b, &(*str));
	write(1, &(*str), 9);
}

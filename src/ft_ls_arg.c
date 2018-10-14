/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:42:07 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/27 20:42:09 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

static int	ft_ls_cmp_flag_s(char *argv, int i)
{
	if (argv[i] == 'u')
		g_flag |= FLAG_u;
	else if (argv[i] == 'U')
		g_flag |= FLAG_U;
	else if (argv[i] == 'c')
		g_flag |= FLAG_c;
	else if (argv[i] == 'T')
		g_flag |= FLAG_T;
	else if (argv[i] == 't')
		g_flag |= FLAG_t;
	else if (argv[i] == 's')
		g_flag |= FLAG_s;
	else if (argv[i] == 'G')
		g_flag |= FLAG_G;
	else if (argv[i] == 'S')
		g_flag |= FLAG_S;
	else
		return (0);
	return (1);
}

static int	ft_ls_cmp_flag(char *argv, int i)
{
	if (argv[i] == 'R')
		g_flag |= FLAG_R;
	else if (argv[i] == 'l')
		g_flag |= FLAG_l;
	else if (argv[i] == 'a')
		g_flag |= FLAG_a;
	else if (argv[i] == 'r')
		g_flag |= FLAG_r;
	else if (argv[i] == 'd')
		g_flag |= FLAG_d;
	else if (argv[i] == 'g')
		g_flag |= FLAG_g;
	else if (argv[i] == 'o')
		g_flag |= FLAG_o;
	else if (!(ft_ls_cmp_flag_s(argv, i)))
		return (0);
	return (1);
}

static int	ft_ls_cmp_arg(char *argv)
{
	int i;

	i = 1;
	if (!ft_strcmp(argv, "--"))
		return (0);
	while (argv[i] != '\0')
	{
		if (!ft_ls_cmp_flag(argv, i))
			return (-1);
		i++;
	}
	return (1);
}

int			ft_ls_arg(char **str, int rgc)
{
	int i;
	int result;

	i = 1;
	while (i < rgc && str[i][0] == '-' && str[i][1] != '\0')
	{
		if ((result = ft_ls_cmp_arg(str[i])) == -1)
			return (-1);
		else if (result == 0)
			break ;
		i++;
	}
	if (i < rgc)
	{
		if ((ft_ls_arg_dfl(i, rgc, str)) == -1)
			return (-1);
	}
	else
	{
		if (g_flag & FLAG_d)
			return (ft_ls_arg_dfl(i, rgc, str));
		if (ft_current_dir(".") == -1)
			return (EXIT_FAILURE);
	}
	return (1);
}

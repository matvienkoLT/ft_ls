/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 17:25:17 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/27 17:25:19 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

int	main(int argc, char **argv)
{
	g_flag = 0;
	if (argc == 1)
	{
		if (ft_current_dir(".") == -1)
			return (EXIT_FAILURE);
	}
	else if (argc > 1)
	{
		if (ft_ls_arg(argv, argc) == -1)
		{
			ft_ls_bad_arg();
			return (EXIT_FAILURE);
		}
	}
	return (0);
}

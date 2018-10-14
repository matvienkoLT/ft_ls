/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_printer_mod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 20:45:18 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/19 20:45:20 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

#define SBUF lst->data.sbuf

int		ft_dgt_quntt(unsigned int n)
{
	int	quantt;

	if (n == 0)
		return (1);
	quantt = 0;
	while (n > 0)
	{
		n /= 10;
		quantt++;
	}
	return (quantt);
}

void	ft_ls_printer_mod_s(t_list *lst, int align_r)
{
	long long int	temp;
	int				remainder;

	if (!S_ISDIR(SBUF->st_mode))
	{
		if (SBUF->st_size < 4096 && SBUF->st_size != 0)
			ft_printf("%*lli ", align_r, 8);
		else if ((temp = SBUF->st_size / 512) > 0)
		{
			if ((remainder = temp % 8) > 0)
			{
				temp += (8 - remainder);
			}
			ft_printf("%*lli ", align_r, temp);
		}
	}
	else
		ft_printf("%*lli ", align_r, 0);
}

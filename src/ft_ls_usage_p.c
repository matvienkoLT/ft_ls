/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_usage_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:42:34 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/21 10:42:35 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_ls_bad_arg(void)
{
	char	*line;

	line = "usage: ./ft_ls [-RUTGSacdglostu] [file ...]\n";
	ft_printf("%s", line);
}

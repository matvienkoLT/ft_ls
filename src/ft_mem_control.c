/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 19:03:01 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/27 19:03:02 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_mem_cleaner(t_list *list)
{
	while (list->data.flname)
	{
		free(list->data.flname);
		free(list->data.patch);
		if (list->data.sbuf)
			free(list->data.sbuf);
		if (list->behind)
			free(list->behind);
		list = list->next;
	}
	if (list->behind)
		free(list->behind);
	if (list)
		free(list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_display_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:15:27 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/07 10:15:29 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

#define SIX_MONTH 15811200

static time_t	*ft_ls_dspl_time(t_list *lst)
{
	if (g_flag & FLAG_u)
		return (&lst->data.sbuf->st_atimespec.tv_sec);
	else if (g_flag & FLAG_U)
		return (&lst->data.sbuf->st_birthtimespec.tv_sec);
	else if (g_flag & FLAG_c)
		return (&lst->data.sbuf->st_ctimespec.tv_sec);
	else
		return (&lst->data.sbuf->st_mtimespec.tv_sec);
}

void			ft_ls_display_time(t_list *lst)
{
	char	*the_time;
	time_t	*cr_time;
	time_t	ls_time;

	ls_time = time(0);
	cr_time = ft_ls_dspl_time(lst);
	the_time = ctime(cr_time);
	if (g_flag & FLAG_T)
		ft_printf(" %3.3s %2.2s %8.8s %4.4s", the_time + 8,
			the_time + 4, the_time + 11, the_time + 20);
	else if (FT_ABS((long long int)(ls_time - *cr_time)) > SIX_MONTH)
		ft_printf(" %3.3s %2.2s  %4.4s", the_time + 4, the_time + 8,
			the_time + 20);
	else
		ft_printf(" %3.3s %2.2s %5.5s", the_time + 4, the_time + 8,
		the_time + 11);
}

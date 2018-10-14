/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 17:24:53 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/27 17:24:59 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_HEADER_H

# define FT_LS_HEADER_H
# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>
# include <time.h>
# include <limits.h>
# include <unistd.h>
# include <errno.h>
# include <sys/xattr.h>

# define FT_ABS(x) (((x)<0)?-(x):(x))
# define CC	const char

long long int		g_flag;

enum				e_flags
{
	FLAG_a = 2,
	FLAG_l = 4,
	FLAG_R = 8,
	FLAG_r = 16,
	FLAG_d = 32,
	FLAG_g = 64,
	FLAG_o = 128,
	FLAG_u = 256,
	FLAG_U = 512,
	FLAG_c = 1024,
	FLAG_T = 2048,
	FLAG_t = 4096,
	FLAG_s = 8192,
	FLAG_G = 16384,
	FLAG_S = 32768
};

typedef struct		s_dirarg
{
	struct stat		*sbuf;
	char			*flname;
	char			*patch;
}					t_dirarg;

typedef struct		s_list
{
	t_dirarg		data;
	struct s_list	*next;
	struct s_list	*behind;
}					t_list;

typedef struct		s_lst_type
{
	t_list			*lst_dir;
	t_list			*lst_file;
	t_list			*lst_error;
	t_list			*lst_dir_begin;
	t_list			*lst_file_begin;
	t_list			*lst_error_begin;
	t_dirarg		temp_d;
}					t_lst_type;

t_list				*create_list();
int					ft_dgt_quntt(unsigned int n);
int					ft_ls_aligment_size(t_list *lst);
void				ft_relink_data(t_list *cur_d, t_list *next_d);
int					ft_current_dir(char *str);
int					ft_dcontent(char *str, t_list *lst);
int					ft_ls_arg(char **argv, int argc);
int					ft_ls_arg_dfl(int i, int argc, char **argv);
void				ft_ls_sort(t_list *lst, int(*func)(CC *, CC *));
void				ft_ls_sort_rev(t_list *lst, int(*func)(CC *, CC *));
void				ft_ls_time_sort_modificator(t_list *lst);
void				ft_ls_printer_mod_s(t_list *lst, int align_r);
void				ft_ls_type_sort(t_list *lst);
int					ft_ls_time_sort(t_list *list_i, t_list *list_j);
int					ft_ls_time_sort_up_u(t_list *list_i, t_list *list_j);
int					ft_ls_time_sort_u(t_list *list_i, t_list *list_j);
int					ft_ls_time_sort_c(t_list *list_i, t_list *list_j);
void				ft_ls_sort_mod_size(t_list *lst);
void				ft_ls_printer(t_list *lst, int align_r);
void				ft_ls_sort_n_print(t_lst_type *lst, int *dir_c);
void				ft_mem_cleaner(t_list *list);
void				ft_lst_cleaner(t_list *list);
int					ft_ls_arg(char **argv, int argc);
int					err_file_not_found(void);
void				bad_file_descriptor(char *str);
void				ft_ls_bad_arg(void);
void				ft_ls_errno_printer(t_list *lst);
void				ft_ls_file_printer(t_list *lst, int sw);
void				ft_ls_dir_printer(t_list *lst, int dir_c);
void				ft_ls_link_printer(struct stat *sb, char *path);
void				ft_column_sz(t_list *lst, int *prmt, int sw);
void				ft_ls_mod_d(int argc, int *i, char **argv);
int					ft_ls_file_type(mode_t mode);
void				ft_ls_permission(mode_t b);
void				ft_ls_display_time(t_list *lst);
void				ft_ls_dir_open(t_list *list);
#endif

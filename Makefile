#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/06 20:11:35 by lmatvien          #+#    #+#              #
#    Updated: 2018/09/24 09:19:54 by lmatvien         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			= ft_ls
NAME1 			= lib_mini.a
MAIN_NAME_LIB	= mlib.a
ODIR = obj
SDIR = src
LDIR = libft_mini

FLAGS  = -Wall -Werror -Wextra
CFILES = 	ft_dcontent.c \
			ft_dircurrent.c \
			ft_ls_main.c \
			ft_ls_arg.c \
			ft_ls_arg_dfl.c \
			ft_ls_column.c \
			ft_ls_display_time.c \
			ft_ls_printer.c \
			ft_ls_sort.c \
			ft_ls_sort_time_mod.c \
			ft_ls_printer_mod.c \
			ft_ls_tb_crtr.c \
			ft_ls_time_sort.c \
			ft_ls_usage.c \
			ft_ls_usage_p.c \
			ft_mem_control.c \

LIBFILE =   ft_atoi_base.c \
			ft_itoa.c \
			ft_strnew.c \
			ft_pow.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_putnbr_fd.c \
			ft_putstr_error.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcmp.c \
			ft_strlen.c \
			ft_strnlen.c \
	 		ft_strdup.c \
			ft_strjoin.c \
			ft_strstr.c \
			ft_memset.c \
			ft_strncat.c \
			ft_strcat.c \
			get_next_line.c \
			ft_strsplit.c \
			ft_isdigit.c \
			ft_atoi.c \
			ft_swap.c \

MAIN_HEADERS = -I ./libft_mini -I ./includes -I ./ft_printf/includes

_LIB_OBJ		= $(LIBFILE:.c=.o)
_OBJ_MAIN =	$(CFILES:.c=.o)
OBJ_MAIN =	$(addprefix ./obj/, $(_OBJ_MAIN))
LIB_OBJ =	$(addprefix ./obj/, $(_LIB_OBJ))

all: $(NAME)

$(ODIR)/%.o : $(SDIR)/%.c
	@mkdir -p $(ODIR)
	@gcc -c $(FLAGS) $(MAIN_HEADERS) $< -o $@ -O3
$(ODIR)/%.o: $(LDIR)/%.c 
	@gcc -c $(FLAGS) $< -o $@ -O3

$(NAME): $(OBJ_MAIN) $(LIB_OBJ)
	@ar rcs ./obj/$(MAIN_NAME_LIB) $(OBJ_MAIN)
	@ar rcs ./obj/$(NAME1) $(LIB_OBJ)
	@make -C ./ft_printf/
	@gcc -o $(NAME) ./obj/mlib.a ./obj/lib_mini.a ./ft_printf/libftprintf.a -I ./lib_mini -O3
clean:
	@/bin/rm -f $(LIB_OBJ) $(OBJ_MAIN)
	@make clean -C ./ft_printf/
	@echo "\033[35;1m>>>Removed OBJ Files\033[0m"
	
fclean: clean
	@/bin/rm -f ./obj/lib_mini.a ./obj/mlib.a ./ft_ls
	@make fclean -C ./ft_printf/
	@echo "\033[35;1m>>>Removed executed files\033[0m"

re: fclean all
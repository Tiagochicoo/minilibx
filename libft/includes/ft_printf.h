/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:47:48 by tpereira          #+#    #+#             */
/*   Updated: 2021/09/17 17:15:50 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include "./libft.h"

int		ft_printf(const char *format, ...);

typedef enum e_type {
	is_null,
	is_snum,
	is_unum,
	is_char,
	is_string,
	is_wchar,
	is_wstring,
	is_escape,
	num_types
}	t_type;

typedef struct s_flag {
	int	has_minusflag;
	int	has_zeroflag;
	int	has_pointflag;
	int	has_starflag;
	int	has_hashflag;
	int	has_plusflag;
	int	has_spaceflag;
	int	has_dotflag;
	int	has_lflag;
	int	has_hflag;
}	t_flag;

typedef struct s_arg {
	t_type	type;
	t_flag	*flags;
	int		fieldwidth;
	int		precision;
	char	*modifiers;
	int		specifier;
	int		is_invalid;
	int		is_negative;
	int		base;
	void	*data;
	char	*str;
	wchar_t	*wstr;
}	t_arg;

char	*read_str(char **str);
t_arg	read_arg(char *input, va_list *args);

void	free_struct(t_arg *ptr_arg_struct);
void	set_struct(char *input_block, t_arg *ptr_arg_struct, va_list *args);
void	init_struct(t_arg *arg);
t_flag	*new_flags(void);

void	set_flags(char **str_block, t_arg *ptr_arg_struct);
void	set_width(char **str_block, t_arg *ptr_arg_struct, va_list *args);
void	set_precision(char **str_block, t_arg *ptr_arg_struct);
void	set_modifiers(char **str_block, t_arg *ptr_arg_struct);
void	set_specifier(char **str_block, t_arg *ptr_arg_struct);
void	set_type(t_arg *ptr_arg_struct);
void	set_data(t_arg *ptr_arg_struct, va_list *arg_ptr);
void	set_char(t_arg *ptr_arg_struct, va_list *args);
void	set_wstring(t_arg *ptr_arg_struct, va_list *args);
void	set_wchar(t_arg *ptr_arg_struct, va_list *args);
void	set_string(t_arg *ptr_arg_struct, va_list *args);
void	set_is_negative(t_arg *ptr_arg_struct);
void	set_base(t_arg *ptr_arg_struct);
void	clean_flags(t_arg *ptr_arg_struct);

void	manage_zero_width(t_arg *ptr_arg_struct);
void	manage_hash(t_arg *ptr_arg_struct);
void	manage_sign(t_arg *ptr_arg_struct);
void	apply_widths_and_flags(t_arg *ptr_arg_struct);

# define FLAGS "-0.*#+lh"
# define DIGITS "0123456789"
# define PRECISION_SEP "."
# define MODIFIERS "hljz"
# define CONVERSIONS "cspdiuxX%nfge"

#endif
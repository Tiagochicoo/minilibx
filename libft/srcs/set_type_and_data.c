/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type_and_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:24:55 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/24 19:03:24 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_type(t_arg *arg_struct)
{
	char	s;
	char	*m;

	s = arg_struct->specifier;
	m = arg_struct->modifiers;
	if (ft_strchr("d", s) != NULL)
		arg_struct->type = is_snum;
	else if (ft_strchr("dDioOuUxXbBp", s) != NULL)
		arg_struct->type = is_unum;
	else if (s == 'C' || (m && s == 'c' && (ft_countletter(m, 'l') == 1)))
		arg_struct->type = is_wchar;
	else if (s == 'S' || (m && s == 's' && (ft_countletter(m, 'l') == 1)))
		arg_struct->type = is_wstring;
	else if (s == 'c')
		arg_struct->type = is_char;
	else if (s == 's')
		arg_struct->type = is_string;
	else if (s == '%' || (ft_strchr(CONVERSIONS, s) == NULL && ft_isalpha(s)))
		arg_struct->type = is_escape;
	else
		arg_struct->type = is_null;
}

void	set_snum(t_arg *arg_struct, va_list *args)
{
	intmax_t	snum;

	if (!arg_struct->modifiers)
		snum = va_arg(*args, int);
	else if (ft_countletter(arg_struct->modifiers, 'j') == 1
		|| ft_countletter(arg_struct->modifiers, 'z') == 1)
		snum = va_arg(*args, intmax_t);
	else if (ft_countletter(arg_struct->modifiers, 'l') == 2)
		snum = va_arg(*args, long long);
	else if (ft_countletter(arg_struct->modifiers, 'l') == 1)
		snum = va_arg(*args, long);
	else if (ft_countletter(arg_struct->modifiers, 'h') == 2)
		snum = (char)va_arg(*args, int);
	else if (ft_countletter(arg_struct->modifiers, 'h') == 1)
		snum = (short)va_arg(*args, int);
	else
		snum = va_arg(*args, intmax_t);
	arg_struct->data = &snum;
	set_is_negative(arg_struct);
	arg_struct->str = ft_itoabase_umax(snum, arg_struct->base);
}

void	set_unum(t_arg *arg_struct, va_list *args)
{
	size_t	unum;

	if (arg_struct->specifier == 'D' || arg_struct->specifier == '0'
		|| arg_struct->specifier == 'U' || arg_struct->specifier == 'p')
		unum = va_arg(*args, size_t);
	else if (!arg_struct->modifiers)
		unum = va_arg(*args, unsigned int);
	else if (ft_countletter(arg_struct->modifiers, 'z') == 1)
		unum = va_arg(*args, size_t);
	else if (ft_countletter(arg_struct->modifiers, 'l') == 1)
		unum = va_arg(*args, unsigned long);
	else if (ft_countletter(arg_struct->modifiers, 'h') == 2)
		unum = (unsigned char)va_arg(*args, int);
	else if (ft_countletter(arg_struct->modifiers, 'h') == 1)
		unum = (unsigned short)va_arg(*args, int);
	else
		unum = va_arg(*args, size_t);
	arg_struct->data = &unum;
	set_base(arg_struct);
	arg_struct->str = ft_itoabase_umax(unum, arg_struct->base);
}

void	set_escape(t_arg *arg_struct, va_list *args)
{
	char	c;

	(void)args;
	c = arg_struct->specifier;
	arg_struct->data = &c;
	if (c)
		arg_struct->str = ft_chrtostr(c);
}

void	set_data(t_arg *arg_struct, va_list *args)
{
	void	(*set_datatype[12])(t_arg *, va_list *);

	set_datatype[is_snum] = set_snum;
	set_datatype[is_unum] = set_unum;
	set_datatype[is_char] = set_char;
	set_datatype[is_string] = set_string;
	set_datatype[is_wchar] = set_wchar;
	set_datatype[is_wstring] = set_wstring;
	set_datatype[is_escape] = set_escape;
	set_datatype[arg_struct->type](arg_struct, args);
}

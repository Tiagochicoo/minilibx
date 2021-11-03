/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_num_types_and_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:52:16 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/06 15:13:16 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_string(t_arg *arg_struct, va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	arg_struct->data = str;
	if (str)
		arg_struct->str = ft_strdup(str);
}

void	set_char(t_arg *arg_struct, va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	arg_struct->data = &c;
	if (c)
		arg_struct->str = ft_chrtostr(c);
}

void	set_wstring(t_arg *arg_struct, va_list *args)
{
	void	*wstr;

	wstr = va_arg(*args, wchar_t *);
	arg_struct->data = wstr;
	if (wstr)
		arg_struct->wstr = ft_wstrdup(wstr);
}

void	set_wchar(t_arg *arg_struct, va_list *args)
{
	wchar_t	wc;

	wc = va_arg(*args, wchar_t);
	arg_struct->data = &wc;
	if (wc)
		arg_struct->wstr = ft_wchrtostr(wc);
}

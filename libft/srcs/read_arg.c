/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:55:10 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/26 15:25:34 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	read_arg(char *input, va_list *args)
{
	t_arg	arg_struct;

	init_struct(&arg_struct);
	set_struct(input, &arg_struct, args);
	apply_widths_and_flags(&arg_struct);
	return (arg_struct);
}

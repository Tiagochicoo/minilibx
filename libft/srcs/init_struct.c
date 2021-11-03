/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:18:29 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/26 15:27:45 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*new_flags(void)
{
	t_flag	*flags;

	flags = (t_flag *)malloc(sizeof(t_flag));
	if (!flags)
		return (NULL);
	flags->has_minusflag = 0;
	flags->has_zeroflag = 0;
	flags->has_pointflag = 0;
	flags->has_starflag = 0;
	flags->has_hashflag = 0;
	flags->has_plusflag = 0;
	flags->has_spaceflag = 0;
	flags->has_dotflag = 0;
	flags->has_lflag = 0;
	flags->has_hflag = 0;
	return (flags);
}

//Iniciar a struct com valores default

void	init_struct(t_arg *arg)
{
	arg->type = is_null;
	arg->flags = new_flags();
	arg->fieldwidth = -1;
	arg->precision = -1;
	arg->modifiers = NULL;
	arg->specifier = 0;
	arg->is_invalid = 0;
	arg->is_negative = 0;
	arg->base = 10;
	arg->data = NULL;
	arg->str = NULL;
	arg->wstr = NULL;
}

void	set_struct(char *input, t_arg *arg_struct, va_list *args)
{
	input++;
	set_flags(&input, arg_struct);
	set_width(&input, arg_struct, args);
	set_precision(&input, arg_struct);
	set_modifiers(&input, arg_struct);
	set_specifier(&input, arg_struct);
	set_type(arg_struct);
	set_data(arg_struct, args);
	clean_flags(arg_struct);
}

void	free_struct(t_arg *arg_struct)
{
	free(arg_struct->flags);
	arg_struct->flags = NULL;
	if (arg_struct->modifiers)
	{
		free(arg_struct->modifiers);
		arg_struct->modifiers = NULL;
	}
	if (arg_struct->str)
	{
		free(arg_struct->str);
		arg_struct->str = NULL;
	}
}

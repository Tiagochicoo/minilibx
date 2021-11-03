/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_and_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 21:12:17 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/25 16:55:01 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(char **input, t_arg *arg_struct)
{
	while (**input == '-' || **input == '0' || **input == '.'
		|| **input == '*' || **input == ' ' || **input == '#'
		|| **input == '+' || **input == 'l' || **input == 'h')
	{
		if (**input == '-')
			arg_struct->flags->has_minusflag = 1;
		else if (**input == '0')
			arg_struct->flags->has_zeroflag = 1;
		else if (**input == '.')
			arg_struct->flags->has_dotflag = 1;
		else if (**input == '*')
			arg_struct->flags->has_starflag = 1;
		else if (**input == ' ')
			arg_struct->flags->has_spaceflag = 1;
		else if (**input == '#')
			arg_struct->flags->has_hashflag = 1;
		else if (**input == '+')
			arg_struct->flags->has_plusflag = 1;
		else if (**input == 'l')
			arg_struct->flags->has_lflag = 1;
		else if (**input == 'h')
			arg_struct->flags->has_hflag = 1;
		(*input)++;
	}
}

void	set_width(char **input, t_arg *arg_struct, va_list *args)
{
	char	num_str[12];
	int		i;
	int		a;

	if (arg_struct->flags->has_starflag)
	{
		a = va_arg(*args, int);
		arg_struct->fieldwidth = a;
		if (a < 0)
			arg_struct->flags->has_minusflag = 1;
	}
	else
	{
		i = 0;
		while (ft_isdigit(**input))
		{
			num_str[i] = **input;
			(*input)++;
			i++;
		}
		num_str[i] = '\0';
		arg_struct->fieldwidth = ft_atoi(num_str);
	}
}

void 	set_precision(char **input, t_arg *arg_struct)
{
	char	num_str[12];
	int		i;

	if (**input == '.')
	{
		input++;
		if (**input >= '0' && **input <= '9')
		{
			i = 0;
			while (**input >= '0' && **input <= '9')
			{
				num_str[i] = **input;
				input++;
				i++;
			}
			num_str[i] = '\0';
			arg_struct->precision = ft_atoi(num_str);
		}
		else
			arg_struct->precision = 0;
	}
	while (**input == '.' || (**input > '0' && **input < '9'))
		input++;
}

void	clean_flags(t_arg *arg_struct)
{
	if (arg_struct->flags->has_spaceflag && arg_struct->flags->has_plusflag)
		arg_struct->flags->has_spaceflag = 0;
	if (arg_struct->flags->has_zeroflag && arg_struct->flags->has_minusflag)
		arg_struct->flags->has_zeroflag = 0;
	if (arg_struct->flags->has_zeroflag && arg_struct->precision != -1)
		arg_struct->flags->has_zeroflag = 0;
	if (arg_struct->specifier == 'p')
		arg_struct->flags->has_hashflag = 1;
}

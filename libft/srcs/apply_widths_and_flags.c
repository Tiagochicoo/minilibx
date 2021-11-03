/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_widths_and_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:22:35 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/31 11:40:59 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	manage_negwidth(t_arg *arg_struct, int len)
{
	if (arg_struct->flags->has_starflag)
	{
		len = -len - 2;
		arg_struct->fieldwidth = -arg_struct->fieldwidth;
		if (len > 0)
			ft_addnfix(&(arg_struct->str), ' ', len, 2);
		else
			ft_addnfix(&(arg_struct->str), ' ', len, 1);
	}
}

void	manage_precision(t_arg *arg_struct)
{
	int		len;
	char	*str;

	if ((arg_struct->precision != -1))
	{
		str = arg_struct->str;
		len = arg_struct->precision - ft_strlen(str);
		if (arg_struct->type == is_string && len < 0)
		{
			if (arg_struct->str == ft_strndup(str, arg_struct->precision))
				free(str);
		}
		else if ((arg_struct->type == is_unum || arg_struct->type == is_snum))
		{
			if (arg_struct->precision == 0 && str[0] == '0' && str[1] == '\0')
				arg_struct->str[0] = '\0';
			else if (len > 0)
				ft_addnfix(&(arg_struct->str), '0', len, 1);
		}
	}
}

void	manage_width(t_arg *arg_struct)
{
	int		len;

	len = 0;
	if (arg_struct->fieldwidth != -1 && arg_struct->flags->has_zeroflag == 0)
	{
		if (arg_struct->str)
			len = arg_struct->fieldwidth - ft_strlen(arg_struct->str);
		if (len > 0)
		{
			if (arg_struct->flags->has_minusflag)
				ft_addnfix(&(arg_struct->str), ' ', len, 2);
			else if (arg_struct->flags->has_starflag)
				ft_addnfix(&(arg_struct->str), ' ', len, 1);
			else
				ft_addnfix(&(arg_struct->str), ' ', len, 1);
		}
		else if (len < 0)
			manage_negwidth(arg_struct, len);
	}
}

void	manage_case(t_arg *arg_struct)
{
	int	i;

	if (arg_struct->specifier == 'X')
	{
		i = 0;
		while (arg_struct->str[i] != '\0')
		{
			arg_struct->str[i] = ft_toupper(arg_struct->str[i]);
			i++;
		}
	}
}

void	apply_widths_and_flags(t_arg *arg_struct)
{
	manage_precision(arg_struct);
	manage_zero_width(arg_struct);
	manage_sign(arg_struct);
	manage_hash(arg_struct);
	manage_case(arg_struct);
	manage_width(arg_struct);
}

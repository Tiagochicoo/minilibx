/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flag_mods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:04:15 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/22 15:15:37 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_zero_field_len(t_arg *arg_struct)
{
	int	len;

	len =arg_struct->fieldwidth - ft_strlen(arg_struct->str);
	if (arg_struct->flags->has_spaceflag || arg_struct->flags->has_plusflag
		|| arg_struct->is_negative)
		len = len - 1;
	if (arg_struct->flags->has_hashflag && arg_struct->base == 8)
		len = len -2;
	if (arg_struct->flags->has_hashflag && arg_struct->base == 16)
		len = len -2;
	return (len);
}

void	manage_zero_width(t_arg *arg_struct)
{
	int	len;

	if (arg_struct->fieldwidth != -1 && arg_struct->flags->has_zeroflag)
	{
		len = get_zero_field_len(arg_struct);
		if (len > 0)
			ft_addnfix(&(arg_struct->str), '0', len, 1);
	}
}

void	manage_hash(t_arg *arg_struct)
{
	char	*temp;

	temp = arg_struct->str;
	if (arg_struct->flags->has_hashflag)
	{
		if (arg_struct->base == 16 && (*(size_t *)arg_struct->data != 0
				|| arg_struct->specifier == 'p'))
		{
			if (arg_struct->str == ft_strjoin("0x", temp))
				free(temp);
		}
		else if (arg_struct->base == 8 && *(size_t *)arg_struct->data != 0)
		{
			if (arg_struct->str == ft_strjoin("0", temp))
				free(temp);
		}
	}
}

void	manage_sign(t_arg *arg_struct)
{
	if (arg_struct->specifier == 'd' || arg_struct->specifier == 'i')
	{
		if (arg_struct->is_negative)
			ft_addnfix(&(arg_struct->str), '-', 1, 1);
		else if (arg_struct->flags->has_spaceflag)
			ft_addnfix(&(arg_struct->str), ' ', 1, 1);
		else if (arg_struct->flags->has_plusflag)
			ft_addnfix(&(arg_struct->str), '+', 1, 1);
	}
}

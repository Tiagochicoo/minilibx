/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:14:03 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/24 14:58:04 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Get the lenght until a specified char

int	get_len_until_spec(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

/* Gets the length until one of the specifier characters, or the %.
Meant to be used to see how long a variable starting with % is. */

int	get_var_len(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (ft_strchr(CONVERSIONS, str[i]) || ft_strchr(FLAGS, str[i])
		|| ft_strchr(DIGITS, str[i]) || ft_strchr(PRECISION_SEP, str[i])
		|| ft_strchr(MODIFIERS, str[i]))
	{
		if (n == 1)
		{
			if (ft_strchr(CONVERSIONS, str[i]))
			{
				return (i+1);
			}
		}
		if (str[i] == '%')
			n++;
		i++;
	}
	return (i);
}

char	*read_str(char **str)
{
	int		len;
	char	*str_block;

	len = 0;
	if (**str == '\0')
		return (0);
	else if (**str == '%')
		len = get_var_len(*str);
	else
		len = get_len_until_spec(*str, '%');
	str_block = ft_strsub(*str, 0, len);
	*str += len;
	return (str_block);
}

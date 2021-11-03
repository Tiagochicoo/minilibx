/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:04:47 by tpereira          #+#    #+#             */
/*   Updated: 2021/09/17 17:08:25 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	char	*sub;

	if (s == 0)
		return (NULL);
	i = ft_strlen(s);
	(i > len) ? (i = len) : 1;
	sub = (char *)malloc((i + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && (i + start < ft_strlen(s)))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:26:16 by tpereira          #+#    #+#             */
/*   Updated: 2022/04/09 15:28:17 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_square(t_data*img, int x, int y, unsigned long color)
{
	while (x < 600 && y < 600)
	{
		my_mlx_pixel_put(img, x, 200, 0xFF0000);
		my_mlx_pixel_put(img, x, 600, color);
		my_mlx_pixel_put(img, 200, y, color);
		my_mlx_pixel_put(img, 600, y, color);
		x++;
		y++;
	}
}
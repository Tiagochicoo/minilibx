/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:26:16 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/30 20:17:01 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>
#include <stdio.h>

void	draw_square(t_data*vars, int x, int y, unsigned long color)
{
	while (x < 600 && y < 600)
	{
		mlx_pixel_put(vars->mlx, vars->mlx_win, x, 200, 0xFF0000);
		mlx_pixel_put(vars->mlx, vars->mlx_win, x, 600, color);
		mlx_pixel_put(vars->mlx, vars->mlx_win, 200, y, color);
		mlx_pixel_put(vars->mlx, vars->mlx_win, 600, y, color);
		x++;
		y++;
	}
}
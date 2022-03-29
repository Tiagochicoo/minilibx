/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:27:30 by tpereira          #+#    #+#             */
/*   Updated: 2022/03/29 23:03:58 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>
#include <stdio.h>

int	key_hook(int keycode, t_data *vars)
{
	t_data mlx;
	t_data img;

	if (keycode == 65307)
	{
		printf("Closing window, bye!\n");
		exit(0);
	}
	else
		printf("You pressed the %d key!\n", keycode);
}

int	click_hook(int keycode, t_data *vars)
{
	if (keycode < 10)
	{
		if (keycode > 3 && keycode < 8)
			printf("Mouse wheel spinning\n");
		else
			printf("Click!\n");
	}
	else
		printf("You pressed the %d key!\n", keycode);
}

int		exit_hook(t_data *vars)
{
	int i;

	if (vars->addr)
		free(vars->addr);
	if (vars->bits_per_pixel)
		free(vars->bits_per_pixel);
	if (vars->endian)
		free(vars->endian);
	if (vars->img)
		free(vars->img);
	if (vars->line_length)
		free(vars->line_length);
	if (vars->mlx)
		free(vars->mlx);
	if (vars->mlx_win)
		free(vars->mlx_win);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_data	mlx;
	t_data	mlx_win;
	t_data	img;
	t_data	str;
	int		x;
	int		y;

	x = 200;
	y = 200;
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 1024, 768, "Hello world!");
	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	draw_square(&img, x, y, 0x00B2FF);
	//mlx_hook(mlx.mlx_win, 2, (1L << 1), close(27, &mlx, &mlx_win), &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 1, 1);
	mlx_string_put(mlx.mlx, mlx.mlx_win, 250, 250, 0xFFABCDEF, "square 1");
	mlx_key_hook(mlx.mlx_win, key_hook, &img);
	mlx_hook(mlx.mlx_win, 04, 1L<<2,  click_hook, &img);
	mlx_hook(mlx.mlx_win, 17, 0, exit_hook, &img);
	mlx_loop(mlx.mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:27:30 by tpereira          #+#    #+#             */
/*   Updated: 2022/04/05 17:51:26 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>
#include <stdio.h>

int	key_hook(int keycode)
{
	if (keycode == 65307 || keycode == 53)
	{
		printf("Closing window, bye!\n");
		exit(0);
	}
	else
		printf("You pressed the %d key!\n", keycode);
	return (0);
}

int	click_hook(int keycode)
{
	if (keycode < 10)
	{
		if (keycode > 3 && keycode < 8)
			printf("Mouse wheel spinning\n Keycode: %d\n", keycode);
		else
			printf("Click!\n");
	}
	else
		printf("You pressed the %d key!\n", keycode);
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}

int	resize_hook(void)
{
	ft_printf("resizing!");
	return (0);
}

// void		mouse_hook(void)
// {
// 	exit(0);
// }



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_data	mlx;
	int		x;
	int		y;
	int		x1;
	int		y1;

	x = 200;
	y = 200;	
	x1 = 100;
	y1 = 100;
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 1024, 768, "Hello world!");
	mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);

	draw_square(&mlx, x, y, 0x00B2FF);
	//mlx_hook(mlx.mlx_win, 2, (1L << 1), close(27, &mlx, &mlx_win), &mlx);
	//sleep(10);

	while (x1 < 700 && y1 < 700)
	{
		mlx_pixel_put(mlx.mlx, mlx.mlx_win, x1, 300, 0xFF0000);
		mlx_pixel_put(mlx.mlx, mlx.mlx_win, x1, 700, 0xFF0000);
		mlx_pixel_put(mlx.mlx, mlx.mlx_win, 300, y1, 0xFF0000);
		mlx_pixel_put(mlx.mlx, mlx.mlx_win, 700, y1, 0xFF0000);
		x1++;
		y1++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, &mlx.img, 1, 1);
	mlx_string_put(mlx.mlx, mlx.mlx_win, 500, 250, 0xFFABCDEF, "Testing");
	mlx_key_hook(mlx.mlx_win, key_hook, mlx.img);
	mlx_hook(mlx.mlx_win, 04, 1L<<2,  click_hook, &mlx); // 04 keys+buttons | 02 only keyboard
	mlx_hook(mlx.mlx_win, 25, 0,  resize_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, exit_hook, &mlx);
	mlx_loop(mlx.mlx);
}
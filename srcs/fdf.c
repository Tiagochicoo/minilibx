/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:27:30 by tpereira          #+#    #+#             */
/*   Updated: 2022/04/09 15:56:28 by tpereira         ###   ########.fr       */
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
	return (0);
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
	return (0);
}

int		exit_hook(t_data *vars)
{
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char**argv)
{
	fdf		*data;
	int		i;
	int		j;

	ft_printf("test\n");
	i = 0;
	data = (fdf*)malloc(sizeof(fdf));
	if (argc > 1)
	{	
		read_file(argv[1], data);
		i = 0;
		while (i < data->height)
		{
			j = 0;
			while (j < data->width)
			{
				ft_printf("%3d", data->z_matrix[i][j]);
				j++;
			}
			ft_printf("\n");
			i++;
		}
	}
}

// int	main(int argc, char**argv)
// {
// 	t_data	mlx;
// 	t_data	img;
// 	t_data	str;
// 	int		x;
// 	int		y;

// 	x = 200;
// 	y = 200;

// 	mlx.mlx = mlx_init();
// 	mlx.mlx_win = mlx_new_window(mlx.mlx, 1024, 768, "FDF");
// 	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
// 	draw_square(&img, x, y, 0x00B2FF);
// 	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 1, 1);
// 	mlx_string_put(mlx.mlx, mlx.mlx_win, 250, 250, 0xFFABCDEF, "TEST");
// 	mlx_key_hook(mlx.mlx_win, key_hook, &img);
// 	mlx_hook(mlx.mlx_win, 04, 1L<<2,  click_hook, &img);
// 	mlx_hook(mlx.mlx_win, 17, 0, exit_hook, &img);
// 	mlx_loop(mlx.mlx);
// }
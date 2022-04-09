/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:21:52 by tpereira          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/04/08 17:50:23 by tpereira         ###   ########.fr       */
=======
/*   Updated: 2022/04/09 12:07:54 by tpereira         ###   ########.fr       */
>>>>>>> testing
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/includes/libft.h"
#include <mlx.h>

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct 
{
	int	width;
	int	height;
	int	**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}				fdf;

void	read_file(char *filename, fdf*data);
void	my_mlx_pixel_put(t_data*data, int x, int y, int color);
void	draw_square(t_data*img, int x, int y, unsigned long color);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:03:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/01 22:27:35 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#define LPX 600
#define PPX 600

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x = 10;
	int y = 10;
	int c1 = 255;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, LPX, PPX, "Hello world!");
	img.img = mlx_new_image(mlx, LPX, PPX);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (1)
	{
		my_mlx_pixel_put(&img, x++, y, 0x00FF0000);
		if (y == PPX - 10 && x == LPX - 10)
			break;
		if (x == LPX - 10)
		{
			x = 10;
			y++;
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook()
	mlx_loop(mlx);
	return (0);
}
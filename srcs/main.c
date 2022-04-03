/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:03:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/03 17:36:16 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#define LPX 600
#define PPX 600



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == touch_w || keycode == touch_up)
	{
		printf("foreward is pressed\n");
		forward(img);
		trace_background(img);
		trace_square(img);
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	}
	else
		printf("Hello from key_hook! : %d\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, t_data *img)
{

//	printf("Hello mouse\n");
	return(0);
}

void trace_background(t_data *img)
{
	int x = 10;
	int y = 10;
	int c1 = 255;
	
	while (1)
		{
			my_mlx_pixel_put(img, x++, y, 0x00FF0000);
			if (y == PPX - 10 && x == LPX - 10)
				break;
			if (x == LPX - 10)
			{
				x = 10;
				y++;
			}
		}
}

void trace_square(t_data *img)
{
	int x = 0;
	int y = 0;
	img->plyr.size = 30;
	img, img->plyr.posx = 300;
	img, img->plyr.posy = 300;
	while(y <= img->plyr.size)
	{
		my_mlx_pixel_put(img, img->plyr.posx + x++, img->plyr.posx + y, 0x00000000);
		if (x == img->plyr.size)
		{
			x = 0;
			y++;
		}
	}
	
}

int	forward(t_data *img)
{
	img->plyr.posy += img->plyr.size;
	return(0);
}

int	main(void)
{
	t_data	img;
	//t_vars	vars;
	// int x = 10;
	// int y = 10;
	// int c1 = 255;
	
	
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, LPX, PPX, "Hello world!");
	img.img = mlx_new_image(img.mlx, LPX, PPX);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// while (1)
	// {
	// 	my_mlx_pixel_put(&img, x++, y, 0x00FF0000);
	// 	if (y == PPX - 10 && x == LPX - 10)
	// 		break;
	// 	if (x == LPX - 10)
	// 	{
	// 		x = 10;
	// 		y++;
	// 	}
	// }
	 
	trace_background(&img);
	trace_square(&img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_key_hook(img.win, key_hook, &img); //TODO: resttruct img
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_loop(img.mlx);
	return (0);
}
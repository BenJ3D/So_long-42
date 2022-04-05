/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:03:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/05 19:06:50 by bducrocq         ###   ########.fr       */
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

int	ft_forward(t_data *img)
{
	img->plyr.posy += 50;
	return(0);
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == touch_w || keycode == touch_up)
	{
		trace_background(img, 0x000000FF);
		img->plyr.posy -= img->plyr.size;
		trace_square(img);
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	}
	if (keycode == touch_d || keycode == touch_right)
	{
		trace_background(img, 0x000000FF);
		img->plyr.posx += img->plyr.size;
		trace_square(img);
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	}
	if (keycode == touch_s || keycode == touch_down)
	{
		trace_background(img, 0x000000FF);
		img->plyr.posy += img->plyr.size;
		trace_square(img);
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	}
	if (keycode == touch_a || keycode == touch_left)
	{
		trace_background(img, 0x000000FF);
		img->plyr.posx -= img->plyr.size;
		trace_square(img);
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	}
	if (keycode == 69)
	{
		trace_background(img, 0x000000FF);
		img->plyr.size += 8;
		img->plyr.posx -= img->plyr.size / 8;
		img->plyr.posy -= img->plyr.size / 8;
		trace_square(img);
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	}
		if (keycode == 78)
	{
		trace_background(img, 0x000000FF);
		img->plyr.size -= 8;
		img->plyr.posx += img->plyr.size / 8;
		img->plyr.posy += img->plyr.size / 8;
		trace_square(img);
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	}
	else
		printf("Hello from key_hook! : %d\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, t_data *img)
{

	return(0);
}

int trace_background(t_data *img, int color)
{
	int x = 10;
	int y = 10;
	int c1 = 255;
	//unsigned int color = 0x000000FF;
	while (1)
	{
		my_mlx_pixel_put(img, x++, y, color);
		if (y == PPX - 10 && x == LPX - 10)
			break;
		if (x == LPX - 10)
		{
			x = 10;
			y++;
		}
	}
	return (0);
}

int trace_background2(t_data *game)
{
	int x = 10;
	int y = 10;
	int c1 = 255;

	void *grass;
	//unsigned int color = 0x000000FF;
	grass = mlx_png_file_to_image(game->mlx, "./map/grass.png", &game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, grass, 40, 40);
	return (0);
}

int trace_square(t_data *game)
{
	int x = 0;
	int y = 0;
	//game->plyr.size = 30;
	// game->plyr.posx = 300;
	// game->plyr.posy = 300;
	while(y <= game->plyr.size)
	{
		my_mlx_pixel_put(game, game->plyr.posx + x++, game->plyr.posy + y, 0x00FF0000);
		if (x == game->plyr.size)
		{
			x = 0;
			y++;
		}
	}
	return (0);
}



int	main(void)
{
	t_data	game;
		
	game.plyr.size = 32;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, LPX, PPX, "so_long");
	game.img = mlx_new_image(game.mlx, LPX, PPX);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length,
								&game.endian);
	//trace_background(&game, 0x000000FF);
	trace_background2(&game);
	game.plyr.posx = LPX / 2;
	game.plyr.posy = PPX / 2;
	trace_square(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_mouse_hook(game.win, mouse_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
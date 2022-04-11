/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:03:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/11 15:00:27 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"
#define LPX 1024	
#define PPX 1024


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

int	key_hook(int keycode, t_data *game)
{
	if (keycode == touch_w || keycode == touch_up)
	{
		trace_background(game);
		game->plyr.posy -= game->plyr.size;
		trace_player(game);
		// mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	}
	if (keycode == touch_d || keycode == touch_right)
	{
		trace_background(game);
		game->plyr.posx += game->plyr.size;
		trace_player(game);
		// mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	}
	if (keycode == touch_s || keycode == touch_down)
	{
		trace_background(game);
		game->plyr.posy += game->plyr.size;
		trace_player(game);
		// mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	}
	if (keycode == touch_a || keycode == touch_left)
	{
		trace_background(game);
		game->plyr.posx -= game->plyr.size;
		trace_player(game);
		// mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	}
	if (keycode == touch_esc)
		exit(0);
	// if (keycode == 69)
	// {
	// 	trace_background(game);
	// 	game->plyr.size += 8;
	// 	game->plyr.posx -= game->plyr.size / 8;
	// 	game->plyr.posy -= game->plyr.size / 8;
	// 	trace_player(game);
	// 	// mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	// }
	// 	if (keycode == 78)
	// {
	// 	trace_background(game);
	// 	game->plyr.size -= 8;
	// 	game->plyr.posx += game->plyr.size / 8;
	// 	game->plyr.posy += game->plyr.size / 8;
	// 	trace_player(game);
	// 	// mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	// }
	else
		printf("Hello from key_hook! : %d\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, t_data *img)
{

	return(0);
}

int trace_backgroundold(t_data *img, int color)
{
	int x = 10;
	int y = 10;
	int c1 = 255;
	//unsigned int color ;
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

int trace_background(t_data *game)
{
	int x = 0;
	int y = 0;
	int maxtile;

	maxtile = SIZE_PNG * 16;
	game->grass.img = mlx_png_file_to_image(game->mlx, "./map/grass.png", &game->grass.w, &game->grass.h);
	//mlx_put_image_to_window(game->mlx, game->win, game->grass.img, x, y);

	

	
	while (1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass.img, x, y);
		x += SIZE_PNG - 1;
		if (x >= maxtile && y >= maxtile)
			break ;
		if (x >= maxtile)
		{
			x = 0;
			y += SIZE_PNG - 1;
		}
	trace_apple(game);
	trace_door(game);

	}
	
	
	//mlx_put_image_to_window(game->mlx, game->win, game->grass.img, 128, 128);
	return (0);
}

int trace_square(t_data *game)
{
	int x = 0;
	int y = 0;
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

int trace_player(t_data *game)
{
	if(!game->player.img)
		game->player.img = mlx_png_file_to_image(game->mlx, "./map/player.png", &game->player.w, &game->player.h);
	mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->plyr.posx, game->plyr.posy);
	return (0);
}

int trace_apple(t_data *game)
{
	if(!game->collect.img)
		game->collect.img = mlx_png_file_to_image(game->mlx, "./map/collectable.png", &game->collect.w, &game->collect.h);
	mlx_put_image_to_window(game->mlx, game->win, game->collect.img, 320, 320);
	mlx_put_image_to_window(game->mlx, game->win, game->collect.img, 832, 512);
	mlx_put_image_to_window(game->mlx, game->win, game->collect.img, 604, 256);
	return (0);
}

int trace_door(t_data *game)
{
	if(!game->door.img)
		game->door.img = mlx_png_file_to_image(game->mlx, "./map/door.png", &game->door.w, &game->door.h);
	mlx_put_image_to_window(game->mlx, game->win, game->door.img, 900, 900);
	return (0);
}

int	main(void)
{
	t_data	game;
		
	game.plyr.size = SIZE_PNG;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, LPX, PPX, "so_long");
	game.img = mlx_new_image(game.mlx, LPX, PPX);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length,
								&game.endian);
	//trace_background(&game);
	game.plyr.posx = LPX / 2;
	game.plyr.posy = PPX / 2;
	trace_background(&game);
	trace_player(&game);
	//trace_door(&game);

	//trace_square(&game);
	//mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
	//mlx_put_image_to_window(game.mlx, game.win, game.grass.img, 0, 0);
	//mlx_hook(game.win, key_hook, &game);
	 mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, key_hook, &game);
	mlx_mouse_hook(game.win, mouse_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_img_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:48:31 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/12 18:38:42 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//int	trace_player_to_win(t_data *game, int posx, int posy, int hpng, int i);
int	trace_player_to_win(t_data *game);

int	push_one_tile(t_data *game, int target)
{
	int		posx;
	int		posy;
	int		index;
	int		sizepng;
	
	sizepng = game->sizetile;
	posx = 0;
	posy = 0;
	index = 0;
	while (game->map.tile[index])
	{
		if (posx == game->map.lenx)
		{
			posx = 0;
			posy++;
			game->map.leny++; // dependance ? ou a virer
		}
		if (game->map.tile[index] != GROUND) //FIXME:
			mlx_put_image_to_window(game->mlx, game->windows, 
				game->wall.img, sizepng * posx, sizepng * posy);
		if (game->map.tile[index] != WALL)
			mlx_put_image_to_window(game->mlx, game->windows, 
				game->ground.img, sizepng * posx, sizepng * posy);
		if (game->map.tile[index] == ITEM)
			mlx_put_image_to_window(game->mlx, game->windows, 
				game->item.img, sizepng * posx, sizepng * posy);
		if (game->map.tile[index] == DOOR)
			mlx_put_image_to_window(game->mlx, game->windows, 
				game->door.img, sizepng * posx, sizepng * posy);
		// else if (game->map.tile[index] == PLAYER)
		// 	trace_player_to_win(game, posx, posy, sizepng, index);
		if (game->map.tile[index] == PLAYER)
		{
			// mlx_put_image_to_window(game->mlx, game->windows, 
			// 	game->player.png.img, sizepng * posx, sizepng * posy);
				game->map.tile[index] = GROUND;
				game->player.posi = index;
				game->player.posx = posx;
				game->player.posy = posy;
		}
		posx++;
		index++;
	}
	return (0);
}


int	push_tile_to_win(t_data *game)
{
	int		posx;
	int		posy;
	int		index;
	int		sizepng;
	
	sizepng = game->sizetile;
	posx = 0;
	posy = 0;
	index = 0;
	while (game->map.tile[index])
	{
		if (posx == game->map.lenx)
		{
			posx = 0;
			posy++;
			game->map.leny++; // dependance ? ou a virer
		}
		if (game->map.tile[index] != GROUND) //FIXME:
			mlx_put_image_to_window(game->mlx, game->windows, 
				game->wall.img, sizepng * posx, sizepng * posy);
		if (game->map.tile[index] != WALL)
			mlx_put_image_to_window(game->mlx, game->windows, 
				game->ground.img, sizepng * posx, sizepng * posy);
		if (game->map.tile[index] == ITEM)
			mlx_put_image_to_window(game->mlx, game->windows, 
				game->item.img, sizepng * posx, sizepng * posy);
		if (game->map.tile[index] == DOOR)
			mlx_put_image_to_window(game->mlx, game->windows, 
				game->door.img, sizepng * posx, sizepng * posy);
		// else if (game->map.tile[index] == PLAYER)
		// 	trace_player_to_win(game, posx, posy, sizepng, index);
		if (game->map.tile[index] == PLAYER)
		{
			// mlx_put_image_to_window(game->mlx, game->windows, 
			// 	game->player.png.img, sizepng * posx, sizepng * posy);
				game->map.tile[index] = GROUND;
				game->player.posi = index;
				game->player.posx = posx;
				game->player.posy = posy;
		}
		posx++;
		index++;
	}
	return (0);
}

int	trace_player_to_win(t_data *game)
{
	int		sizepng;
	
	sizepng = game->sizetile;
	mlx_put_image_to_window(game->mlx, game->windows,
		game->player.png.img, sizepng * game->player.posx, 
		sizepng * game->player.posy);

	return (0);
}

// int	trace_player_to_win(t_data *game, int posx, int posy, int hpng, int i)
// {

// 	mlx_put_image_to_window(game->mlx, game->windows, 
// 				game->player.png.img, hpng * posx, hpng * posy);
// 	game->player.posi = i;
// 	game->player.posx = posx;
// 	game->player.posy = posy;
// 	return (0);
// }

int	update_windows(t_data *game)
{
	//push_tile_to_win(game);
	trace_player_to_win(game);
	return (0);
}

int	push_windows(t_data *game)
{
	push_tile_to_win(game);
	trace_player_to_win(game);
	return (0);
}
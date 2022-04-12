/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_img_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:48:31 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/12 15:30:27 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	trace_player_to_win(t_data *game, int posx, int posy, int hpng, int i);

int	push_tile_to_win(t_data *game)
{
	int		posx;
	int		posy;
	int		index;
	int		sizepng;
	
	sizepng = game->wall.h - 1; // PATH LINE MLX BUG
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
		if (game->map.tile[index] != GROUND)
		{
			mlx_put_image_to_window(game->mlx, game->windows, 
				game->wall.img, sizepng * posx, sizepng * posy);
		}
		if (game->map.tile[index] != WALL)
		{
			mlx_put_image_to_window(game->mlx, game->windows, 
				game->ground.img, sizepng * posx, sizepng * posy);
		}
		if (game->map.tile[index] == ITEM)
		{
			mlx_put_image_to_window(game->mlx, game->windows, 
				game->item.img, sizepng * posx, sizepng * posy);
		}
		else if (game->map.tile[index] == DOOR)
		{
			mlx_put_image_to_window(game->mlx, game->windows, 
				game->door.img, sizepng * posx, sizepng * posy);
			//game->b_door = 0;
		}
		else if (game->map.tile[index] == PLAYER)
			trace_player_to_win(game, posx, posy, sizepng, index);
		posx++;
		index++;
	}
	return (0);
}

// int	trace_player_to_win2(t_data *game, int posx, int posy, int hpng, int i)
// {
// 	int		posx;
// 	int		posy;
// 	int		index;
// 	int		sizepng;
	
// 	sizepng = game->wall.h - 1; // PATH LINE MLX BUG
// 	posx = 0;
// 	posy = 0;
// 	index = 0;
// 	while (game->map.tile[index])
// 	{
// 		if (posx == game->map.lenx)
// 			{
// 				posx = 0;
// 				posy++;
// 				game->map.leny++; // dependance ? ou a virer
// 			}
// 		if (game->map.tile[index] == PLAYER)
// 			trace_player_to_win(game, posx, posy, sizepng, index);
// 		posx++;
// 		index++;
// 	}
// 	return (0);
// }

int	trace_player_to_win(t_data *game, int posx, int posy, int hpng, int i)
{

	mlx_put_image_to_window(game->mlx, game->windows, 
				game->player.png.img, hpng * posx, hpng * posy);
	game->player.posi = i;
	game->player.posx = posx;
	game->player.posy = posy;
	return (0);
}

int	push_windows(t_data *game)
{
	push_tile_to_win(game);
	return (0);
}
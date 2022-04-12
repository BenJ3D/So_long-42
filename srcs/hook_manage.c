/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:02:40 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/12 18:31:00 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	update_move_player(t_data *game)
{
	int	posx;
	int	posy;
	int	i;
	int sizepng;

	sizepng = game->sizetile;
	posx = 0;
	posy = 0;
	i = 1;
	while (i <= game->player.target)
	{
		if (posx == game->map.lenx)
		{
			posx = 0;
			posy++;
		}
		posx++;
		i++;
	}
	if (game->map.tile[game->player.posi] != GROUND) //FIXME:
			mlx_put_image_to_window(game->mlx, game->windows, 
				game->wall.img, sizepng * posx, sizepng * posy);
	if (game->map.tile[game->player.target] != WALL)
		mlx_put_image_to_window(game->mlx, game->windows,
							game->ground.img, sizepng * posx, sizepng * posy);
	if (game->map.tile[game->player.target] == ITEM)
		mlx_put_image_to_window(game->mlx, game->windows,
							game->item.img, sizepng * posx, sizepng * posy);
	if (game->map.tile[game->player.target] == DOOR)
		mlx_put_image_to_window(game->mlx, game->windows,
							game->door.img, sizepng * posx, sizepng * posy);
	mlx_put_image_to_window(game->mlx, game->windows, game->player.png.img, 
		game->sizetile * game->player.posx, game->sizetile * game->player.posy);
	game->player.posx = posx;
	game->player.posy = posy;
	return (0);
}

int	collision_management(t_data *game)
{
	int	nb_item;
	
	nb_item = ft_str_search_char(game->map.tile, ITEM);
	printf("\ntarget : %d\n", game->player.target);
	if (game->map.tile[game->player.target] != WALL)
	{
		update_move_player(game);

		// if (game->map.tile[game->player.target] == DOOR)
		// 	game->b_door = 1;
		//game->map.tile[game->player.posi] = GROUND;
		// game->map.tile[game->player.target] = PLAYER;
		//push_tile_to_win(game);
		//update_move_player(game);
		//trace_player_to_win(game);
	}
	// else if (game->map.tile[game->player.target] == DOOR)
	// {
	// 	if (nb_item <= 0)
	// 		exit(0);
	// 	else
	// 	{
	// 		game->map.tile[game->player.posi] = DOOR;
	// 		game->map.tile[game->player.rev_target] = PLAYER;
	// 		//push_tile_to_win(game);
	// 		push_tile_to_win(game);
	// 		trace_player_to_win(game);
	// 	}

	// }
	return (0);
}

int	key_hook(int kc, t_data *game)
{
	game->player.rev_target = -game->player.target;
	if (kc == touch_w || kc == touch_up)
		game->player.target = game->player.posi - game->map.lenx;
	else if (kc == touch_s || kc == touch_down)
		game->player.target = game->player.posi + game->map.lenx;
	else if (kc == touch_d || kc == touch_right)
		game->player.target = game->player.posi + 1;
	else if (kc == touch_a || kc == touch_left)
		game->player.target = game->player.posi - 1;
	else if (kc == touch_esc)
		exit(0);
	else
		return (0);
	collision_management(game);
		return (0);
	return (0);
}
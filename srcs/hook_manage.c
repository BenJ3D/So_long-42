/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:02:40 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/12 15:31:33 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	collision_management(t_data *game, int target, int back_target)
{
	int	nb_item;
	
	nb_item = ft_str_search_char(game->map.tile, ITEM);
	if (game->map.tile[target] != WALL)
	{
		// if (game->map.tile[target] == DOOR)
		// 	game->b_door = 1;
		game->map.tile[game->player.posi] = GROUND;
		game->map.tile[target] = PLAYER;
		push_tile_to_win(game);
	}
	else if (game->map.tile[target] == DOOR)
	{
		if (nb_item <= 0)
			exit(0);
		else
		{
			game->map.tile[game->player.posi] = DOOR;
			game->map.tile[back_target] = PLAYER;
			push_tile_to_win(game);
		}

	}
	return (0);
}

int	key_hook(int kc, t_data *game)
{
	int	target;
	int	back_target;

	back_target = -target;
	if (kc == touch_w || kc == touch_up)
		target = game->player.posi - game->map.lenx;
	else if (kc == touch_s || kc == touch_down)
		target = game->player.posi + game->map.lenx;
	else if (kc == touch_d || kc == touch_right)
		target = game->player.posi + 1;
	else if (kc == touch_a || kc == touch_left)
		target = game->player.posi - 1;
	else if (kc == touch_esc)
		exit(0);
	else
		return (0);
	//game->player.target = target;
	collision_management(game, target, back_target);
		return (0);
	return (0);
}
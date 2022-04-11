/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:02:40 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/11 16:39:28 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	collision_management(t_data *game, int target, int back_target)
{
	int	nb_item;
	
	nb_item = ft_str_search_char(game->map.tile, ITEM);
	if (game->map.tile[target] != WALL && game->map.tile[target] != DOOR)
	{
		game->map.tile[game->player.posi] = GROUND;
		game->map.tile[target] = PLAYER;
		push_tile_to_win(game);
	}
	else if (game->map.tile[target] == DOOR)
	{
		if (nb_item <= 0)
			exit(0);
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
	collision_management(game, target, back_target);
		return (0);

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
	return (0);
}
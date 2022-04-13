/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:02:40 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/13 16:53:16 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move_counter(t_data *game)
{
	game->player.countmove++;
	ft_putnbr(game->player.countmove);
	ft_putchar('\n');
}

int	collision_management(t_data *game, int target, int back_target)
{
	int	nb_item;
	
	nb_item = ft_str_search_char(game->map.tile, ITEM);
	if (game->map.tile[target] != WALL && game->map.tile[target] != DOOR)
	{
		game->map.tile[game->player.posi] = GROUND;
		game->map.tile[target] = PLAYER;
		push_tile_to_win(game);
		player_move_counter(game);
	}
	else if (game->map.tile[target] == DOOR)
	{
		if (nb_item <= 0)
		{
			player_move_counter(game);
			exit_normal(game);
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
		exit_normal(game);
	collision_management(game, target, back_target);
	return (0);
}
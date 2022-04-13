/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:01:39 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/13 15:30:59 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	game;
	
	if (check_norm_arg_is_ok(ac, av[1], &game) == 0)
		return (write_error_type(&game));
	game.mlx = mlx_init();
	define_all_png_to_image(&game);
	game.error = NO_ERROR;	//////// START PARSING /////////
	game.player.countmove = 0;
	parsing_map(&game, av[1]);
	game.map.leny = (ft_strlen(game.map.tile) / game.map.lenx);
	game.img_width = game.sizetile * game.map.lenx;
	game.img_height = game.sizetile * game.map.leny;
	game.windows = mlx_new_window(game.mlx, game.img_width,
			game.img_height, "so_long");	//** setup mlx **///
	game.img = mlx_new_image(game.mlx, game.img_width, game.img_height);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel,
			&game.line_length, &game.endian);//** fin setup mlx **///
	push_tile_to_win(&game);
	///// HOOK
	mlx_hook(game.windows, X_EVENT_KEY_PRESS, 0, key_hook, &game);
	mlx_mouse_hook(game.windows, mouse_hook, &game);
	mlx_loop (game.mlx);
	free(game.map.tile);
	return (0);
}

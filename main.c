/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:01:39 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/11 00:44:20 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: OU PAS, CHOIX ?? ressoudre gestion filename error // au moins un char avant le .
#include "./includes/so_long.h"
#define LPX 512	
#define HPX 512

int	main(int ac, char **av)
{
	t_data	game;
	int fd;
	
	if (check_norm_arg_is_ok(ac, av[1], &game) == 0)
		return (write_error_type(&game));
	//parsing_map(&game);
	// game.img_width = LPX;
	// game.img_height = HPX;
	game.mlx = mlx_init();
	
	define_all_png_to_image(&game);

	//////// START PARSING /////////
	game.error = NO_ERROR;
	parsing_map(&game, av[1]);
	game.map.leny = (ft_strlen(game.map.tile) / game.map.lenx);
	game.img_width = game.wall.w * game.map.lenx;
	game.img_height = game.wall.h * game.map.leny;
	printf("debig leny %d\n", (int)ft_strlen(game.map.tile));
	////////////
	
	//** setup mlx **///
	game.windows = mlx_new_window(game.mlx, game.img_width,
			game.img_height, "so_long");
	game.img = mlx_new_image(game.mlx, game.img_width, game.img_height);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel,
			&game.line_length, &game.endian);
	//		fin setup mlx **//
	
	push_tile_to_win(&game);
	// mlx_put_image_to_window(game.mlx, game.windows, game.ground.img, 64, 64);
	// mlx_put_image_to_window(game.mlx, game.windows, game.door.img,
	// 	game.wall.w, game.wall.h);
	
	
	 mlx_loop (game.mlx);
	free(game.map.tile);
	return (0);
}

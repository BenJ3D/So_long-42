/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:01:39 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/06 17:47:11 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: ressoudre gestion filename error // au moins un char avant le .
#include "./includes/so_long.h"
#define LPX 512	
#define HPX 512

int	main(int ac, char **av)
{
	t_data	game;
	
	if (check_norm_arg_is_ok(ac, av[1], &game) == 0)
	{
		write_error_type(&game);
		return (0);
	}
	//parsing_map(&game);
	game.img_width = LPX;
	game.img_height = HPX;
	
	//** initiation mlx
	game.mlx = mlx_init();
	game.windows = mlx_new_window(game.mlx, game.img_width,
			game.img_height, "so_long");
	game.img = mlx_new_image(game.mlx, game.img_width, game.img_height);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel,
			&game.line_length, &game.endian);
	//		fin initiation mlx **//
	
	define_all_png_to_image(&game);
	mlx_put_image_to_window(game.mlx, game.windows, game.ground.img, 64, 64);
	mlx_put_image_to_window(game.mlx, game.windows, game.door.img,
		game.wall.w, game.wall.h);
	mlx_loop (game.mlx);
	return (0);
}

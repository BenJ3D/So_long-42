/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:01:39 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/06 13:51:14 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#define LPX 512	
#define HPX 512

int	main(int ac, char **av)
{
	t_data	game;

	hello();
	game.img_width = LPX;
	game.img_height = HPX;
	game.mlx = mlx_init();
	game.windows = mlx_new_window(game.mlx, game.img_width,
			game.img_height, "so_long");
	game.img = mlx_new_image(game.mlx, game.img_width, game.img_height);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel,
			&game.line_length, &game.endian);
	mlx_loop (game.mlx);
	return (0);
}

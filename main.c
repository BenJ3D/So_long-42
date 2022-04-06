/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:01:39 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/06 17:30:21 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: ressoudre gestion filename error
#include "./includes/so_long.h"
#define LPX 512	
#define HPX 512

void	write_error_type(t_data *game)
{
	if (game->error == ERROR_ARG_NBR)
		ft_putstr("Please enter one path argument\n");
	else if (game->error == ERROR_FILE_TYPE)
		ft_putstr("file is not .ber extension\n");
}

//FIXME: check if ==>> gerer les espaces en fin de path
/**
 * @brief return 0 if path extension is == typefile
 * 
 * @param str 
 * @param filetype enter ".type"
 * @return int 
 */
int	check_type_file(char *str, char *filetype)
{
	int	i;
	int	y;
	
	i = ft_strlen(str) - 1;
	y = ft_strlen(filetype) - 1;
	while (ft_isspace(str[i]) != 0)
		i--;
	while (filetype >= 0)
	{
		if (filetype[y] != str[i])
			return (1);
		i--;
		y--;
	}
	return (0);
}

int	check_norm_arg_is_ok(int ac, char *str, t_data *game)
{
	int	len;
	
	if (ac != 2 || str[0] == '\0')
	{
		ft_putstr("arg error\n");
		game->error = ERROR_ARG_NBR;
		//return (1);
	}
	else if (check_type_file(str, ".ber"))
	{
		ft_putstr("file error\n");
		game->error = ERROR_FILE_TYPE;
		//return (1);
	}
	else if (game->error != NO_ERROR)
	{
		return (1);		
	}
		ft_putstr("no error\n");
	return(0);
}

int	main(int ac, char **av)
{
	t_data	game;
	
	printf("check result norm arg function : %d", check_norm_arg_is_ok(ac, av[1], &game));
	if (check_norm_arg_is_ok(ac, av[1], &game) == 1)
	{
		ft_putstr("norm arg not ok\n");
		write_error_type(&game);
		return (0);
	}
	parsing_map(&game);
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

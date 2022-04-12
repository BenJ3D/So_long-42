/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_png.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:49:23 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/12 17:56:41 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
//gerer les open
static void	filename_path(t_data *game)
{
	ft_strlcpy(game->ground.path, "./srcs/png/ground.png", 22);
	ft_strlcpy(game->wall.path, "./srcs/png/wall.png", 20);
	ft_strlcpy(game->item.path, "./srcs/png/item.png", 20);
	ft_strlcpy(game->door.path, "./srcs/png/door.png", 20);
	ft_strlcpy(game->player.png.path, "./srcs/png/player.png", 22);
}

static void	filename_path_xpm(t_data *game)
{
	ft_strlcpy(game->ground.path, "./srcs/xpm/ground.xpm", 22);
	ft_strlcpy(game->wall.path, "./srcs/xpm/wall.xpm", 20);
	ft_strlcpy(game->item.path, "./srcs/xpm/item.xpm", 20);
	ft_strlcpy(game->door.path, "./srcs/xpm/door.xpm", 20);
	ft_strlcpy(game->player.png.path, "./srcs/xpm/player.xpm", 22);
}

/**
 * @brief save all png file for project in mlx img
 * 
 * @param game 
 */
void	define_all_png_to_image(t_data *game)
{
	filename_path(game);
	game->ground.img = mlx_png_file_to_image(game->mlx, game->ground.path,
			&game->ground.w, &game->ground.h);
	game->wall.img = mlx_png_file_to_image(game->mlx, game->wall.path,
			&game->wall.w, &game->wall.h);
	game->item.img = mlx_png_file_to_image(game->mlx, game->item.path,
			&game->item.w, &game->item.h);
	game->door.img = mlx_png_file_to_image(game->mlx, game->door.path,
			&game->door.w, &game->door.h);
	game->player.png.img = mlx_png_file_to_image(game->mlx,
			game->player.png.path, &game->player.png.w, &game->player.png.h);
	patch_mlx(game);
}

/**
 * @brief save all png file for project in mlx img
 * 
 * @param game 
 */
void	define_all_xpm_to_image(t_data *game)
{
	filename_path(game);
	game->ground.img = mlx_xpm_file_to_image(game->mlx, game->ground.path,
			&game->ground.w, &game->ground.h);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, game->wall.path,
			&game->wall.w, &game->wall.h);
	game->item.img = mlx_xpm_file_to_image(game->mlx, game->item.path,
			&game->item.w, &game->item.h);
	game->door.img = mlx_xpm_file_to_image(game->mlx, game->door.path,
			&game->door.w, &game->door.h);
	game->player.png.img = mlx_xpm_file_to_image(game->mlx,
			game->player.png.path, &game->player.png.w, &game->player.png.h);
	patch_mlx(game);
}


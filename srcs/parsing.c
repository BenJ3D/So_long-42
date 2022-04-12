/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:48:31 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/12 16:08:05 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	put_good_img_debug(t_data *game, char *line)  //put text debug
{
	int	i;

	i = 0;
	while (*line)
	{
		if (i == game->map.lenx)
			{
				printf(" |||||\n");
				i = 0;
				game->map.leny++;
			}
		if (*line == WALL)
		{
			printf("  wall  ");
		}
		else if (*line == GROUND)
		{
			printf(" ground ");
		}
		else if (*line == ITEM)
		{
			printf("  ITEM  ");
		}
		else if (*line == DOOR)
		{
			printf("  EXIT  ");
		}
		else if (*line == PLAYER)
		{
			printf(" PLAYER ");
		}
		i++;
		line++;
	}
	return (0);
}

// int	push_tile_to_win(t_data *game)
// {
// 	int	posx;
// 	int	posy;
// 	int	index;
// 	int		sizepng;
// 	sizepng = 63;
// 	posx = 0;
// 	posy = 0;
// 	index = 0;
// 	while (game->map.tile[index])
// 	{
// 		if (posx == game->map.lenx)
// 			{
// 				posx = 0;
// 				posy++;
// 				game->map.leny++; // dependance ? ou a virer
// 			}
// 		printf("%d %d %d %d\n", posx, posy,(sizepng * posx)%64, (sizepng * posy)%64);
// 		if (game->map.tile[index] != GROUND)
// 		{
// 			mlx_put_image_to_window(game->mlx, game->windows, 
// 				game->wall.img, sizepng * posx, sizepng * posy);
// 		}
// 		if (game->map.tile[index] != WALL)
// 		{
// 			mlx_put_image_to_window(game->mlx, game->windows, 
// 				game->ground.img, sizepng * posx, sizepng * posy);
// 		}
// 		if (game->map.tile[index] == ITEM)
// 		{
// 			mlx_put_image_to_window(game->mlx, game->windows, 
// 				game->item.img, sizepng * posx, sizepng * posy);
// 		}
// 		else if (game->map.tile[index] == DOOR)
// 		{
// 			mlx_put_image_to_window(game->mlx, game->windows, 
// 				game->door.img, sizepng * posx, sizepng * posy);
// 		}
// 		else if (game->map.tile[index] == PLAYER)
// 		{
// 			mlx_put_image_to_window(game->mlx, game->windows, 
// 				game->player.png.img, sizepng * posx, sizepng * posy);
// 		}
// 		posx++;
// 		index++;
// 	}
// 	return (0);
// }

/**
 * @brief fill *tile str with all char map, whitout space or new line
 * 
 * @param game 
 * @param fd
 * @return int 
 */
int	fill_data_map(t_data *game, int fd)
{
	static int		lentmp = 0;
	char			*tmp;
	
	game->line = get_next_line(fd);
	if (!game->line)
		return (0);
	game->map.lenx = ft_strlen(game->line);
	if(game->line[game->map.lenx - 1] == '\n')
	{
		game->line[game->map.lenx - 1] = '\0';
		game->map.lenx--;
	}
	if (lentmp != game->map.lenx && game->map.bool == 1)
	{
		game->error = ERROR_MAP_NO_RECT;
		write_error_type(game);
	}
	lentmp = game->map.lenx;
	tmp = ft_strdup(game->map.tile);
	free(game->map.tile);
	game->map.tile = ft_strjoin(tmp, game->line);
	free(tmp);
	free(game->line);
	game->map.bool = 1;
	return (0);
}

/**
 * @brief check if all required elements are present
 * 
 * @param game 
 * @return int 
 */
int check_minimum_required(t_data *game)
{
	int	c;
	int	e;
	int	p;
	int i;

	c = ft_str_search_char(game->map.tile, ITEM);
	e = ft_str_search_char(game->map.tile, DOOR);
	p = ft_str_search_char(game->map.tile, PLAYER);
	if (c <= 0)
		game->error = ERROR_MAP_NO_ITEM;
	else if (p <= 0)
		game->error = ERROR_MAP_NO_PLAYER;
	else if (e <= 0)
		game->error = ERROR_MAP_NO_EXIT;
	if (game->error != NO_ERROR)
		write_error_type(game);
	return (0);
}

int	check_wall_close_map(t_data *game)
{
	int	posx;
	int	posy;
	int	i;
	posx = 1;
	posy = 1;
	i = 0;
	game->map.leny = (int)ft_strlen(game->map.tile) / game->map.lenx;
	while(game->map.tile[i])
	{
		if (((posy == 1) || (posx == 1) || (posy == game->map.leny) || 
					(posx == game->map.lenx)) && game->map.tile[i] != WALL)
		{
			game->error = ERROR_MAP_WALL;
			write_error_type(game);
		}
		if (posx == game->map.lenx)
		{
			posx = 1;
			posy++;
		}
		else
			posx++;
		i++;
	}
	return (0);
}

int	check_chars_is_valid(t_data *game)
{
	int	i;
	
	i = 0;
	game->error = NO_ERROR;
	while(game->map.tile[i])
	{
		if (WALL == game->map.tile[i])
			i++;
		else if (GROUND == game->map.tile[i])
			i++;
		else if (PLAYER == game->map.tile[i])
			i++;
		else if (ITEM == game->map.tile[i])
			i++;
		else if (DOOR == game->map.tile[i])
			i++;
		else
		{
			game->error = ERROR_MAP_CHAR_NO_VALID;
			break ;
		}
	}
	if (game->error != NO_ERROR)
		write_error_type(game);
	return (0);
}

/**
 * @brief copy toute la map dans game.map.tile
 * et gère la detection des erreurs de file ou mapping 
 *  ATTENTION free game.map.tile a faire
 * @param game 
 * @param pathfile 
 * @return int 
 */
int	parsing_map(t_data	*game, char *pathfile)
{
	int		fd;
	char	line;
	
	game->map.bool = 0;
	fd = ft_open_file(pathfile, game);
	game->map.tile = ft_strdup("");
	game->map.leny = 1;
	while (1)
	{
		if(fill_data_map(game, fd))
			write_error_type(game);
		if (!game->line)
			break;
	}
	if (check_chars_is_valid(game))
		write_error_type(game);
	if (check_minimum_required(game))
		write_error_type(game);
	if (check_wall_close_map(game))
		write_error_type(game);
	if (put_good_img_debug(game, game->map.tile))
		write_error_type(game);
//	game->map. ft_strdup(game);
	return (0);
}

// int main(int ac, char **av)
// {
// 	char path[] = "maps/02.ber";
// 	int	fd;
// 	t_data	game;
// 	if (ac != 2)
// 		fd = parsing_map(&game, path);
// 	else
// 		fd = parsing_map(&game, av[1]);
// 	//printf("map tile %c\n\n", game.map.tile[0]);
// 	free(game.map.tile);
// 	return (0);
// }
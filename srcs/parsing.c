/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:48:31 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/10 16:33:38 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	put_good_img_debug(t_data *game, char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (i == game->map.lenx)
			{
				printf(" |||||\n");
				i = 0;
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

int		make_map(t_data *game, char *line) // obselete
{
	int	i;
	int	x;

	i = 0;
	while (*line)
	{
		if (*line == WALL)
			game->map.tile[x] = WALL;
		else if (*line == GROUND)
			game->map.tile[x] = GROUND;
		else if (*line == ITEM)
			game->map.tile[x] = ITEM;
		else if (*line == DOOR)
			game->map.tile[x] = DOOR;
		else if (*line == PLAYER)
			game->map.tile[x] = PLAYER;
		else if (*line == '\0')
			return (0);
		else
		{
			game->error = ERROR_CHAR_NO_VALID;
			return (1); 
		}
		line++;
		x++;
	}
	return (0);
}

int		make_mapOLD(t_data *game, char *line)
{
	int	x;

	x = 0;
	if (!line)
		return (0);
	while (*line != '\n')
	{
		if (*line == WALL)
			game->map.tile[x] = WALL;
		else if (*line == GROUND)
			game->map.tile[x] = GROUND;
		else if (*line == ITEM)
			game->map.tile[x] = ITEM;
		else if (*line == DOOR)
			game->map.tile[x] = DOOR;
		else if (*line == PLAYER)
			game->map.tile[x] = PLAYER;
		else if (*line == '\0')
			return (0);
		else
		{
			game->error = ERROR_CHAR_NO_VALID;
			return (1); 
		}
		line++;
		x++;
	}
	game->map.lenx = x;
	return (0);
}

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
	lentmp = game->map.lenx;  //save pour compare le prochain tour
	tmp = ft_strdup(game->map.tile);
	free(game->map.tile);
	game->map.tile = ft_strjoin(tmp, game->line);
	free(tmp);
	free(game->line);
	game->map.bool = 1;
	return (0);
}

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
		game->error = ERROR_NO_ITEM;
	else if (p <= 0)
		game->error = ERROR_NO_PLAYER;
	else if (e <= 0)
		game->error = ERROR_NO_EXIT;
	if (game->error != NO_ERROR)
		write_error_type(game);
	return (0);
}

int	check_wall_close_map(t_data *game)
{
	
	return (0);
}

int	parsing_map(t_data	*game, char *pathfile)
{
	int		fd;
	char	line;
	
	game->map.bool = 0;
	fd = open(pathfile, O_RDONLY);
	game->map.tile = ft_strdup("");

	while (1)
	{
		if(fill_data_map(game, fd))
			write_error_type(game);
		if (!game->line)
			break;
		//printf("  |||||\n\n");
	}
	if (check_minimum_required(game))
			write_error_type(game);
	if (put_good_img_debug(game, game->map.tile))
			write_error_type(game);
	//printf("%s", game->map.tile);

	return (fd);
}

int main()
{
	char path[] = "maps/01.ber";
	int	fd;
	t_data	game;
	
	if ((fd = parsing_map(&game, path)) > 0)
		//printf("SUCCESS OPEN\n");
	//else
		//printf("FAIL TO OPEN\n");
	//printf("map tile %c\n\n", game.map.tile[0]);
	free(game.map.tile);
	return (0);
}
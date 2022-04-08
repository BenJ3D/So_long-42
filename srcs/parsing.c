/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:48:31 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/08 20:44:38 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
//TODO: apprendre comment joint 2 struc (apprendre les list chain) 
int	put_good_img_debug(t_data *game, char *line)
{
	if (!line)
		return (0);
	while (*line)
	{
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
		line++;
	}
	return (0);
}

int		make_map(t_data *game, char *line) //TODO: MALLOC TILE + JOINT!
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

int	parsing_map(t_data	*game, char *pathfile)
{
	int		fd;
	char	*line;
	
	fd = open(pathfile, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		game->map.lenx = ft_strlen(line);
		//TODO: malloc et joint tile
		game->map.tile = malloc(sizeof(char) * game->map.lenx + 1);
		if(make_map(game, line))
			write_error_type(game);
		if (put_good_img_debug(game, line))
			write_error_type(game);
		if (!line)
			break;
		printf("  |||||\n\n");
	}
	return (fd);
}

int main()
{
	char path[] = "maps/01.ber";
	int	fd;
	t_data	game;
	
	if ((fd = parsing_map(&game, path)) > 0)
		printf("SUCCESS OPEN\n");
	else
		printf("FAIL TO OPEN\n");

	return (0);
}
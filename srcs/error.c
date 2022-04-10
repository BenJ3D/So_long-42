/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:47:13 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/10 19:59:54 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	write_error_type(t_data *game)
{
	if (game->error == ERROR_ARG_NBR)
		ft_putstr("Error\nPlease enter one path argument\n");
	else if (game->error == ERROR_FILE_TYPE)
		ft_putstr("Error\nFile is not .ber extension\n");
	else if (game->error == ERROR_MAP_CHAR_NO_VALID)
		ft_putstr("Error\nUnknown character detected,\
 are allowed:\n1 : Wall\n0 : Empty location\nC : Collectible\nE\
 : Exit\nP : Position player");
	else if (game->error == ERROR_MAP_NO_RECT)
		ft_putstr("Error\nMap is not rectangular\n");
	else if (game->error == ERROR_MAP_NO_PLAYER)
		ft_putstr("Error\nPlease add one 'P' on map for position player \
start position\n");
	else if (game->error == ERROR_MAP_NO_ITEM)
		ft_putstr("Error\nPlease add minimum one 'C' \
collectible item on map\n");
	else if (game->error == ERROR_MAP_NO_EXIT)
		ft_putstr("Error\nPlease add minimum one 'E' in map for exit game\n");
	else if (game->error == ERROR_MAP_WALL)
		ft_putstr("Error\nThe map is not closed with walls on all exteriors\n");
	else if (game->error == ERROR_FILE_NOT_EXIST)
		ft_putstr("Error\nThe file don't exist or is corrupted\n");
	if (game->error != NO_ERROR)
		exit(0);
	return (0);
}

//TODO: FIXME: le virer
int	check_name_file(char *str, char *filetype)
{
	int	i;
	int	y;

	i = ft_strlen(str);
	y = ft_strlen(filetype);
	if ((i + y) <= y)
		return (1);
	return (0);
}

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
	while (y >= 0)
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
		game->error = ERROR_ARG_NBR;
	else if (check_type_file(str, ".ber"))
		game->error = ERROR_FILE_TYPE;
	else if (game->error != NO_ERROR)
		return (1);
	return (0);
}

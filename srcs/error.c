/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:47:13 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/06 17:55:12 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	write_error_type(t_data *game)
{
	if (game->error == ERROR_ARG_NBR)
		ft_putstr("Error number of argument :\nPlease enter one path argument\n");
	else if (game->error == ERROR_FILE_TYPE)
		ft_putstr("Error file type :\nFile is not .ber extension\n");
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
	//ft_putstr("Starting..."); //FIXME:
	return(0);
}

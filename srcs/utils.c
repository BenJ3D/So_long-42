/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:47:13 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/12 14:29:08 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Prend une str et cherche si le char c est dedans
 * 
 * @param str 
 * @param c 
 * @return int return number result
 */
int	ft_str_search_char(char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	if (counter > 0)
		return (counter);
	return (0);
}

// /**
//  * @brief Prend une str et cherche si l'un des char
//  * 
//  * @param str 
//  * @param c 
//  * @return int return 1 si auncun char trouve
//  */
// int	ft_str_search_str(char *str, char *cmp)
// {
// 	int	i;
// 	int	y;

// 	i = 0;
// 	y = 0;
// 	while (cmp[y])
// 	{
// 		while (str[i])
// 		{
// 			if (str[i] != cmp[y])
// 				return (1);
// 			i++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }

// int	ft_strchr_c(const char *s, int c)
// {	
// 	while (*s != (char)c)
// 	{
// 		if (*s == '\0')
// 			return (0);
// 		s++;
// 	}
// 	return (1);
// }
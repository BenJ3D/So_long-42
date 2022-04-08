/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:47:13 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/08 16:14:15 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_open_file(char *path)
{
	int	fd;
	
	fd = open(path, O_RDONLY);
	return (fd);
}

// int main()
// {
// 	str path[] = "./01.ber";
// 	if (open_file(path));
// 		printf("SUCCESS OPEN\n");
// 	else
// 		printf("FAIL TO OPEN\n");

// 	return (0);
// }
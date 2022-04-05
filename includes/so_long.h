/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:51:25 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/05 19:25:02 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
typedef struct	s_player
{
	int posx;
	int	posy;
	int	size;
}				t_player;

typedef struct	s_map
{
	int posx;
	int	posy;
	int	size;
}				t_map;
typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	void	*grass;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_player	plyr;
	t_map		map;
	int		img_width;
	int		img_height;
}				t_data;

enum	e_key
{
	touch_w=13,
	touch_d=2,
	touch_a=0,
	touch_s=1,
	touch_up=126,
	touch_down=125,
	touch_left=123,
	touch_right=124,
	touch_esc=53
};

int		trace_background(t_data *img, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	key_hook(int keycode, t_data *img);
int	mouse_hook(int keycode, t_data *img);
int trace_square(t_data *img);

#endif
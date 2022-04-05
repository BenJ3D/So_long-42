/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:51:25 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/05 23:27:36 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_release		3
# define X_EVENT_KEY_EXIT		17 //exit key code
# define SIZE_PNG				64
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

typedef struct s_png
{
	int		w;
	int		h;
	void	*img;
}				t_png;

typedef struct s_level
{
	t_png	grass;
	t_png	wall;
	t_png	collect;
	t_png	player;
	t_png	gate;
	
}				t_level;


typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_player	plyr;
	t_map		map;
	t_level		solong;
	t_png		player;
	t_png		collect;
	t_png		door;
	t_png		grass;
	
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

int		trace_door(t_data *game);
int		trace_apple(t_data *game);
int		trace_player(t_data *game);
int		trace_backgroundold(t_data *img, int color);
int		trace_background(t_data *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	key_hook(int keycode, t_data *img);
int	mouse_hook(int keycode, t_data *img);
int trace_square(t_data *img);

#endif
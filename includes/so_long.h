/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:51:25 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/06 13:52:00 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/gnl/get_next_line.h"
# include <math.h>
# include <stdio.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17 //exit key code
# define SIZE_PNG				64

typedef struct s_png
{
	int		w;
	int		h;
	void	*img;
}				t_png;
typedef struct s_player
{
	int		posx;
	int		posy;
	int		size;
	t_png	png;
}				t_player;

typedef struct s_map // FIXME: a virer ?
{
	int		posx;
	int		posy;
	int		size;
}				t_map;

typedef struct s_txture // FIXME: a virer ?
{
	t_png	grass;
	t_png	wall;
	t_png	collect;
	t_png	player;
	t_png	gate;
}				t_txture;

typedef struct s_data
{
	void		*mlx;
	void		*windows;
	int			size_winx;
	int			size_winy;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_player	player;
	t_png		item;
	t_png		door;
	t_png		ground;
	int			img_width;
	int			img_height;
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

/******-------------srcs ---------------******/
/**
 * @brief ft test pour compile make file correctement
 * 
 */
void	hello(void);

/******------------------ practice function -------*/
int		trace_door(t_data *game);
int		trace_apple(t_data *game);
int		trace_player(t_data *game);
int		trace_backgroundold(t_data *img, int color);
int		trace_background(t_data *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_data *img);
int		mouse_hook(int keycode, t_data *img);
int		trace_square(t_data *img);

#endif
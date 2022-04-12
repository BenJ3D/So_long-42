/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:51:25 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/12 15:32:17 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/gnl/get_next_line.h"
# include <math.h>
# include <stdio.h> // FIXME:
# include <fcntl.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17 //exit key code
# define SIZE_PNG				64

/****------------ enum ------------****/
enum	e_error
{
	NO_ERROR,
	ERROR_ARG_NBR,
	ERROR_FILE_TYPE,
	ERROR_FILE_NOT_EXIST,
	ERROR_FILE_NO_NAME, //FIXME: accepter les ".ber" ?
	ERROR_MAP,
	ERROR_MAP_NO_RECT,
	ERROR_MAP_CHAR_NO_VALID,
	ERROR_MAP_NO_PLAYER,
	ERROR_MAP_NO_ITEM,
	ERROR_MAP_NO_EXIT,
	ERROR_MAP_WALL
};

enum	e_type_obj
{
	WALL='1',
	GROUND='0', 
	ITEM='C',
	DOOR='E',
	PLAYER='P'
};

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

/****----------- struct -----------****/
typedef struct s_clist
{
	char			*content;
	struct s_clist	*next;
}					t_clist;
typedef struct s_tile // trop complex A VIRER TODO:
{
	int				x;
	int				y;
	char			c;
}			t_tile;

typedef struct s_map
{
	char			*tile;
	int				i;
	int				bool;
	int				lenx;
	int				lenx_less1;
	int				leny;
}			t_map;
typedef struct s_png
{
	int		w;
	int		h;
	void	*img;
	char	path[255];
}				t_png;
typedef struct s_player
{
	int		posx;
	int		posy;
	int		posi;
	int		size;
	t_png	png;
}				t_player;
typedef struct s_data
{
	void			*arg;
	void			*mlx;
	void			*windows;
	int				size_winx;
	int				size_winy;
	void			*img;
	int				img_width;
	int				img_height;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	char			*line;
	int				endian;
	t_player		player;
	t_png			item;
	t_png			door;
	t_png			ground;
	t_png			wall;
	int				b_door;				
	int				i_map;
	t_map			map;
	enum e_error	error;
}				t_data;


/******----------------- intialise img ----------------------******/

void	define_all_png_to_image(t_data *game);
void	define_all_xpm_to_image(t_data *game);

/******------------------ parsing ------------------------******/

int	parsing_map(t_data	*game, char *pathfile);


/******-------------- manage open file -------------------******/

int		ft_open_file(char *path, t_data *game);
int		put_good_img_debug(t_data *game, char *line);

/******--------------- manage error --------------------******/

int		write_error_type(t_data *game);
int		check_type_file(char *str, char *filetype);
int		check_norm_arg_is_ok(int ac, char *str, t_data *game);


/******------------------- utils ---------------------******/

int	ft_str_search_char(char *str, char c);
int	ft_str_search_str(char *str, char *cmp);
int	ft_strchr_c(const char *s, int c);

/******-------------- image management ---------------******/

int	push_tile_to_win(t_data *game);
int	push_windows(t_data *game);


/******-------------- hook management ---------------******/

int		key_hook(int keycode, t_data *game);

/******------------------ practice function -------*/

int		trace_door(t_data *game);
int		trace_apple(t_data *game);
int		trace_player(t_data *game);
int		trace_backgroundold(t_data *img, int color);
int		trace_background(t_data *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
// int		key_hook(int keycode, t_data *img);
int		mouse_hook(int keycode, t_data *img);
int		trace_square(t_data *img);

#endif
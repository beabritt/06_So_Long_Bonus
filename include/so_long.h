/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:39:39 by becamino          #+#    #+#             */
/*   Updated: 2024/03/13 19:15:52 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
// include "../mlx/mlx.h"

// ** ENUMS ** 

enum e_return
{
	ERROR = -1,
	NO_ERROR = 0	
};

enum e_flood
{
	NO_PATH,
	KEEP_FLOOD,
	PATH
};

// ** KEY DEFINES **

# define DESTROY 	17
# define ESC_K 		53
# define UP_K 		13
# define DOWN_K 	1
# define LEFT_K 	0
# define RIGHT_K 	2
# define UP_A		126
# define DOWN_A		125
# define LEFT_A		123
# define RIGHT_A	124

// **  IMAGES DEFINES **

# define PLYR_F "./images/front0.xpm"
# define PLYR_B "./images/back0.xpm"
# define PLYR_L "./images/left0.xpm"
# define PLYR_R "./images/right0.xpm"
# define WLL "./images/wall0.xpm"
# define COL "./images/pokeflute0.xpm"
# define EXT1 "./images/snorlax02.xpm"
# define EXT2 "./images/stairs.xpm"
# define GRND "./images/free_space0.xpm"
# define CNTR "./images/counter.xpm"

// ** STRUCTS **

typedef struct s_map
{
	char			*line;
	struct s_map	*next;

}				t_map;

typedef struct s_parse
{
	int			coll;
	int			cat;
	int			exit;
}				t_parse;

typedef struct s_img
{
	void	*image;
	int		height;
	int		width;
	int		x;
	int		y;
}				t_img;

typedef struct s_imgp
{
	void	*image_f;
	void	*image_b;
	void	*image_r;
	void	*image_l;
	int		height;
	int		width;
	int		x;
	int		y;
	int		position;
}				t_imgp;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		count_collectibles;
	int		map_width;
	int		map_height;
	int		plyr_steps;
	t_imgp	player;
	t_img	ground;
	t_img	walls;
	t_img	collectibles;
	t_img	exit1;
	t_img	exit2;
	t_img	counter;
	t_map	*map;
}				t_game;

// ** FUNCTIONS **

// main funcions.
void	init_so_long(t_map *map, t_game *game);
void	ft_createmap(char *argv, t_map **map);
t_game	*ft_gamedata(t_map *map, t_game *game);
void	load_images(t_game *game);

// lst functions.
t_map	**ft_createnode(t_map **map, char *line);
t_map	*ft_lstnew_so(char *n_line);
void	ft_lstaddback_so(t_map **map, t_map *node);

// !!
void	ft_print_map(t_map **map);

// free_functions.
void	ft_lstclear_so(t_map **map);
void	ft_lstdelone_so(t_map *map);
void	ft_delgame(t_game *game);

// parse.
int		checkargv(char *argv);
void	ft_checkmap(t_map *map, t_game *game);
int		ft_checkdata(t_map **map, t_game *game);
int		ft_walls(t_map **map);
int		ft_form(t_map **map);
t_parse	ft_init_data(void);
int		ft_basics(t_map **map, t_parse data);
int		ft_invalid_characters(t_map **map);
int		ft_checkpath(t_map **map, t_game *game);
t_map	*ft_copymap(t_map **map);
int		ft_floodmap(t_map *copy, t_game *game_copy);
void	ft_check_left(t_map *copy, t_game *game, int *flood);
void	ft_check_right(t_map *copy, t_game *game_copy, int *flood);
void	ft_check_down(t_map *copy, t_game *game_copy, int *flood);
void	ft_check_up(t_map *copy, t_game *game_copy, int *flood);
void	ft_checkwriter_right(t_map *copy, t_game *game_copy, int *flood);
void	ft_checkwriter_left(t_map *copy, t_game *game_copy, int *flood);
void	ft_checkwriter_down(t_map *copy, t_map *aux, t_game *game_copy,
			int *flood);
void	ft_checkwriter_up(t_map *aux, t_map *prev, t_game *game_copy,
			int *flood);

// set_map.
void	init_map(t_game *game, t_map *map);
void	init_floor(t_game *game);
void	init_wallsandexit(t_game *game, t_map *map);
void	init_playerandcollectibles(t_game *game, t_map *map);
void	ft_set_exit(t_game *game);

// movements.
void	put_player(t_game *game, int position);
void	put_ground(t_game *game, int x, int y);
void	ft_move_right(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);

// exit functions.
int		ft_only_werror(char *s);
int		fast_close(t_game *game);
int		fast_close_success(t_game *game);
int		fast_close_error(t_game *game, char *s);
int		fast_close_images(t_game *game);
void	destroy_all_images(t_game *game);

// bonus functions.
void	print_steps(t_game *game);
#endif
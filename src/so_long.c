/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:34:26 by becamino          #+#    #+#             */
/*   Updated: 2024/04/16 13:37:19 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#define WHITE 0x00FFFFFF
#define WIDTH 50

t_game	*ft_gamedata(t_map *map, t_game *game)
{
	int		i;
	t_map	*aux;

	aux = map;
	game = malloc(sizeof(t_game));
	game->count_collectibles = 0;
	game->map_width = 0;
	game->map_height = 1;
	game->plyr_steps = 0;
	game->map = map;
	while (aux != NULL)
	{
		i = -1;
		while (aux->line[++i] != '\0')
		{
			if (aux->line[i] == 'C')
				game->count_collectibles += 1;
		}
		if (aux->next == NULL)
			break ;
		aux = aux->next;
		game->map_height++;
	}
	game->map_width = ft_strlen(aux->line);
	return (game);
}

void	print_steps(t_game *game)
{
	char	*str;
	char	*n;

	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->counter.image, 0, 0);
	n = ft_itoa(game->plyr_steps);
	str = ft_strjoin("Steps: ", n);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 0, 0, WHITE, str);
	free(n);
	free(str);
}

int	key_hook(int keycode, t_game *game)
{
	int		step_controller;

	step_controller = game->plyr_steps;
	if (keycode == ESC_K)
		fast_close(game);
	if (keycode == RIGHT_K || keycode == RIGHT_A)
		ft_move_right(game);
	if (keycode == LEFT_K || keycode == LEFT_A)
		ft_move_left(game);
	if (keycode == UP_K || keycode == UP_A)
		ft_move_up(game);
	if (keycode == DOWN_K || keycode == DOWN_A)
		ft_move_down(game);
	if (game->count_collectibles == 0)
		ft_set_exit(game);
	if (step_controller != game->plyr_steps)
		print_steps(game);
	return (0);
}

void	init_so_long(t_map *map, t_game *game)
{
	t_map	*f_copy;

	game->mlx_ptr = NULL;
	game->mlx_win = NULL;
	f_copy = ft_copymap(&map);
	ft_checkmap(f_copy, game);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("mlx couldn't be initialized\n");
		exit(EXIT_FAILURE);
	}
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->map_width * 32,
			game->map_height * 32, "so_long");
	if (!game->mlx_win)
	{
		ft_printf("mlx window couldn't be initialized\n");
		free(game->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	load_images(game);
	init_map(game, map);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, DESTROY, 0, fast_close, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	map = NULL;
	game = NULL;
	if (argc == 2)
	{
		if (checkargv(argv[1]) == ERROR)
		{
			ft_printf("This is not a valid file D:\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			ft_createmap(argv[1], &map);
			game = ft_gamedata(map, game);
			init_so_long(map, game);
		}
	}
	else
	{
		ft_printf("I need one map D:\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

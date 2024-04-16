/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:54:35 by becamino          #+#    #+#             */
/*   Updated: 2024/04/16 13:37:09 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_walls2(t_game *game, t_map *aux)
{
	while (game->walls.x < game->map_width || aux->line[game->walls.x] != '\0')
	{
		if (aux->line[game->walls.x] == '1')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->walls.image, 32 * game->walls.x, 32 * game->walls.y);
		}
		if (aux->line[game->walls.x] == 'E')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->exit1.image, 32 * game->walls.x, 32 * game->walls.y);
		}
		game->walls.x++;
	}
}

void	init_wallsandexit(t_game *game, t_map *map)
{
	t_map	*aux;

	aux = map;
	game->exit1.x = 0;
	game->exit1.y = 0;
	game->walls.x = 0;
	game->walls.y = 0;
	while (aux != NULL || game->walls.y < game->map_height)
	{
		init_walls2(game, aux);
		if (aux->next == NULL)
			break ;
		aux = aux->next;
		game->walls.x = 0;
		game->walls.y++;
	}
}

void	init_floor(t_game *game)
{
	game->ground.x = 0;
	game->ground.y = 0;
	while (game->ground.y < game->map_height)
	{
		while (game->ground.x < game->map_width)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->ground.image, 32 * game->ground.x, 32 * game->ground.y);
			game->ground.x++;
		}
		game->ground.x = 0;
		game->ground.y++;
	}
}

void	init_map(t_game *game, t_map *map)
{
	load_images(game);
	init_floor(game);
	init_wallsandexit(game, map);
	init_playerandcollectibles(game, map);
}

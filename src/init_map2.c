/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:37:20 by becamino          #+#    #+#             */
/*   Updated: 2023/12/22 14:59:45 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_player2(t_game *game, t_map *aux)
{
	while (game->player.x < game->map_width
		|| aux->line[game->player.x] != '\0')
	{
		if (aux->line[game->player.x] == 'P')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->player.image_f, 32 * game->player.x,
				32 * game->player.y);
		}
		if (aux->line[game->player.x] == 'C')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->collectibles.image, 32 * game->player.x,
				32 * game->player.y);
		}
		game->player.x++;
	}
}

void	init_playerandcollectibles(t_game *game, t_map *map)
{
	t_map	*aux;

	aux = map;
	game->player.x = 0;
	game->player.y = 0;
	game->player.position = 0;
	game->collectibles.x = 0;
	game->collectibles.y = 0;
	game->player.image_f = mlx_xpm_file_to_image(game->mlx_ptr, PLYR_F,
			&game->player.width, &game->player.height);
	if (!game->player.image_f)
		fast_close_images(game);
	while (aux != NULL || game->player.y < game->map_height)
	{
		init_player2(game, aux);
		if (aux->next == NULL)
			break ;
		aux = aux->next;
		game->player.x = 0;
		game->player.y++;
	}
}

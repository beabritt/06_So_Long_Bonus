/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:50:59 by becamino          #+#    #+#             */
/*   Updated: 2023/12/22 15:30:10 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_set_exit2(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->ground.image, 32 * game->exit1.x, 32 * game->exit1.y);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->exit2.image, 32 * game->exit1.x, 32 * game->exit1.y);
}

void	ft_set_exit(t_game *game)
{
	t_map	*aux;
	int		done;

	aux = game->map;
	game->exit1.y = 0;
	while (aux != NULL || done == 0)
	{
		game->exit1.x = 0;
		while (aux->line[game->exit1.x] != '\0'
			|| game->exit1.x < game->map_width)
		{
			if (aux->line[game->exit1.x] == 'E')
			{
				aux->line[game->exit1.x] = 'X';
				ft_set_exit2(game);
				done = 1;
				break ;
			}
			game->exit1.x++;
		}
		if (aux->next == NULL)
			break ;
		aux = aux->next;
		game->exit1.y++;
	}
}

void	put_player(t_game *game, int position)
{
	if (position == 1)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->player.image_f, game->player.x * 32, game->player.y * 32);
	}
	else if (position == 2)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->player.image_b, game->player.x * 32, game->player.y * 32);
	}
	else if (position == 3)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->player.image_r, game->player.x * 32, game->player.y * 32);
	}
	else if (position == 4)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->player.image_l, game->player.x * 32, game->player.y * 32);
	}
	game->plyr_steps += 1;
	ft_printf("Steps: %i\n", game->plyr_steps);
}

void	put_ground(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->ground.image, 32 * x, 32 * y);
}

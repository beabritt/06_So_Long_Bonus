/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:43:35 by becamino          #+#    #+#             */
/*   Updated: 2024/03/13 19:03:43 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_right3(t_game *game, t_map *aux)
{
	if (aux->line[game->player.x + 1] == 'C'
		|| aux->line[game->player.x + 1] == '0')
		aux->line[game->player.x + 1] = 'P';
	game->player.position = 3;
	game->player.x += 1;
	put_player(game, game->player.position);
	aux->line[game->player.x - 1] = '0';
	put_ground(game, game->player.x - 1, game->player.y);
	if (aux->line[game->player.x] == 'X')
		fast_close_success(game);
}

void	ft_move_right2(t_game *game, t_map *aux, int *done)
{
	while (aux->line[game->player.x] != '\0')
	{
		if (aux->line[game->player.x] == 'P')
		{
			if (aux->line[game->player.x + 1] == '0'
				|| aux->line[game->player.x + 1] == 'C'
				|| aux->line[game->player.x + 1] == 'X')
			{
				if (aux->line[game->player.x + 1] == 'C')
				{
					game->count_collectibles -= 1;
					put_ground(game, game->player.x + 1, game->player.y);
				}
				ft_move_right3(game, aux);
				*done = 1;
				break ;
			}
		}
		game->player.x++;
	}
}

void	ft_move_right(t_game *game)
{
	t_map	*aux;
	int		done;

	done = 0;
	aux = game->map;
	game->player.x = 0;
	game->player.y = 0;
	while (aux != NULL && done == 0)
	{
		ft_move_right2(game, aux, &done);
		if (aux->next == NULL || done == 1)
			break ;
		aux = aux->next;
		game->player.x = 0;
		game->player.y++;
	}
}
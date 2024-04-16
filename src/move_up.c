/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:54:16 by becamino          #+#    #+#             */
/*   Updated: 2024/01/08 16:47:42 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_up3(t_game *game, t_map *aux, t_map *prev)
{
	if (prev->line[game->player.x] == '0' || prev->line[game->player.x] == 'C')
		prev->line[game->player.x] = 'P';
	game->player.position = 2;
	put_player(game, game->player.position);
	aux->line[game->player.x] = '0';
	put_ground(game, game->player.x, game->player.y + 1);
	if (prev->line[game->player.x] == 'X')
		fast_close_success(game);
}

void	ft_move_up2(t_game *game, int *done, t_map *aux, t_map *prev)
{
	while (aux->line[game->player.x] != '\0')
	{
		if (aux->line[game->player.x] == 'P'
			&& prev->line[game->player.x] != '1')
		{
			if (prev->line[game->player.x] == '0'
				|| prev->line[game->player.x] == 'C'
				|| prev->line[game->player.x] == 'X')
			{
				if (prev->line[game->player.x] == 'C')
				{
					game->count_collectibles -= 1;
					put_ground(game, game->player.x, game->player.y);
				}
				ft_move_up3(game, aux, prev);
				*done = 1;
				break ;
			}
		}
		game->player.x++;
	}
}

void	ft_move_up(t_game *game)
{
	int		done;
	t_map	*prev;
	t_map	*aux;

	done = 0;
	prev = game->map;
	game->player.x = 0;
	game->player.y = 0;
	while (prev->next != NULL && done == 0)
	{
		aux = prev->next;
		ft_move_up2(game, &done, aux, prev);
		if (prev->next == NULL)
			break ;
		prev = prev->next;
		game->player.x = 0;
		game->player.y++;
	}
}

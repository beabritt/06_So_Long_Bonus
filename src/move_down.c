/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:53:02 by becamino          #+#    #+#             */
/*   Updated: 2023/12/22 15:19:44 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_down3(t_game *game, t_map *aux, t_map *next_p)
{
	if (next_p->line[game->player.x] == '0'
		|| next_p->line[game->player.x] == 'C')
		next_p->line[game->player.x] = 'P';
	game->player.position = 1;
	game->player.y += 1;
	put_player(game, game->player.position);
	aux->line[game->player.x] = '0';
	put_ground(game, game->player.x, game->player.y - 1);
	if (next_p->line[game->player.x] == 'X')
		fast_close_success(game);
}

void	ft_move_down2(t_game *game, int *done, t_map *aux, t_map *next_p)
{
	while (aux->line[game->player.x] != '\0')
	{
		if (aux->line[game->player.x] == 'P'
			&& next_p->line[game->player.x] != '1')
		{
			if (next_p->line[game->player.x] == '0'
				|| next_p->line[game->player.x] == 'C'
				|| next_p->line[game->player.x] == 'X')
			{
				if (next_p->line[game->player.x] == 'C')
				{
					game->count_collectibles -= 1;
					put_ground(game, game->player.x, game->player.y + 1);
				}
				ft_move_down3(game, aux, next_p);
				*done = 1;
				break ;
			}
		}
		game->player.x++;
	}
}

void	ft_move_down(t_game *game)
{
	int		done;
	t_map	*aux;
	t_map	*next_p;

	done = 0;
	game->player.x = 0;
	game->player.y = 0;
	aux = game->map;
	next_p = aux->next;
	while (next_p->next != NULL && done == 0)
	{
		ft_move_down2(game, &done, aux, next_p);
		if (next_p->next == NULL)
			break ;
		aux = next_p;
		next_p = next_p->next;
		game->player.x = 0;
		game->player.y++;
	}
}

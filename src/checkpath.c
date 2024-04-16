/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:14:08 by becamino          #+#    #+#             */
/*   Updated: 2024/03/13 17:10:31 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_set_f(t_map *copy)
{
	t_map	*aux;
	int		i;

	aux = copy;
	while (aux != NULL)
	{
		i = 0;
		while (aux->line[i] != '\0')
		{
			if (aux->line[i] == 'P')
				aux->line[i] = 'F';
			i++;
		}
		if (aux->next == NULL)
			break ;
		else
			aux = aux->next;
	}
}

int	ft_floodmap(t_map *copy, t_game *game_copy)
{
	int	flood;

	flood = KEEP_FLOOD;
	ft_set_f(copy);
	while (flood == KEEP_FLOOD)
	{
		flood = NO_PATH;
		ft_check_left(copy, game_copy, &flood);
		if (flood == PATH)
			return (NO_ERROR);
		ft_check_right(copy, game_copy, &flood);
		if (flood == PATH)
			return (NO_ERROR);
		ft_check_up(copy, game_copy, &flood);
		if (flood == PATH)
			return (NO_ERROR);
		ft_check_down(copy, game_copy, &flood);
		if (flood == PATH)
			return (NO_ERROR);
	}
	return (ERROR);
}

void	ft_delgame(t_game *game_copy)
{
	if (!game_copy)
		return ;
	game_copy->count_collectibles = 0;
	game_copy->map_width = 0;
	free(game_copy);
	game_copy = NULL;
}

int	ft_checkpath(t_map **map, t_game *game)
{
	t_map	*copy;
	t_game	*game_copy;

	copy = NULL;
	game_copy = malloc(sizeof(t_game));
	copy = ft_copymap(map);
	game_copy->count_collectibles = game->count_collectibles;
	game_copy->map_width = game->map_width;
	if (ft_floodmap(copy, game_copy) == ERROR)
	{
		ft_lstclear_so(&copy);
		ft_lstclear_so(map);
		ft_delgame(game_copy);
		return (ERROR);
	}
	ft_lstclear_so(&copy);
	ft_lstclear_so(map);
	ft_delgame(game_copy);
	return (NO_ERROR);
}

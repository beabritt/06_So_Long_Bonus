/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:40:32 by becamino          #+#    #+#             */
/*   Updated: 2023/12/18 15:53:10 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_checkwriter_up(t_map *aux, t_map *prev, t_game *game_copy,
			int *flood)
{
	int	i;

	i = 0;
	while (aux->line[i] != '\0' && *flood != PATH)
	{
		if (aux->line[i] == 'F')
		{
			if (prev->line[i] == 'C')
			{
				game_copy->count_collectibles -= 1;
				prev->line[i] = 'F';
				*flood = KEEP_FLOOD;
			}
			else if (prev->line[i] == '0')
			{
				prev->line[i] = 'F';
				*flood = KEEP_FLOOD;
			}
			else if (prev->line[i] == 'E')
				if (game_copy->count_collectibles == 0)
					*flood = PATH;
		}
		i++;
	}
}

void	ft_check_up(t_map *copy, t_game *game_copy, int *flood)
{
	t_map	*prev;
	t_map	*aux;

	prev = copy;
	while (prev->next != NULL && *flood != PATH)
	{
		aux = prev->next;
		ft_checkwriter_up(aux, prev, game_copy, flood);
		if (prev->next == NULL)
			break ;
		prev = prev->next;
	}
}

void	ft_checkwriter_down(t_map *copy, t_map *aux, t_game *game_copy,
			int *flood)
{
	int	i;

	i = 0;
	while (copy->line[i] != '\0' && *flood != PATH)
	{
		if (copy->line[i] == 'F')
		{
			if (aux->line[i] == 'C')
			{
				game_copy->count_collectibles -= 1;
				aux->line[i] = 'F';
				*flood = KEEP_FLOOD;
			}
			else if (aux->line[i] == '0')
			{
				aux->line[i] = 'F';
				*flood = KEEP_FLOOD;
			}
			else if (aux->line[i] == 'E')
				if (game_copy->count_collectibles == 0)
					*flood = PATH;
		}
		i++;
	}
}

void	ft_check_down(t_map *copy, t_game *game_copy, int *flood)
{
	t_map	*aux;

	while (copy->next != NULL && *flood != PATH)
	{
		aux = copy->next;
		ft_checkwriter_down(copy, aux, game_copy, flood);
		if (aux->next == NULL)
			break ;
		copy = copy->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:23:47 by becamino          #+#    #+#             */
/*   Updated: 2023/12/18 15:44:50 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_checkwriter_left(t_map *copy, t_game *game_copy, int *flood)
{
	int	i;

	i = game_copy->map_width;
	while (i > 0 && *flood != PATH)
	{
		if (copy->line[i] == 'F')
		{
			if (copy->line[i - 1] == 'C')
			{
				game_copy->count_collectibles -= 1;
				copy->line[i - 1] = 'F';
				*flood = KEEP_FLOOD;
			}
			else if (copy->line[i - 1] == '0')
			{
				copy->line[i - 1] = 'F';
				*flood = KEEP_FLOOD;
			}
			else if (copy->line[i - 1] == 'E')
				if (game_copy->count_collectibles == 0)
					*flood = PATH;
		}
		i--;
	}
}

void	ft_check_left(t_map *copy, t_game *game_copy, int *flood)
{
	t_map	*aux;

	aux = copy;
	while (aux != NULL && *flood != PATH)
	{
		ft_checkwriter_left(aux, game_copy, flood);
		if (aux->next == NULL)
			break ;
		aux = aux->next;
	}
}

void	ft_checkwriter_right(t_map *copy, t_game *game_copy, int *flood)
{
	int	i;

	i = 0;
	while (copy->line[i] != '\0' && *flood != PATH)
	{
		if (copy->line[i] == 'F')
		{
			if (copy->line[i + 1] == 'C')
			{
				game_copy->count_collectibles -= 1;
				copy->line[i + 1] = 'F';
				*flood = KEEP_FLOOD;
			}
			else if (copy->line[i + 1] == '0')
			{
				copy->line[i + 1] = 'F';
				*flood = KEEP_FLOOD;
			}
			else if (copy->line[i + 1] == 'E')
				if (game_copy->count_collectibles == 0)
					*flood = PATH;
		}
		i++;
	}
}

void	ft_check_right(t_map *copy, t_game *game_copy, int *flood)
{
	while (copy != NULL && *flood != PATH)
	{
		ft_checkwriter_right(copy, game_copy, flood);
		if (copy->next == NULL)
			break ;
		copy = copy->next;
	}
}

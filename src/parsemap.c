/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:08:44 by becamino          #+#    #+#             */
/*   Updated: 2024/01/08 16:52:04 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_form(t_map **map)
{
	t_map	*aux;
	int		i;
	int		j;

	j = 0;
	aux = *map;
	i = ft_strlen(aux->line);
	while (aux != NULL)
	{
		j = ft_strlen(aux->line);
		if (j != i)
			return (ERROR);
		aux = aux->next;
	}
	return (NO_ERROR);
}

int	ft_walls(t_map **map)
{
	t_map	*aux;
	char	*l_aux;

	aux = *map;
	while (aux != NULL)
	{
		l_aux = aux->line;
		while (*l_aux != '\0')
		{
			if ((aux->next == (*map)->next || aux->next == NULL)
				&& *l_aux != '1')
				return (ERROR);
			else if (aux->next != (*map)->next
				&& (aux->next != NULL))
				if ((l_aux == aux->line || *(l_aux + 1) == '\0')
					&& *l_aux != '1')
					return (ERROR);
			l_aux++;
		}
		if (aux->next != NULL)
			aux = aux->next;
		else
			break ;
	}
	return (NO_ERROR);
}

int	ft_basics(t_map **map, t_parse data)
{
	t_map	*aux;
	char	*l_aux;

	aux = *map;
	while (aux != NULL)
	{
		l_aux = aux->line;
		while (*l_aux != '\0')
		{
			if (*l_aux == 'C')
				data.coll += 1;
			else if (*l_aux == 'P')
				data.cat += 1;
			else if (*l_aux == 'E')
				data.exit += 1;
			l_aux++;
		}
		if (aux->next == NULL)
			break ;
		aux = aux->next;
	}
	if (data.coll == 0 || data.cat != 1 || data.exit != 1)
		return (ERROR);
	return (NO_ERROR);
}

int	ft_invalid_characters(t_map **map)
{
	t_map	*aux;
	char	*l_aux;
	int		i;

	aux = *map;
	i = 0;
	while (aux != NULL)
	{
		l_aux = aux->line;
		while (l_aux[i] != '\0')
		{
			if (*l_aux != '0' && *l_aux != '1' && *l_aux != 'C'
				&& *l_aux != 'P' && *l_aux != 'E')
				return (ERROR);
			i++;
		}
		if (aux->next == NULL)
			break ;
		aux = aux->next;
	}
	return (NO_ERROR);
}

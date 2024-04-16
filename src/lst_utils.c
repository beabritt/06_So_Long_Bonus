/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:26:49 by becamino          #+#    #+#             */
/*   Updated: 2024/04/16 14:42:59 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_lstaddback_so(t_map **map, t_map *node)
{
	t_map	*aux;

	if (!*map)
	{
		*map = node;
	}
	else
	{
		aux = *map;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = node;
	}
}

t_map	*ft_lstnew_so(char *n_line)
{
	t_map	*node;

	node = malloc(sizeof(t_map));
	if (!node)
		return (NULL);
	node->line = n_line;
	node->next = NULL;
	return (node);
}

t_map	**ft_createnode(t_map **map, char *line)
{
	t_map	*node;

	node = ft_lstnew_so(line);
	ft_lstaddback_so(map, node);
	return (map);
}

void	ft_createmap(char *argv, t_map **map)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("file could not be opened D:\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Empty map :(\n");
		free(line);
		close(fd);
		exit(EXIT_FAILURE);
	}
	while (line != NULL)
	{
		ft_createnode(map, line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
}

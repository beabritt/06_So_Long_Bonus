/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:23:53 by becamino          #+#    #+#             */
/*   Updated: 2023/12/22 15:14:27 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strlcpy2(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i ++;
		}
		dst [i] = '\0';
		return (dst);
	}
	else
		return ("error");
}

t_map	*ft_copymap(t_map **map)
{
	t_map	*aux;
	t_map	*node;
	t_map	*copy;
	char	*line_copy;

	copy = NULL;
	node = NULL;
	line_copy = NULL;
	aux = *map;
	while (aux != NULL)
	{
		line_copy = malloc(sizeof(char *) * ft_strlen(aux->line));
		if (!line_copy)
		{
			ft_lstclear_so(&copy);
			exit (EXIT_FAILURE);
		}
		line_copy = ft_strlcpy2(line_copy, aux->line, ft_strlen(aux->line) + 1);
		node = ft_lstnew_so(line_copy);
		ft_lstaddback_so(&copy, node);
		aux = aux->next;
	}
	return (copy);
}

void	ft_print_map(t_map **map)
{
	t_map	*aux;

	if (*map == NULL)
	{
		ft_printf("(vacio)\n");
		return ;
	}
	aux = *map;
	while (aux->next != NULL)
	{
		ft_printf("%s\n", aux->line);
		aux = aux->next;
	}
	ft_printf("%s\n", aux->line);
}

void	ft_lstclear_so(t_map **map)
{
	t_map	*aux;

	if (!*map)
		return ;
	aux = *map;
	while (aux != NULL)
	{
		aux = aux->next;
		ft_lstdelone_so(*map);
		*map = aux;
	}
	*map = NULL;
}
// void	ft_lstdelone_so(t_map *map_node)
// {
// 	if (!map_node)
// 		return ;
// 	map_node->line = NULL;
// 	free(map_node);
// 	map_node = NULL;
// }

void	ft_lstdelone_so(t_map *map_node)
{
	if (!map_node)
		return ;
	free(map_node->line);
	free(map_node);
	map_node = NULL;
}

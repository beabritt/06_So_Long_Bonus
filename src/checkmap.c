/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:09:55 by becamino          #+#    #+#             */
/*   Updated: 2024/01/11 16:16:35 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_parse	ft_init_data(void)
{
	t_parse	data;

	data.coll = 0;
	data.cat = 0;
	data.exit = 0;
	return (data);
}

int	ft_checkdata(t_map **map, t_game *game)
{
	t_parse	data;

	data = ft_init_data();
	if (ft_invalid_characters(map) == ERROR)
		return (ft_only_werror("There are some non valid characters D:\n"));
	else if (ft_form(map) == ERROR)
		return (ft_only_werror("Invalid map form D:\n"));
	else if (ft_basics(map, data) == ERROR)
		return (ft_only_werror("Wrong data in this map D:\n"));
	else if (ft_walls(map) == ERROR)
		return (ft_only_werror("Walls are not closed D:\n"));
	else if (ft_checkpath(map, game) == ERROR)
		return (ft_only_werror("There is no possible path :(\n"));
	return (NO_ERROR);
}

void	ft_checkmap(t_map *map, t_game *game)
{
	if (ft_checkdata(&map, game) == ERROR)
	{
		ft_lstclear_so(&map);
		exit(EXIT_FAILURE);
	}
	ft_lstclear_so(&map);
}

int	checkargv(char *argv)
{
	char	*ber;
	int		x;

	ber = ".ber";
	x = ft_strlen(argv) - 4;
	if (ft_strncmp(&argv[x], ber, 3) == 0)
		return (NO_ERROR);
	else
		return (ERROR);
}

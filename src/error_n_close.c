/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_n_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:13:30 by becamino          #+#    #+#             */
/*   Updated: 2023/12/22 14:57:49 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	fast_close(t_game *game)
{
	ft_printf("Hope to see u soon :D\n");
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	ft_lstclear_so(&game->map);
	exit(EXIT_SUCCESS);
}

int	fast_close_success(t_game *game)
{
	ft_printf("Congrats!\n");
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	ft_lstclear_so(&game->map);
	exit(EXIT_SUCCESS);
}

int	fast_close_error(t_game *game, char *s)
{
	ft_printf("%s\n", s);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	ft_lstclear_so(&game->map);
	exit(EXIT_FAILURE);
}

int	fast_close_images(t_game *game)
{
	ft_printf("Couldn't load some image(s), please check they're correct :D\n");
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	ft_lstclear_so(&game->map);
	exit(EXIT_FAILURE);
}

int	ft_only_werror(char *s)
{
	int	size;

	size = ft_strlen(s);
	write(1, s, size);
	return (ERROR);
}

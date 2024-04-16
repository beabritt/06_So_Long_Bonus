/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:33:45 by becamino          #+#    #+#             */
/*   Updated: 2024/04/16 13:37:42 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_all_images(t_game *game)
{
	if (game->counter.image)
		mlx_destroy_image(game->mlx_ptr, game->counter.image);
	if (game->ground.image)
		mlx_destroy_image(game->mlx_ptr, game->ground.image);
	if (game->walls.image)
		mlx_destroy_image(game->mlx_ptr, game->walls.image);
	if (game->collectibles.image)
		mlx_destroy_image(game->mlx_ptr, game->collectibles.image);
	if (game->walls.image)
		mlx_destroy_image(game->mlx_ptr, game->ground.image);
	if (game->exit1.image)
		mlx_destroy_image(game->mlx_ptr, game->exit1.image);
	if (game->exit2.image)
		mlx_destroy_image(game->mlx_ptr, game->exit2.image);
	if (game->player.image_f)
		mlx_destroy_image(game->mlx_ptr, game->player.image_f);
	if (game->player.image_b)
		mlx_destroy_image(game->mlx_ptr, game->player.image_b);
	if (game->player.image_r)
		mlx_destroy_image(game->mlx_ptr, game->player.image_r);
	if (game->player.image_l)
		mlx_destroy_image(game->mlx_ptr, game->player.image_l);
}

int	load_player_images(t_game *game)
{
	int	control;

	control = 0;
	game->player.image_f = mlx_xpm_file_to_image(game->mlx_ptr, PLYR_F,
			&game->player.width, &game->player.height);
	game->player.image_b = mlx_xpm_file_to_image(game->mlx_ptr, PLYR_B,
			&game->player.width, &game->player.height);
	game->player.image_r = mlx_xpm_file_to_image(game->mlx_ptr, PLYR_R,
			&game->player.width, &game->player.height);
	game->player.image_l = mlx_xpm_file_to_image(game->mlx_ptr, PLYR_L,
			&game->player.width, &game->player.height);
	if (!game->player.image_b || !game->player.image_f || !game->player.image_r
		|| !game->player.image_l)
		return (ERROR);
	else
		return (NO_ERROR);
}

void	load_images(t_game *game)
{
	game->counter.image = mlx_xpm_file_to_image(game->mlx_ptr, CNTR,
			&game->counter.width, &game->counter.width);
	if (!game->counter.image)
		fast_close_images(game);
	game->ground.image = mlx_xpm_file_to_image(game->mlx_ptr, GRND,
			&game->ground.width, &game->ground.width);
	game->walls.image = mlx_xpm_file_to_image(game->mlx_ptr, WLL,
			&game->walls.width, &game->walls.height);
	game->collectibles.image = mlx_xpm_file_to_image(game->mlx_ptr, COL,
			&game->collectibles.width, &game->collectibles.height);
	if (!game->ground.image || !game->walls.image || !game->collectibles.image)
		fast_close_images(game);
	game->exit1.image = mlx_xpm_file_to_image(game->mlx_ptr, EXT1,
			&game->exit1.width, &game->exit1.height);
	game->exit2.image = mlx_xpm_file_to_image(game->mlx_ptr, EXT2,
			&game->exit2.width, &game->exit2.height);
	if (!game->exit1.image || !game->exit2.image)
		fast_close_images(game);
	if (load_player_images(game) == ERROR)
		fast_close_images(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 22:41:07 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/02 21:58:52 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_open_window(t_data *dt)
{
	if (!dt)
	{
		// PRINT ERROR MESSAGE
		return (FAILURE);
	}
	dt->graphics.mlx = mlx_init();
	if (!dt->graphics.mlx)
	{
		// PRINT ERROR MESSAGE
		return (FAILURE);
	}
	dt->graphics.window = mlx_new_window(dt->graphics.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!dt->graphics.window)
	{
		// PRINT ERROR MESSAGE
		free(dt->graphics.mlx);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_close_program(t_data *dt)
{
	if (!dt)
	{
		//PRINT ERROR MESSAGE
		exit(FAILURE);
	}
	if (dt->graphics.window)
		mlx_destroy_window(dt->graphics.mlx, dt->graphics.window);
	if (dt->graphics.mlx)
	{
		mlx_destroy_display(dt->graphics.mlx);
		free(dt->graphics.mlx);
	}
	exit(SUCCESS);
}

void	ft_game_loop(t_data *dt)
{
	if (!dt)
		ft_close_program(dt);
	ft_floor_img(dt);
	ft_ceiling_img(dt);
	mlx_hook(dt->graphics.window, 17, 0L, ft_close_program, dt);
	mlx_hook(dt->graphics.window, 2, 1L << 0, ft_key_events, dt);
	mlx_loop(dt->graphics.mlx);
}
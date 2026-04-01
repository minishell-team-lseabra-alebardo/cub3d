/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 22:41:07 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/01 23:54:34 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_open_window(t_graphics *graphics)
{
	if (!graphics)
	{
		// PRINT ERROR MESSAGE
		return (FAILURE);
	}
	graphics->mlx = mlx_init();
	if (!graphics->mlx)
	{
		// PRINT ERROR MESSAGE
		return (FAILURE);
	}
	graphics->window = mlx_new_window(graphics->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!graphics->window)
	{
		// PRINT ERROR MESSAGE
		free(graphics->mlx);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_close_program(t_graphics *graphics)
{
	if (graphics->window)
		mlx_destroy_window(graphics->mlx, graphics->window);
	if (graphics->mlx)
	{
		mlx_destroy_display(graphics->mlx);
		free(graphics->mlx);
	}
	exit(SUCCESS);
}

void	ft_game_loop(t_data *dt, t_graphics *graphics)
{
	if (!dt || !graphics)
	{
		// PRINT ERROR MESSAGE
		exit(FAILURE);
	}
	mlx_hook(graphics->window, 17, 0L, ft_close_program, graphics);
	mlx_loop(graphics->mlx);
}
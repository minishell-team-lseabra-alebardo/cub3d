/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_boundaries.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:55:07 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/27 18:33:43 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_result	ft_flood_fill_check(t_map *map, int row, int col)
{
	if (row < 0
		|| col < 0
		|| map->grid[row][col] == '\0'
		|| ft_is_space(map->grid[row][col]))
	{
		return (ft_p_err_ret(NULL, NULL, ERR_MAP_OPEN));
	}
	else if (map->grid[row][col] != '0')
		return (SUCCESS);
	map->grid[row][col] = 'V';
	if (ft_flood_fill_check(map, row - 1, col) != SUCCESS)
		return (FAILURE);
	else if (ft_flood_fill_check(map, row, col + 1) != SUCCESS)
		return (FAILURE);
	else if (ft_flood_fill_check(map, row + 1, col) != SUCCESS)
		return (FAILURE);
	else if (ft_flood_fill_check(map, row, col - 1) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

t_result	ft_validate_map_boundaries(t_map map_cpy)
{
	int	row;
	int	col;

	row = map_cpy.player_spawn.row;
	col = map_cpy.player_spawn.col;
	if (ft_flood_fill_check(&map_cpy, row, col) != SUCCESS)
		return (FAILURE);
	row = 0;
	col = 0;
	while (row < map_cpy.row_count)
	{
		while (map_cpy.grid[row][col])
		{
			if (map_cpy.grid[row][col] == '0'
				&& ft_flood_fill_check(&map_cpy, row, col) != SUCCESS)
			{
				return (FAILURE);
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (SUCCESS);
}

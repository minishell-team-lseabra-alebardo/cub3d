/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:29:37 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/27 17:54:39 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	ft_str_has_char(char c, char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static t_result	ft_validate_row_chars_and_spawn(t_map *map, size_t row)
{
	t_bool	is_spawn;
	size_t	col;

	col = 0;
	while (map->grid[row][col])
	{
		is_spawn = ft_str_has_char(map->grid[row][col], DIRECTIONS);
		if (is_spawn && map->player_spawn.row < 0)
		{
			map->player_spawn.row = row;
			map->player_spawn.col = col;
			map->player_spawn.direction = map->grid[row][col];
		}
		else if (is_spawn && map->player_spawn.row >= 0)
			return (ft_p_err_ret(NULL, NULL, ERR_MULT_SPAWN));
		else if (!ft_is_space(map->grid[row][col])
			&& !ft_str_has_char(map->grid[row][col], MAP_TILES))
		{
			return (ft_p_err_ret(NULL, map->grid[row], ERR_INV_C));
		}
		col++;
	}
	return (SUCCESS);
}

t_result	ft_validate_map_content(t_map *map)
{
	int	row;

	row = 0;
	while (row < map->row_count)
	{
		if (ft_validate_row_chars_and_spawn(map, row) != SUCCESS)
			return (FAILURE);
		row++;
	}
	if (map->player_spawn.row < 0)
	{
		ft_put_error(NULL, NULL, ERR_NO_SPAWN);
		return (FAILURE);
	}
	return (SUCCESS);
}

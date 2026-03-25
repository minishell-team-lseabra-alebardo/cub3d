/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:12:26 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/25 16:34:19 by lseabra-         ###   ########.fr       */
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
			return (ft_p_err_ret(NULL, NULL, ERR_MULT_SPAWN, FAILURE));
		else if (!ft_is_space(map->grid[row][col])
			&& !ft_str_has_char(map->grid[row][col], MAP_TILES))
		{
			return (ft_p_err_ret(NULL, map->grid[row], ERR_INV_C, FAILURE));
		}
		col++;
	}
	return (SUCCESS);
}

static t_result	ft_validate_map_content(t_map *map)
{
	size_t	row;

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

static t_result	ft_get_clean_row(t_data *dt, size_t row)
{
	size_t	len;

	if (ft_get_next_line(dt->file_fd, dt->map.grid[row]) != SUCCESS)
	{
		ft_put_error("ft_get_clean_row()", "get_next_line()", NULL);
		return (FAILURE);
	}
	len = ft_strlen(dt->map.grid[row]);
	if (len > 1 && dt->map.grid[row][len - 1] == '\n')
		dt->map.grid[row][len - 1] = '\0';
	return (SUCCESS);
}

t_result	ft_parse_map(t_data *dt)
{
	size_t	i;

	dt->map.player_spawn.row = -1;
	dt->map.player_spawn.col = -1;
	i = 0;
	if (ft_get_clean_row(dt, i) != SUCCESS)
		return (FAILURE);
	while (dt->map.grid[i++][0])
	{
		if (ft_get_clean_row(dt, i) != SUCCESS)
			return (FAILURE);
	}
	dt->map.row_count = i;
	if (ft_validate_map_content(&dt->map) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

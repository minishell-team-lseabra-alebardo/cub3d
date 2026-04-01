/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:12:26 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/27 20:51:51 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_result	ft_get_clean_map_row(t_data *dt, size_t row)
{
	char	line[MAX_LINE_SIZE];
	size_t	i;

	if (ft_get_next_line(dt->file_fd, line) != SUCCESS)
		return (FAILURE);
	if (line[0] && row >= MAX_MAP_ROWS)
		return (ft_p_err_ret(NULL, NULL, ERR_MAP_ROWS));
	i = 0;
	while (line[i])
	{
		if (i >= MAX_MAP_COLS)
			return (ft_p_err_ret(NULL, NULL, ERR_MAP_COLS));
		if (line[i] == '\n' && i > 0)
			break ;
		dt->map.grid[row][i] = line[i];
		i++;
	}
	dt->map.grid[row][i] = '\0';
	return (SUCCESS);
}

t_result	ft_parse_map(t_data *dt)
{
	size_t	row;

	dt->map.player_spawn.row = -1;
	dt->map.player_spawn.col = -1;
	row = 0;
	if (ft_get_clean_map_row(dt, row) != SUCCESS)
		return (FAILURE);
	while (dt->map.grid[row++][0])
	{
		if (ft_get_clean_map_row(dt, row) != SUCCESS)
			return (FAILURE);
	}
	dt->map.row_count = row;
	if (ft_validate_map_content(&dt->map) != SUCCESS)
		return (FAILURE);
	else if (ft_validate_map_boundaries(dt->map) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

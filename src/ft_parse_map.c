/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:12:26 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/27 18:32:29 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_result	ft_get_clean_row(t_data *dt, size_t row)
{
	size_t	len;

	if (ft_get_next_line(dt->file_fd, dt->map.grid[row]) != SUCCESS)
		return (FAILURE);
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
	else if (ft_validate_map_boundaries(dt->map) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:12:26 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/24 21:06:14 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>

static void	ft_print_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->row_count)
	{
		printf("%s", map->grid[i]);
		i++;
	}
}

t_result	ft_parse_map(t_data *dt)
{
	size_t	i;

	i = 0;
	if (ft_get_next_line(dt->file_fd, dt->map.grid[i]) != SUCCESS)
	{
		ft_put_error("ft_parse_map()", "get_next_line()", NULL);
		return (FAILURE);
	}
	while (dt->map.grid[i++][0])
	{
		if (ft_get_next_line(dt->file_fd, dt->map.grid[i]) != SUCCESS)
		{
			ft_put_error("ft_parse_map()", "get_next_line()", NULL);
			return (FAILURE);
		}
	}
	dt->map.row_count = i;
	ft_print_map(&dt->map);
	return (SUCCESS);
}

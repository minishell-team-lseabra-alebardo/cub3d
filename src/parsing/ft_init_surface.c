/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_surface.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:15:23 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/23 14:32:27 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <errno.h>

static t_surface_id	ft_get_surface_id(char *buffer)
{
	if (ft_strncmp(buffer, CEILING, ft_strlen(CEILING)) == 0
		&& buffer[ft_strlen(CEILING)] == ' ')
	{
		return (C);
	}
	else if (ft_strncmp(buffer, FLOOR, ft_strlen(FLOOR)) == 0
		&& buffer[ft_strlen(FLOOR)] == ' ')
	{
		return (F);
	}
	else
	{
		return (C);
	}
}

char	*ft_get_surface_str(t_surface_id id)
{
	if (id == C)
		return (CEILING);
	else if (id == F)
		return (FLOOR);
	else
		return (NULL);
}

t_result	ft_init_surface(t_data *dt, char *buffer)
{
	t_surface_id	id;
	int				i;

	id = ft_get_surface_id(buffer);
	if (dt->surfaces[id].initialized == TRUE)
	{
		ft_put_error(NULL, ft_get_surface_str(id), ERR_DUP_ID);
		return (FAILURE);
	}
	dt->surfaces[id].id = id;
	buffer += ft_calc_id_spaces_jump(buffer);
	if (*buffer == '\0' || *buffer == '\n')
	{
		ft_put_error(NULL, ft_get_surface_str(id), ERR_MISS_RGB_ARG);
		return (FAILURE);
	}
	i = -1;
	while (buffer[++i] && buffer[i] != '\n' && buffer[i] != '\0')
		dt->surfaces[id].rgb_str[i] = buffer[i];
	if (ft_parse_rgb(&dt->surfaces[id]) != SUCCESS)
		return (FAILURE);
	dt->surfaces[id].initialized = TRUE;
	return (SUCCESS);
}

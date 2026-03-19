/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:15:23 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/19 19:19:45 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture_id	ft_get_texture_id(char	*buffer)
{
	if (ft_strncmp(buffer, NORTH, ft_strlen(NORTH)) == 0
		&& buffer[ft_strlen(NORTH)] == ' ')
	{
		return (NO);
	}
	else if (ft_strncmp(buffer, SOUTH, ft_strlen(SOUTH)) == 0
		&& buffer[ft_strlen(SOUTH)] == ' ')
	{
		return (SO);
	}
	else if (ft_strncmp(buffer, WEST, ft_strlen(WEST)) == 0
		&& buffer[ft_strlen(WEST)] == ' ')
	{
		return (WE);
	}
	else if (ft_strncmp(buffer, EAST, ft_strlen(EAST)) == 0
		&& buffer[ft_strlen(EAST)] == ' ')
	{
		return (EA);
	}
	else
	{
		return (NO);
	}
}

static char	*ft_get_texture_str(t_texture_id id)
{
	if (id == NO)
		return (NORTH);
	else if (id == SO)
		return (SOUTH);
	else if (id == WE)
		return (WEST);
	else if (id == EA)
		return (EAST);
	else
		return (NULL);
}

t_result	ft_init_texture(t_data *dt, char *buffer)
{
	t_texture_id	id;
	size_t			i;

	id = ft_get_texture_id(buffer);
	if (dt->textures[id].initialized == TRUE)
	{
		ft_put_error(NULL, ft_get_texture_str(id), ERR_DUP_ID);
		return (FAILURE);
	}
	dt->textures[id].id = id;
	while (*buffer && *buffer != '\n' && *buffer != ' ')
		buffer++;
	if (*buffer == '\0' || *buffer == '\n')
	{
		ft_put_error(NULL, ft_get_texture_str(id), ERR_MISS_FILENAME);
		return (FAILURE);
	}
	while (*buffer == ' ')
		buffer++;
	i = -1;
	while (buffer[++i] && buffer[i] != '\n' && buffer[i] != '\0')
		dt->textures[id].filename[i] = buffer[i];
	dt->textures[id].initialized = TRUE;
	return (SUCCESS);
}

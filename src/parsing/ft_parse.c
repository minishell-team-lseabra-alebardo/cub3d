/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:18:59 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/01 22:39:37 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_is_texture(char *buffer)
{
	if (ft_strncmp(buffer, NORTH, ft_strlen(NORTH)) == 0
		&& buffer[ft_strlen(NORTH)] == ' ')
	{
		return (TRUE);
	}
	else if (ft_strncmp(buffer, SOUTH, ft_strlen(SOUTH)) == 0
		&& buffer[ft_strlen(SOUTH)] == ' ')
	{
		return (TRUE);
	}
	else if (ft_strncmp(buffer, WEST, ft_strlen(WEST)) == 0
		&& buffer[ft_strlen(WEST)] == ' ')
	{
		return (TRUE);
	}
	else if (ft_strncmp(buffer, EAST, ft_strlen(EAST)) == 0
		&& buffer[ft_strlen(EAST)] == ' ')
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

t_bool	ft_is_surface(char *buffer)
{
	if (ft_strncmp(buffer, FLOOR, ft_strlen(FLOOR)) == 0
		&& buffer[ft_strlen(FLOOR)] == ' ')
	{
		return (TRUE);
	}
	else if (ft_strncmp(buffer, CEILING, ft_strlen(CEILING)) == 0
		&& buffer[ft_strlen(CEILING)] == ' ')
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

static t_result	ft_handle_inv_id(char *buffer)
{
	int		i;
	char	*id;

	if (!buffer)
		return (FAILURE);
	if (buffer[0] == ' ')
	{
		ft_put_error(NULL, "' '", ERR_INV_ID);
		return (FAILURE);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n' && buffer[i] != ' ')
		i++;
	id = malloc((i + 1) * sizeof(char));
	if (!id)
	{
		ft_put_error("ft_handle_inv_id()", "malloc", strerror(errno));
		return (FAILURE);
	}
	id[i] = '\0';
	while (--i >= 0)
		id[i] = buffer[i];
	ft_put_error(NULL, id, ERR_INV_ID);
	free(id);
	return (FAILURE);
}

t_result	ft_parse_information(t_data *dt, char *buffer)
{
	if (ft_get_next_line(dt->file_fd, buffer) != SUCCESS)
		return (FAILURE);
	while (buffer && buffer[0] == '\n')
	{
		if (ft_get_next_line(dt->file_fd, buffer) != SUCCESS)
			return (FAILURE);
	}
	if (ft_is_texture(buffer) == TRUE)
		return (ft_init_texture(dt, buffer));
	else if (ft_is_surface(buffer) == TRUE)
		return (ft_init_surface(dt, buffer));
	else
		return (ft_handle_inv_id(buffer));
}

t_result	ft_parse(t_data *dt, char *filename)
{
	int		i;
	char	buffer[MAX_LINE_SIZE];

	dt->file_fd = open(filename, O_RDONLY);
	if (dt->file_fd < 0)
	{
		ft_put_error("ft_parse()", filename, strerror(errno));
		return (FAILURE);
	}
	i = 0;
	while (i < 6)
	{
		if (ft_parse_information(dt, buffer) != SUCCESS)
			return (FAILURE);
		i++;
	}
	if (ft_parse_map(dt) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

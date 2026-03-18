/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:18:59 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/18 17:47:27 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

static t_bool	ft_is_texture(char *buffer)
{
	size_t	len;

	len = ft_strlen(NORTH);
	if (ft_strncmp(buffer, NORTH, len) == 0 && buffer[len] == ' ')
		return (TRUE);
	else if (ft_strncmp(buffer, SOUTH, ft_strlen(SOUTH)) == 0
		&& buffer[2] == ' ')
		return (TRUE);
	else if (ft_strncmp(buffer, WEST, ft_strlen(WEST)) == 0
		&& buffer[2] == ' ')
		return (TRUE);
	else if (ft_strncmp(buffer, EAST, ft_strlen(EAST)) == 0
		&& buffer[2] == ' ')
		return (TRUE);
	else
		return (FALSE);
}

static t_bool	ft_is_surface(char *buffer)
{
	if (ft_strncmp(buffer, FLOOR, ft_strlen(FLOOR)) == 0
		&& buffer[2] == ' ')
	{
		return (TRUE);
	}
	else if (ft_strncmp(buffer, CEILING, ft_strlen(CEILING)) == 0
		&& buffer[2] == ' ')
	{
		return (TRUE);
	}
	else
		return (FALSE);
}

t_result	ft_parse_information(t_data *dt, t_fd fd, char *buffer)
{
	if (ft_get_next_line(fd, buffer) != SUCCESS)
	{
		ft_put_error("ft_parse_information()", NULL, NULL);
		return (FAILURE);
	}
	while (buffer && buffer[0] == '\n')
	{
		if (ft_get_next_line(fd, buffer) != SUCCESS)
		{
			ft_put_error("ft_parse_information()", NULL, NULL);
			return (FAILURE);
		}
	}
	if (ft_is_texture(buffer) == TRUE)
		return (ft_init_texture(dt, buffer));
	else if (ft_is_surface(buffer) == TRUE)
		return (ft_init_surface(dt, buffer));
	else
	{
		ft_put_error(NULL, buffer, ERR_INV_ID);
		return (FAILURE);
	}
}

t_result	ft_parse(t_data *dt, char *filename)
{
	int		i;
	t_fd	fd;
	char	buffer[MAX_LINE_SIZE + 1];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_put_error("ft_parse()", filename, strerror(errno));
		return (FAILURE);
	}
	i = 0;
	while (i < 6)
	{
		if (ft_parse_information(dt, fd, buffer) != SUCCESS)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

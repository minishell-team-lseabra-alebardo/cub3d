/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:00:06 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/24 21:15:21 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static t_result	ft_validate_fd(int fd)
{
	if (fd < 0 || fd > 1024)
	{
		ft_put_error("ft_get_next_line()", NULL, ERR_FD_RANGE);
		return (FAILURE);
	}
	else
		return (SUCCESS);
}

t_result	ft_get_next_line(int fd, char line[MAX_LINE_SIZE])
{
	static char	buffer[BUFFER_SIZE];
	static int	buf_pos;
	static int	buf_len;
	int			line_pos;

	if (ft_validate_fd(fd) != SUCCESS)
		return (FAILURE);
	line_pos = 0;
	while (TRUE)
	{
		if (buf_pos >= buf_len)
		{
			buf_pos = 0;
			buf_len = read(fd, buffer, BUFFER_SIZE - 1);
			if (buf_len < 0)
				return (FAILURE);
			else if (buf_len == 0)
				break ;
		}
		line[line_pos++] = buffer[buf_pos++];
		if (line[line_pos - 1] == '\n' || line_pos >= MAX_LINE_SIZE - 1)
			break ;
	}
	line[line_pos] = '\0';
	return (SUCCESS);
}

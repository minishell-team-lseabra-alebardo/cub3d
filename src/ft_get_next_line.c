/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:00:06 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/26 16:47:38 by lseabra-         ###   ########.fr       */
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
	static t_gnl_state	s;
	int					line_pos;

	if (ft_validate_fd(fd) != SUCCESS)
		return (FAILURE);
	line_pos = 0;
	while (TRUE)
	{
		if (s.buf_pos >= s.buf_len)
		{
			s.buf_pos = 0;
			s.buf_len = read(fd, s.buffer, BUFFER_SIZE - 1);
			if (s.buf_len < 0)
				return (FAILURE);
			else if (s.buf_len == 0)
				break ;
		}
		line[line_pos++] = s.buffer[s.buf_pos++];
		if (line[line_pos - 1] == '\n')
			break ;
		else if (line_pos > MAX_LINE_SIZE)
			return (ft_p_err_ret(NULL, NULL, ERR_LINE_SIZE));
	}
	line[line_pos] = '\0';
	return (SUCCESS);
}

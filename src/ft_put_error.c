/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:08:22 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/18 15:54:19 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

static void	ft_put_str_fd(int fd, char *str)
{
	size_t	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	if (write(fd, str, len) == FAILURE)
		perror(NULL);
}

void	ft_put_error(char *program, char *target, char *message)
{
	ft_put_str_fd(STDERR_FILENO, ERR_PREFIX);
	if (program)
	{
		ft_put_str_fd(STDERR_FILENO, ERR_SEP);
		ft_put_str_fd(STDERR_FILENO, program);
	}
	if (target)
	{
		ft_put_str_fd(STDERR_FILENO, ERR_SEP);
		ft_put_str_fd(STDERR_FILENO, target);
	}
	if (message)
	{
		ft_put_str_fd(STDERR_FILENO, ERR_SEP);
		ft_put_str_fd(STDERR_FILENO, message);
	}
	write(STDERR_FILENO, "\n", 1);
}

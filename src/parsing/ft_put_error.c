/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:08:22 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/01 22:40:06 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_put_str_fd(int fd, char *str)
{
	size_t	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	if (write(fd, str, len) == FAILURE)
		perror(NULL);
}

void	ft_put_error(char *pgm, char *tgt, char *msg)
{
	ft_put_str_fd(STDERR_FILENO, ERR_PREFIX);
	if (pgm)
	{
		ft_put_str_fd(STDERR_FILENO, ERR_SEP);
		ft_put_str_fd(STDERR_FILENO, pgm);
	}
	if (tgt)
	{
		ft_put_str_fd(STDERR_FILENO, ERR_SEP);
		ft_put_str_fd(STDERR_FILENO, tgt);
	}
	if (msg)
	{
		ft_put_str_fd(STDERR_FILENO, ERR_SEP);
		ft_put_str_fd(STDERR_FILENO, msg);
	}
	write(STDERR_FILENO, "\n", 1);
}

int	ft_p_err_ret(char *pgm, char *tgt, char *msg)
{
	ft_put_error(pgm, tgt, msg);
	return (FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:21:38 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/02 22:03:04 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_result	ft_validate_macros(void)
{
	if (BUFFER_SIZE <= 0)
	{
		ft_put_error(NULL, NULL, ERR_BUFFER_SIZE);
		return (FAILURE);
	}
	else if (MAX_LINE_SIZE <= 0)
	{
		ft_put_error(NULL, NULL, ERR_MAX_LINE_SIZE);
		return (FAILURE);
	}
	else
		return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_data		dt;

	dt = (t_data){};
	if (ft_validate_macros() != SUCCESS
		|| ft_validate_arg(argc, argv) != SUCCESS
		|| ft_parse(&dt, argv[1]) != SUCCESS)
	{
		return (EXIT_FAILURE);
	}
	//TEST FOR RGB VALUES OF FLOOR AND CEILING
	printf("%d %d %d\n", dt.surfaces[F].rgb.r, dt.surfaces[F].rgb.g, dt.surfaces[F].rgb.b);
	printf("%d %d %d\n", dt.surfaces[C].rgb.r, dt.surfaces[C].rgb.g, dt.surfaces[C].rgb.b);
	//////////////////////////////////////////
	if (ft_open_window(&dt) != SUCCESS)
		return (EXIT_FAILURE);
	ft_game_loop(&dt);
	return (EXIT_SUCCESS);
}

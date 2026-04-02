/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 20:31:39 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/02 21:59:11 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_draw_pixel(t_img *img, int x, int y, int color)
{
	int		offset;
	char	*allign;

	if (y < 0 || y > WIN_HEIGHT || x < 0 || x > WIN_WIDTH)
		return ;
	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	if (offset < 0)
		return ;
	allign = img->addr + offset;
	*(unsigned int *)allign = color;
}

static void ft_draw_floor(t_data *dt)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT / 2)
		{
			ft_draw_pixel(&dt->graphics.floor, i, j,
				dt->surfaces[F].rgb.r << 16 |
				dt->surfaces[F].rgb.g << 8 |
				dt->surfaces[F].rgb.b);
			j++;
		}
		i++;
	}
}

static void ft_draw_ceiling(t_data *dt)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT / 2)
		{
			ft_draw_pixel(&dt->graphics.ceiling, i, j,
				dt->surfaces[C].rgb.r << 16 |
				dt->surfaces[C].rgb.g << 8 |
				dt->surfaces[C].rgb.b);
			j++;
		}
		i++;
	}
}

void	ft_floor_img(t_data *dt)
{
	if (!dt)
		ft_close_program(dt);
	if (!dt->graphics.floor.img)
	{
		dt->graphics.floor.img =
			mlx_new_image(dt->graphics.mlx, WIN_WIDTH, WIN_HEIGHT / 2);
		if (!dt->graphics.floor.img)
		{
			//PRINT ERROR MESSAGE
			ft_close_program(dt);
		}
		dt->graphics.floor.addr = mlx_get_data_addr(
			dt->graphics.floor.img, &dt->graphics.floor.bits_per_pixel,
			&dt->graphics.floor.line_length, &dt->graphics.floor.endian);
		ft_draw_floor(dt);
	}
	mlx_put_image_to_window(dt->graphics.mlx,
		dt->graphics.window,
		dt->graphics.floor.img,
		0, WIN_HEIGHT / 2);
}

void	ft_ceiling_img(t_data *dt)
{
	if (!dt)
		ft_close_program(dt);
	if (!dt->graphics.ceiling.img)
	{
		dt->graphics.ceiling.img =
			mlx_new_image(dt->graphics.mlx, WIN_WIDTH, WIN_HEIGHT / 2);
		if (!dt->graphics.ceiling.img)
		{
			//PRINT ERROR MESSAGE
			ft_close_program(dt);
		}
		dt->graphics.ceiling.addr = mlx_get_data_addr(
			dt->graphics.ceiling.img, &dt->graphics.ceiling.bits_per_pixel,
			&dt->graphics.ceiling.line_length, &dt->graphics.ceiling.endian);
		ft_draw_ceiling(dt);
	}
	mlx_put_image_to_window(dt->graphics.mlx,
		dt->graphics.window,
		dt->graphics.ceiling.img,
		0, 0);
}

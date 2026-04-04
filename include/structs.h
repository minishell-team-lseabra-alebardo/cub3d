/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:06:19 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/04 19:02:58 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "enums.h"

typedef int				t_fd;
typedef unsigned char	t_u_char;

typedef struct s_texture
{
	t_bool			initialized;
	t_texture_id	id;
	char			filename[MAX_LINE_SIZE];
	t_fd			fd;
}	t_texture;

typedef struct s_rgb
{
	t_u_char	r;
	t_u_char	g;
	t_u_char	b;
}	t_rgb;

typedef struct s_surface
{
	t_bool			initialized;
	t_surface_id	id;
	char			rgb_str[MAX_LINE_SIZE];
	t_rgb			rgb;
}	t_surface;

typedef struct s_spawn
{
	int		row;
	int		col;
	char	direction;
}	t_spawn;

typedef struct s_map
{
	char		grid[MAX_MAP_ROWS][MAX_MAP_COLS];
	t_spawn		player_spawn;
	int			row_count;
	int			max_line_len;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_graphics
{
	void	*mlx;
	void	*window;
	t_img	floor;
	t_img	ceiling;
}	t_graphics;

typedef struct s_data
{
	t_fd		file_fd;
	t_texture	textures[4];
	t_surface	surfaces[2];
	t_map		map;
	t_graphics	graphics;
}	t_data;

typedef struct s_gnl_state
{
	char	buffer[BUFFER_SIZE];
	int		buf_pos;
	int		buf_len;
}	t_gnl_state;

#endif
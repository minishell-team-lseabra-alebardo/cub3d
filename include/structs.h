/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:06:19 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/18 17:33:07 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "enums.h"
# include <sys/types.h>

typedef int	t_fd;

typedef struct s_texture
{
	t_texture_id	id;
	char			*filename;
	t_fd			fd;
}	t_texture;

typedef struct s_rgb
{
	u_char	r;
	u_char	g;
	u_char	b;
}	t_rgb;

typedef struct s_surface
{
	t_surface_id	*id;
	char			*rgb_str;
	t_rgb			rgb;
}	t_surface;

typedef struct s_map
{
}	t_map;

typedef struct s_data
{
	t_texture	textures[4];
	t_surface	surfaces[2];
	t_map		map;
}	t_data;

#endif
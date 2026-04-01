/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:23:52 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/01 23:54:00 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "enums.h"
# include "macros.h"
# include "structs.h"

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <string.h>
# include <math.h>
# include <mlx.h>

t_result	ft_get_next_line(int fd, char line[MAX_LINE_SIZE]);
char		*ft_get_surface_str(t_surface_id id);
t_result	ft_init_surface(t_data *dt, char *buffer);
t_bool		ft_is_space(char c);
size_t		ft_calc_id_spaces_jump(char *str);
t_result	ft_init_texture(t_data *dt, char *buffer);
t_bool		ft_is_texture(char *buffer);
t_bool		ft_is_surface(char *buffer);
t_result	ft_parse_map(t_data *dt);
t_result	ft_parse_rgb(t_surface *surface);
t_result	ft_parse(t_data *dt, char *filename);
void		ft_put_error(char *pgm, char *tgt, char *msg);
int			ft_p_err_ret(char *pgm, char *tgt, char *msg);
t_result	ft_validate_arg(int argc, char *argv[]);
t_result	ft_validate_map_boundaries(t_map map);
t_result	ft_validate_map_content(t_map *map);
size_t		ft_strlen(char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_open_window(t_graphics *graphics);
int			ft_close_program(t_graphics *graphics);
void		ft_game_loop(t_data *dt, t_graphics *graphics);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:23:52 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/19 12:07:04 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "enums.h"
# include "macros.h"
# include "structs.h"

# include <stddef.h>

t_result	ft_get_next_line(int fd, char line[MAX_LINE_SIZE + 1]);
t_result	ft_init_surface(t_data *dt, char *buffer);
t_result	ft_init_texture(t_data *dt, char *buffer);
t_bool		ft_is_texture(char *buffer);
t_bool		ft_is_surface(char *buffer);
t_result	ft_parse(t_data *dt, char *filename);
void		ft_put_error(char *program, char *target, char *message);
t_result	ft_validate_arg(int argc, char *argv[]);
size_t		ft_strlen(char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
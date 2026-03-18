/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:00:50 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/18 17:13:32 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// ft_get_next_line.c
# define MAX_LINE_SIZE	100000
# define BUFFER_SIZE	100

# define EXTENSION	".cub"

// Directions
# define NORTH	"NO"
# define SOUTH	"SO"
# define WEST	"WE"
# define EAST	"EA"

// Surfaces
# define FLOOR "F"
# define CEILING "C"

// Errors
# define ERR_PREFIX			"Error"
# define ERR_SEP			": "
# define ERR_FD_RANGE		"file descriptor must be between 0 and 1024"
# define ERR_BUFFER_SIZE	"BUFFER_SIZE should be greater than 0"
# define ERR_MAX_LINE_SIZE	"MAX_LINE_SIZE should be greater than 0"
# define ERR_MISS_ARG		"missing argument: '*.cub' file"
# define ERR_MISS_ARG		"missing argument: '*.cub' file"
# define ERR_MANY_ARGS		"exactly one argument is required"
# define ERR_INV_EXT		"file extension must be '.cub'"
# define ERR_NO_FILENAME	"filename not passed"
# define ERR_MISS_PARAM		"missing parameter"
# define ERR_INV_ID			"invalid information identifier"

#endif
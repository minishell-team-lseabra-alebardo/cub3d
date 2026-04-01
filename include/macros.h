/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:00:50 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/27 20:29:13 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// ft_get_next_line.c
# define MAX_MAP_ROWS	128
# define MAX_MAP_COLS	128
# define MAX_LINE_SIZE	512
# define BUFFER_SIZE	128

# define EXTENSION	".cub"

// Textures
# define NORTH	"NO"
# define SOUTH	"SO"
# define WEST	"WE"
# define EAST	"EA"

// Surfaces
# define FLOOR		"F"
# define CEILING	"C"

// Map
# define DIRECTIONS	"NSEW"
# define MAP_TILES	"01"

// Errors
# define ERR_PREFIX			"Error"
# define ERR_SEP			": "
# define ERR_FD_RANGE		"file descriptor must be between 0 and 1024"
# define ERR_BUFFER_SIZE	"BUFFER_SIZE should be greater than 0"
# define ERR_MAX_LINE_SIZE	"MAX_LINE_SIZE should be greater than 0"
# define ERR_LINE_SIZE		"input line exceeds MAX_LINE_SIZE"
# define ERR_MAP_COLS		"input map exceeds columns limit (MAX_MAP_COLS - 1)"
# define ERR_MAP_ROWS		"input map exceeds rows limit (MAX_MAP_ROWS - 1)"
# define ERR_MISS_ARG_FILE	"missing argument: '*.cub' file"
# define ERR_MANY_ARGS		"exactly one argument is required"
# define ERR_INV_EXT		"file extension must be '.cub'"
# define ERR_NO_FILENAME	"filename not passed"
# define ERR_MISS_PARAM		"missing parameter"
# define ERR_INV_ID			"invalid information identifier"
# define ERR_NOT_TEXTURE	"argument is not a texture"
# define ERR_DUP_ID			"duplicated identifier"
# define ERR_MISS_FILENAME	"missing filename"
# define ERR_MISS_RGB_ARG	"RGB not passed"
# define ERR_MISS_RGB_COMP	"missing RGB component"
# define ERR_INV_RGB		"invalid RGB. Usage: '(0–255),(0–255),(0–255)'"
# define ERR_MULT_SPAWN		"multiple player spawns detected"
# define ERR_NO_SPAWN		"no spawn detected"
# define ERR_INV_C			"invalid character detected"
# define ERR_MAP_OPEN		"map has invalid or unreachable areas"

#endif
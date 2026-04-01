/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:05:37 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/25 11:30:06 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_result
{
	FAILURE = -1,
	SUCCESS = 0
}	t_result;

typedef enum e_texture_id
{
	NO,
	SO,
	EA,
	WE
}	t_texture_id;

typedef enum e_surface_id
{
	F,
	C
}	t_surface_id;

#endif
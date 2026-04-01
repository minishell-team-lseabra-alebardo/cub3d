/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:29:46 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/26 13:32:02 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	ft_is_digit(char character)
{
	if (character >= '0' && character <= '9')
		return (TRUE);
	else
		return (FALSE);
}

static t_result	ft_atouc_rgb(t_surface *surf, t_u_char *component, size_t *i)
{
	int		res;

	if (!surf || !component || !i)
		return (ft_p_err_ret("ft_atouc_rgb()", NULL, ERR_MISS_PARAM));
	else if (surf->rgb_str[*i] == '\0')
		return (ft_p_err_ret(NULL, ERR_MISS_PARAM, ERR_MISS_RGB_COMP));
	else if (surf->rgb_str[*i] == '-')
		return (ft_p_err_ret(NULL, surf->rgb_str, ERR_INV_RGB));
	else if (surf->rgb_str[*i] == '+')
		(*i)++;
	res = 0;
	while (surf->rgb_str[*i] && ft_is_digit(surf->rgb_str[*i]) == TRUE)
	{
		res = (res * 10) + (surf->rgb_str[*i] - '0');
		if (res > 255)
			return (ft_p_err_ret(NULL, surf->rgb_str, ERR_INV_RGB));
		(*i)++;
	}
	if (surf->rgb_str[*i] != ',' && surf->rgb_str[*i] != '\0')
		return (ft_p_err_ret(NULL, surf->rgb_str, ERR_INV_RGB));
	*component = (t_u_char)(res);
	return (SUCCESS);
}

t_result	ft_parse_rgb(t_surface *surface)
{
	size_t		i;

	if (!surface)
	{
		ft_put_error("ft_parse_rgb()", NULL, ERR_MISS_PARAM);
		return (FAILURE);
	}
	i = 0;
	if (ft_atouc_rgb(surface, &surface->rgb.r, &i) != SUCCESS)
		return (FAILURE);
	if (ft_atouc_rgb(surface, &surface->rgb.g, &i) != SUCCESS)
		return (FAILURE);
	if (ft_atouc_rgb(surface, &surface->rgb.b, &i) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:16:03 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/07 17:44:51 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	check_map_size_error(char **map, t_map_infos *info)
{
	t_incr	incr;

	incr.i = 0;
	while (map[incr.i] != 0)
	{
		if (info->size_line != ft_strlen(map[incr.i]))
			return (1);
		incr.i++;
	}
	if (incr.i != info->size)
		return (1);
	return (0);
}

int	is_in_charset(char c, t_map_infos *info)
{
	if (c == info->empty)
		return (1);
	if (c == info->obstacle)
		return (1);
	return (0);
}

int	check_char_in_map(char **map, t_map_infos *info)
{
	t_incr	incr;

	incr.i = 0;
	while (map[incr.i])
	{
		incr.j = 0;
		while (map[incr.i][incr.j])
		{
			if (!(is_in_charset(map[incr.i][incr.j], info)))
				return (1);
			incr.j++;
		}
		incr.i++;
	}
	return (0);
}

int	check_avalaible_charset(t_map_infos *info)
{
	if (info->empty < 32 || info->empty == 127)
		return (1);
	if (info->full < 32 || info->full == 127)
		return (1);
	if (info->obstacle < 32 || info->obstacle == 127)
		return (1);
	if (info->obstacle == info->empty || info->obstacle == info->full
		|| info->empty == info->full)
		return (1);
	return (0);
}

int	check_all_error(char **map, t_map_infos *map_info)
{
	if (check_map_size_error(map, map_info))
		return (1);
	if (check_char_in_map(map, map_info))
		return (1);
	if (check_avalaible_charset(map_info))
		return (1);
	return (0);
}

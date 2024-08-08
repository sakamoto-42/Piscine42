/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:12:07 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/07 18:23:07 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	char_to_int_cpy(char *str, int *tab, t_map_infos info)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == info.empty)
			tab[i] = 1;
		else if (str[i] == info.obstacle)
			tab[i] = 0;
		i++;
	}
	tab[i] = -2;
}

int	**init_map_tab(char **map, t_map_infos *info)
{
	int		**tab;

	tab = NULL;
	info->i = 0;
	tab = malloc(sizeof(int *) * (info->size + 1));
	if (tab == NULL)
		return (NULL);
	while (map[info->i] != 0)
	{
		tab[info->i] = malloc(sizeof(int) * (info->size_line + 1));
		char_to_int_cpy(map[info->i], tab[info->i], *info);
		info->i++;
	}
	tab[info->i] = malloc(sizeof(int) * (info->size_line + 1));
	info->j = 0;
	while (info->j <= info->size)
	{
		tab[info->i][info->j] = -2;
		info->j++;
	}
	return (tab);
}

t_map_infos	ft_get_map_infos(char *str_map)
{
	char					*str_map_infos;
	int						map_infos_len;
	unsigned long long int	nb;
	t_map_infos				map_infos;

	map_infos_len = ft_get_line_len(str_map);
	str_map_infos = malloc((map_infos_len + 1) * sizeof (char *));
	str_map_infos = ft_copy_line(str_map_infos, str_map);
	nb = 0;
	while (*str_map_infos >= '0' && *str_map_infos <= '9')
	{
		nb = nb * 10 + (*str_map_infos - '0');
		str_map_infos++;
	}
	get_map_size_line(str_map, &map_infos);
	get_map_size(str_map, &map_infos);
	map_infos.empty = *(str_map_infos++);
	map_infos.obstacle = *(str_map_infos++);
	map_infos.full = *(str_map_infos++);
	return (map_infos);
}

char	**ft_get_map(char *str_map, t_map_infos map_infos)
{
	char	**map;

	map = malloc(map_infos.size * sizeof(char *) + 1);
	if (map)
	{
		while (*str_map != '\n')
			str_map++;
		str_map++;
	}
	map_infos.i = -1;
	while (++map_infos.i < map_infos.size)
		map[map_infos.i] = malloc((map_infos.size_line + 1) * sizeof(char));
	map[map_infos.i] = NULL;
	map_infos.i = 0;
	while (map_infos.i < map_infos.size)
	{
		map[map_infos.i] = ft_copy_line(map[map_infos.i], str_map);
		while (*str_map != '\n')
			str_map++;
		str_map++;
		map_infos.i++;
	}
	return (map);
}

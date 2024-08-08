/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_solver2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:24:33 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/07 21:19:33 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	aff_map(char **map, t_map_infos *info)
{
	info->i = 0;
	while (info->i < info->size)
	{
		ft_putstr(map[info->i]);
		ft_putstr("\n");
		info->i++;
	}
}

char	**replace_full_map(int **tab, char **map, t_map_infos *info)
{
	*info = find_bigest_nbr(tab, info);
	while (info->y <= info->i)
	{
		info->x = info->j - info->nb;
		while (info->x <= info->j)
		{
			map[info->y][info->x] = info->full;
			info->x++;
		}
		info->y++;
	}
	int_free_2d(tab, info->size_line);
	return (map);
}

int	**fill_first_row_first_col(int **tab, char **map, t_map_infos *infos)
{
	infos->x = 0;
	while (infos->x < infos->size)
	{
		if (map[0][infos->x] == infos->empty)
			tab[0][infos->x] = 1;
		if (map[0][infos->x] == infos->obstacle)
			tab[0][infos->x] = 0;
		infos->x++;
	}
	infos->y = 0;
	while (infos->y < infos->size)
	{
		if (map[infos->y][0] == infos->empty)
			tab[infos->y][0] = 1;
		infos->y++;
	}
	return (tab);
}

void	ft_bsq(t_map_infos map_infos, char **map)
{
	int	**tab;

	tab = init_map_tab(map, &map_infos);
	tab = fill_first_row_first_col(tab, map, &map_infos);
	solver(tab, &map_infos);
	map_infos.i = 0;
	// while (map_infos.i <= map_infos.size)
	// {
	// 	map_infos.j = 0;
	// 	while (map_infos.j <= map_infos.size_line)
	// 	{
	// 		ft_putnbr(tab[map_infos.i][map_infos.j]);
	// 		ft_putchar(' ');
	// 		map_infos.j++;
	// 	}
	// 	ft_putchar('\n');
	// 	map_infos.i++;
	// }
	map = replace_full_map(tab, map, &map_infos);
	aff_map(map, &map_infos);
}

int	ft_init_bsq_with_args(int argc, char **argv)
{
	char		*file_name;
	char		*str;
	t_map_infos	map_infos;
	char		**map;
	int			i;

	i = 0;
	while (i < argc - 1)
	{
		file_name = argv[i + 1];
		str = file_to_str(file_name);
		if (str == NULL)
			return (0);
		map_infos = ft_get_map_infos(str);
		map = ft_get_map(str, map_infos);
		if (map == NULL)
			return (0);
		if (check_all_error(map, &map_infos))
			return (0);
		ft_bsq(map_infos, map);
		free_2d(map);
		free(str);
		i++;
	}
	return (1);
}

char	*ft_read_from_stdin(void)
{
	unsigned long long int		buffer_size;
	unsigned long long int		length;
	char						*buffer;
	char						*new_buffer;
	char						c;
	unsigned long long int		i;

	buffer_size = 1;
	length = 0;
	buffer = malloc(buffer_size * sizeof(char));
	if (buffer == NULL)
	{
		printf("Erreur d'allocation de mémoire");
		return (NULL);
	}
	//while (read(STDIN_FILENO, &c, 1) > 0 && c != '\n')
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		new_buffer = malloc((length + 1 + 1) * sizeof(char));
		if (new_buffer == NULL)
		{
			free(buffer);
			return (NULL);
		}
		i = 0;
		while (i < length)
		{
			new_buffer[i] = buffer[i];
			i++;
		}
		new_buffer[length] = c;
		new_buffer[length + 1] = '\0';
		free(buffer);
		buffer = new_buffer;
		length++;
	}
	if (length == 0)
		buffer[0] = '\0';
	return (buffer);
}

int	ft_init_bsq_with_no_args(void)
{
	char		*str;
	t_map_infos	map_infos;
	char		**map;

	str = ft_read_from_stdin();
	if (str == NULL)
		return (0);
	else
		printf("%s", str);
	map_infos = ft_get_map_infos(str);
	map = ft_get_map(str, map_infos);
	if (map == NULL)
		return (0);
	if (check_all_error(map, &map_infos))
		return (0);
	ft_bsq(map_infos, map);
	free_2d(map);
	free(str);
	return (1);
}

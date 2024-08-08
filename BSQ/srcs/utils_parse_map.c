/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:16:27 by juduchar          #+#    #+#             */
/*   Updated: 2024/08/07 18:25:01 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

t_map_infos	get_map_size(char *str_map, t_map_infos *info)
{
	info->i = 0;
	info->j = 0;
	while (str_map[info->i] != '\n')
		info->i++;
	info->i++;
	while (str_map[info->i])
	{
		if (str_map[info->i] == '\n')
			info->j++;
		info->i++;
	}
	info->j--;
	info->size = info->j;
	return (*info);
}

t_map_infos	get_map_size_line(char *str_map, t_map_infos *info)
{
	info->i = 0;
	info->j = 0;
	while (str_map[info->i] != '\n')
		info->i++;
	info->i++;
	while (str_map[info->i] != '\n')
	{
		info->i++;
		info->j++;
	}
	info->size_line = info->j;
	return (*info);
}

int	file_count_char(char *file_name)
{
	int		count;
	t_file	files;

	count = 0;
	files.file = open(file_name, O_RDONLY);
	if (files.file == -1)
		return (-1);
	files.size = 1;
	while (files.size != 0)
	{
		files.size = read(files.file, files.buff, 1);
		count++;
	}
	close(files.file);
	return (count);
}

char	*file_to_str(char *file_name)
{
	t_file	files;
	int		i;
	char	*list;

	i = 0;
	files.size = file_count_char(file_name);
	if (files.size == -1)
		return (NULL);
	list = malloc(sizeof(char) * files.size + 1);
	if (list == NULL)
		return (NULL);
	files.file = open(file_name, O_RDONLY);
	if (files.file == -1)
		return (NULL);
	files.size = 1;
	while (files.size != 0)
	{
		files.size = read(files.file, files.buff, 1);
		list[i] = *files.buff;
		i++;
	}
	list[i] = 0;
	close(files.file);
	return (list);
}

int	ft_get_line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	return (i);
}

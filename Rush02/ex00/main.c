/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdominoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:32:19 by qdominoi          #+#    #+#             */
/*   Updated: 2024/08/04 19:04:38 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_dict.h"

#include <stdio.h>

int	ft_strlen(char *nbr)
{
	int	len;

	len = 0;
	while (nbr[len])
		len++;
	return (len);
}

char	*ft_atoistr(char *str, char *nbr)
{
	char	*nbr_start;

	nbr_start = nbr;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		*nbr = *str;
		nbr++;
		str++;
	}
	*nbr = '\0';
	return (nbr_start);
}

char	*ft_allocate_str(char *str)
{
	int		count;
	char	*nbr;

	count = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		return (0);
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		count++;
		str++;
	}
	nbr = malloc(count + 1 * sizeof(char));
	if (nbr)
		return (nbr);
	return (0);
}

char	*ft_dict_to_str(char *dict_name)
{
	int		fd;
	char	*buffer;
	size_t	buffer_size;
	size_t	bytes_read;

	fd = open(dict_name, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer_size = 1024;
	buffer = malloc(buffer_size);
	if (!buffer)
	{
		close(fd);
		return (0);
	}
	while ((bytes_read = read(fd, buffer, buffer_size - 1)) > 0)
		buffer[bytes_read] = '\0';
	return (buffer);
}

// DEBUG ONLY
void	ft_show_tab(struct s_dict *par, int lines)
{
	int	i;

	i = 0;
	while (i < lines + 1)
	{
		printf("line : %d\n", i);
		printf("key_size : %d\n", par[i].key_size);
		printf("value_size : %d\n", par[i].value_size);
		printf("key_str : %s\n", par[i].key_str);
		printf("value_str : %s\n", par[i].value_str);
		printf("end : %d\n", par[i].end);
		i++;
		printf("\n");
	}
}

struct s_dict	*ft_allocate_stab_dict(char *dict_str)
{
	struct s_dict	*stab_dict;
	int				line;
	int				i;

	line = 0;
	i = 0;
	while (dict_str[i])
	{
		if (dict_str[i] == '\n' && dict_str[i + 1] != '\n')
			line++;
		i++;
	}
	stab_dict = malloc((line + 1) * sizeof(struct s_dict));
	if (stab_dict)
		return (stab_dict);
	return (0);
}

char	*ft_set_key_value_size(char *dict_str,
	struct s_dict *stab_dict, int line)
{
	int	key_chars_nbr;
	int	value_chars_nbr;

	key_chars_nbr = 0;
	value_chars_nbr = 0;
	while (*dict_str != ' ' && *dict_str != ':')
	{
		key_chars_nbr++;
		dict_str++;
	}
	dict_str++;
	while (*dict_str == ' ')
		dict_str++;
	while (*dict_str != '\n')
	{
		value_chars_nbr++;
		dict_str++;
	}
	dict_str++;
	stab_dict[line].key_size = key_chars_nbr;
	stab_dict[line].value_size = value_chars_nbr;
	return (dict_str);
}

char	*ft_set_key_value_str(char *dict_str, struct s_dict *stab_dict, int line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*dict_str != ' ' && *dict_str != ':')
	{
		stab_dict[line].key_str[i] = *dict_str;
		i++;
		dict_str++;
	}
	stab_dict[line].key_str[i] = '\0';
	dict_str++;
	while (*dict_str == ' ')
		dict_str++;
	while (*dict_str != '\n')
	{
		stab_dict[line].value_str[j] = *dict_str;
		j++;
		dict_str++;
	}
	stab_dict[line].value_str[j] = '\0';
	dict_str++;
	return (dict_str);
}

int	ft_allocate_key_value_str(struct s_dict *stab_dict, int line)
{
	int	key_size;
	int	value_size;

	key_size = stab_dict[line].key_size;
	value_size = stab_dict[line].value_size;
	stab_dict[line].key_str = malloc(key_size + 1 * sizeof(char));
	if (stab_dict[line].key_str)
	{
		stab_dict[line].value_str = malloc(value_size + 1 * sizeof(char));
		if (stab_dict[line].value_str)
			return (1);
		else
		{
			free (stab_dict[line].value_str);
			return (0);
		}
	}
	else
		return (0);
}

struct s_dict	*ft_parse_dict(char *dict_str)
{
	int				line;
	struct s_dict	*stab_dict;
	char			*dict_str_start;

	stab_dict = ft_allocate_stab_dict(dict_str);
	if (stab_dict)
	{
		line = 0;
		dict_str_start = dict_str;
		while (dict_str[line])
		{
			dict_str = ft_set_key_value_size(dict_str, stab_dict, line);
			ft_allocate_key_value_str(stab_dict, line);
			line++;
		}
		line = 0;
		dict_str = dict_str_start;
		while (dict_str[line])
		{
			dict_str = ft_set_key_value_str(dict_str, stab_dict, line);
			line++;
		}
		stab_dict[line].end = 1;
		//ft_show_tab(stab_dict, line);
		return (stab_dict);
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_search(char *str, struct s_dict *stab_dict)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;

	if (len == 1)
	{
		while (stab_dict[i].end != 1)
		{
			if (str[0] == stab_dict[i].key_str[0] && stab_dict[i].key_size == 1)
			{
				ft_putstr(stab_dict[i].value_str);
				break;
			}
			i++;
		}
	}
	else if (len == 2)
	{
		if (str[0] == '1')
		{
			while (stab_dict[i].end != -1)
			{
				if (str[0] == stab_dict[i].key_str[0] && str[1] == stab_dict[i].key_str[1] && stab_dict[i].key_size == 2)
				{
					ft_putstr(stab_dict[i].value_str);
					break;
				}
				i++;
			}
		}
		else
		{
			while (stab_dict[i].end != -1)
			{
				if (str[0] == stab_dict[i].key_str[0] && stab_dict[i].key_str[1] == '0' && stab_dict[i].key_size == 2)
					ft_putstr(stab_dict[i].value_str);
				if (str[1] != '0')
				{
					i = 0;
					while (stab_dict[i].end != -1)
					{
						if (str[1] == stab_dict[i].key_str[1] && stab_dict[i].key_size == 1)
						{
							write(1, "-", 1);
							ft_putstr(stab_dict[i].value_str);
						}
						i++;
					}
				}
				i++;
			}
		}
	}


		/*
		if (len == stab_dict[i].key_size)
		{
			if (str[0] == stab_dict[i].key_str[0])
		}
		i++;
	}*/
}

int	main(int argc, char **argv)
{
	char	*nbr;
	char	*str;
	char	*dict_name;
	char	*dict_str;
	struct s_dict	*stab_dict;

	if (argc - 1 == 1 || argc - 1 == 2)
	{
		if (argc - 1 == 1)
		{
			dict_name = "numbers.dict";
			str = argv[1];
		}
		else if (argc - 1 == 2)
		{
			dict_name = argv[1];
			str = argv[2];
		}
		nbr = ft_allocate_str(str);
		if (!nbr)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		else
		{
			ft_atoistr(str, nbr);
			dict_str = ft_dict_to_str(dict_name);
			if (!dict_str)
				write(2, "Dict Error\n", 11);
			else
			{
				stab_dict = ft_parse_dict(dict_str);
				if (!stab_dict)
					write(2, "Dict Error\n", 11);
				else
				{
					ft_search(str, stab_dict);
					free(dict_str);
				}
			}
		}
	}
	return (0);
}

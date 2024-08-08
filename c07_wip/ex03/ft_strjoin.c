/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:09:29 by juduchar          #+#    #+#             */
/*   Updated: 2024/08/05 13:50:38 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_strs_len(char **strs, int size)
{
	int	i;
	int	j;
	int	strs_len;

	i = 0;
	strs_len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			strs_len++;
			j++;
		}
		i++;
	}
	return (strs_len);
}

int	ft_sep_len(char	*sep)
{
	int	sep_len;

	sep_len = 0;
	while (sep[sep_len])
		sep_len++;
	return (sep_len);
}

char	*ft_allocate_joined_str(int size, char **strs, char *sep)
{
	int		strs_len;
	int		sep_len;
	int		total_len;
	char	*joined_str;

	strs_len = ft_strs_len(strs, size);
	sep_len = ft_sep_len(sep);
	total_len = strs_len + ((size - 1) * sep_len) + 1;
	joined_str = malloc (total_len * sizeof(char));
	if (joined_str)
		return (joined_str);
	return (NULL);
}

char	*ft_join_strs_with_sep(int nb_str, char **strs,
	char *sep, char *joined_str)
{
	int		i_str;
	int		i_sep;
	char	*joined_str_start;

	joined_str_start = joined_str;
	i_str = 0;
	while (i_str < nb_str)
	{
		while (*strs[i_str])
		{
			*joined_str = *strs[i_str];
			joined_str++;
			strs[i_str]++;
		}
		i_sep = 0;
		while (sep[i_sep] && i_str < nb_str - 1)
		{
			*joined_str = sep[i_sep];
			joined_str++;
			i_sep++;
		}
		i_str++;
	}
	*joined_str = '\0';
	return (joined_str_start);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined_str;

	if (size == 0)
	{
		joined_str = malloc(sizeof(char));
		if (joined_str)
		{
			*joined_str = '\0';
			return (joined_str);
		}
		return (NULL);
	}
	joined_str = ft_allocate_joined_str(size, strs, sep);
	if (joined_str)
	{
		ft_join_strs_with_sep(size, strs, sep, joined_str);
		return (joined_str);
	}
	return (NULL);
}
/*
int	main(void)
{
	int		strs_size;
	char	*sep;
	char	*joined_str;
	char	**strs;

	strs = malloc(3 * sizeof(char *));
	*strs = malloc((1 + 1) * sizeof(char));
	strs[0] = "a";
	strs[1] = "bb";
	strs[2] = "ccc";
	sep = "---";
	strs_size = 3;
	joined_str = ft_strjoin(strs_size, strs, sep);
	printf("%s", joined_str);
	return (0);
}
*/

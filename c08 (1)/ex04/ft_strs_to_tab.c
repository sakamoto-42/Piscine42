/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:08:36 by juduchar          #+#    #+#             */
/*   Updated: 2024/08/08 17:50:48 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

void	ft_show_tab(struct s_stock_str *par);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*stab;
	int					i;

	stab = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (stab)
	{
		i = 0;
		while (i < ac)
		{
			stab[i].size = ft_strlen(av[i]);
			stab[i].str = av[i];
			stab[i].copy = malloc((stab[i].size + 1) * sizeof(char));
			if (stab[i].copy)
				ft_strcpy(stab[i].copy, stab[i].str);
			else
				stab[i].copy = NULL;
			i++;
		}
		stab[i].str = NULL;
		return (stab);
	}
	return (NULL);
}

int	main(void)
{
	char				*strs[] = {"abcdaaaaaaaaaaaaaaaaa", "bb", "ccc"};
	int					strs_size;
	struct s_stock_str	*stab;

	strs_size = sizeof(strs) / sizeof(*strs);
	stab = ft_strs_to_tab(strs_size, strs);
	ft_show_tab(stab);
}

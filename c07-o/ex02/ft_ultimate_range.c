/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:35:47 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/31 14:53:57 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = malloc(size * sizeof(**range));
	if (*range)
	{
		i = 0;
		while (i < size)
		{
			(*range)[i] = min;
			i++;
			min++;
		}
		return (size);
	}
	return (-1);
}


void	ft_print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d", tab[i]);
		if (i < size - 1)
			printf(" ");
		i++;
	}
}

int	main(void)
{
	int	min;
	int	max;
	int	*tab;
	int	tab_size;

	min = 5;
	max = 15;
	tab_size = ft_range(&tab, min, max);
	if (tab_size > 0)
	{
		ft_print_tab(tab, tab_size);
		free (tab);
	}
	return (0);
}

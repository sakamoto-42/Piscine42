/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:10:33 by juduchar          #+#    #+#             */
/*   Updated: 2024/08/05 10:49:24 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	range = malloc(size * sizeof(int));
	if (range)
	{
		i = 0;
		while (min < max)
		{
			range[i] = min;
			i++;
			min++;
		}
		return (range);
	}
	return (NULL);
}
/*
void	ft_print_tab(int *range, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		printf("%d", range[i]);
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

	min = 5;
	max = 15;
	tab = ft_range(min, max);
	if (tab)
	{
		ft_print_tab(tab, max - min);
		free (tab);
	}
	return (0);
}
*/

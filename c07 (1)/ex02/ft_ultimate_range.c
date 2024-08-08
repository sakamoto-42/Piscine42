/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:35:47 by juduchar          #+#    #+#             */
/*   Updated: 2024/08/05 11:17:37 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*tab;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = malloc(size * sizeof(int));
	if (*range == NULL)
		return (-1);
	tab = *range;
	while (min < max)
	{
		*tab = min;
		tab++;
		min++;
	}
	return (size);
}
/*
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
	tab_size = ft_ultimate_range(&tab, min, max);
	if (tab_size > 0)
	{
		ft_print_tab(tab, tab_size);
		free (tab);
	}
	return (0);
}
*/

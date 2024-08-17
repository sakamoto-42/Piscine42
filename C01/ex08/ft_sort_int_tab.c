/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:19:02 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/19 09:36:06 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	min = tab[0];
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				min = tab[j];
				tab[j] = tab[i];
				tab[i] = min;
			}
			j++;
		}
		i++;
	}
}

/*
void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d", tab[i]);
		if (i < 9)
			printf(" ");
		i++;
	}
}

int	main(void)
{
	int	array[10] = {15, 12, 23, 1, 9, -15, 0, -42, 42, 12};
	int	size;

	size = 10;
	print_tab(array, size);
	printf("\n");
	ft_sort_int_tab(array, size);
	print_tab(array, size);
}
*/

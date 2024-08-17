/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:42:46 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/18 19:03:29 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

/*
void	ft_print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
}
*/

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	end;
	int	temp;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		temp = tab[start];
		tab[start] = tab[end];
		tab[end] = temp;
		start++;
		end--;
	}
}

/*
int	main(void)
{
	int	tab[10];
	int	i;
	int	tab_size;

	i = 0;
	while (i < 10)
	{
		tab[i] = i;
		i++;
	}
	tab_size = i;
	ft_print_tab(tab, tab_size);
	printf("\n");
	ft_rev_int_tab(tab, tab_size);
	ft_print_tab(tab, tab_size);
}
*/

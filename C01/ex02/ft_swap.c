/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:46:57 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/18 16:11:36 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp_a;

	temp_a = *a;
	*a = *b;
	*b = temp_a;
}

/*
int	main(void)
{
	int	i;
	int	j;
	int	*ptr1;
	int	*ptr2;

	i = 42;
	j = 24;
	printf("%d ", i);
	printf("%d", j);
	printf("\n");
	ptr1 = &i;
	ptr2 = &j;
	ft_swap(ptr1, ptr2);
	printf("%d ", i);
	printf("%d", j);
}
*/

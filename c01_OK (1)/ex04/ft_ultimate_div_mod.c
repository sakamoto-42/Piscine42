/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:03:25 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/18 16:15:14 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_a;

	temp_a = *a;
	*a = *a / *b;
	*b = temp_a % *b;
}

/*
int main(void)
{
	int	i;
	int	j;

	i = 10;
	j = 7;
	printf("%d ", i);
	printf("%d", j);
	printf("\n");
	ft_ultimate_div_mod(&i, &j);
	printf("%d ", i);
	printf("%d", j);
}
*/

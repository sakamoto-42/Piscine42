/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:30:33 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/27 18:36:25 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_rec_is_prime(int n, int sqrt, int i)
{
	int	is_prime;

	if (i > sqrt)
		return (1);
	if (n % i == 0)
		return (0);
	is_prime = ft_rec_is_prime(n, sqrt, i + 1);
	return (is_prime);
}

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 1)
		return (0);
	i = 1;
	while ((i * i) < nb)
		i++;
	return (i);
}

int	ft_is_prime(int nb)
{
	int	is_prime;
	int	sqrt;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	sqrt = ft_sqrt(nb);
	is_prime = ft_rec_is_prime(nb, sqrt, 2);
	return (is_prime);
}

/*
int	main(void)
{
	printf("%d", ft_is_prime(5));
}*/

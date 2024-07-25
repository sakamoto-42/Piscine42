/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:30:33 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/25 18:35:02 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_rec_prime(int nb, int div)
{
	if (div == 1)
		return (1);
	if (nb % div == 0)
		return (0);
	return (ft_rec_prime(nb, div - 1));
}

int	ft_is_prime(int nb)
{
	return (ft_rec_prime(nb, nb - 1));
}

/*
int	main(void)
{
	printf("%d", ft_is_prime(4));
}
*/

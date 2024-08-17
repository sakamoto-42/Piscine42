/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:13:57 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/24 22:07:00 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_nbr(long int nbr)
{
	char	c;

	c = nbr + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	long int	l_nbr;

	l_nbr = (long int) nbr;
	if (l_nbr < 0)
	{
		write(1, "-", 1);
		l_nbr = -l_nbr;
	}
	if (l_nbr >= 10)
		ft_putnbr(l_nbr / 10);
	ft_print_nbr(l_nbr % 10);
}

/*
int	main(void)
{
	int	nbr;

	nbr = 12345;
	ft_putnbr(nbr);
}
*/

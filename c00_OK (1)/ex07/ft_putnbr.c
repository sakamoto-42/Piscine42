/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:23:35 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/24 17:46:59 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_nb(long int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	l_nb;

	l_nb = (long int) nb;
	if (l_nb < 0)
	{
		write(1, "-", 1);
		l_nb = -l_nb;
	}
	if (l_nb >= 10)
		ft_putnbr(l_nb / 10);
	ft_write_nb(l_nb % 10);
}

/*
int	main(void)
{
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:33:34 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/23 13:00:53 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_nb(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

void	ft_write_combn(int comb[9], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_write_nb(comb[i]);
		i++;
	}
}

void	ft_rec_combn(int comb[9], int n, int pos, int prev)
{
	int	i;

	if (pos == n)
	{
		ft_write_combn(comb, n);
		if (comb[0] < 10 - n)
			write(1, ", ", 2);
		return ;
	}
	i = prev + 1;
	while (i <= 9)
	{
		comb[pos] = i;
		ft_rec_combn(comb, n, pos + 1, i);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	comb[9];

	if (n >= 1 && n <= 9)
		ft_rec_combn(comb, n, 0, -1);
}

/*
int	main(void)
{
	int	i;

	i = 9;
	ft_print_combn(i);
	return (0);
}
*/

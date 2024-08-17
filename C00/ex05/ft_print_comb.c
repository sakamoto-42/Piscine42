/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:53:02 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/18 11:34:15 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_int(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				ft_write_int(i);
				ft_write_int(j);
				ft_write_int(k);
				if (!(i == 7 && j == 8 && k == 9))
					write(1, ", ", 2);
				k++;
			}
			j++;
		}
		i++;
	}
}

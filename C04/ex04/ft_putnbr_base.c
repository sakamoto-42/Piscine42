/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:35:01 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/24 09:17:38 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_nbr(int nbr, char *base)
{
	char	c;

	c = base[nbr];
	write(1, &c, 1);
}

void	ft_rec_putnbr_base(int nbr, int base_len, char *base)
{
	if (nbr >= base_len)
		ft_rec_putnbr_base(nbr / base_len, base_len, base);
	ft_write_nbr(nbr % base_len, base);
}

int	ft_error_handler(char *base, int base_len)
{
	int	i;
	int	j;

	if (base_len <= 1)
		return (1);
	i = 0;
	while (i < base_len - 1)
	{
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < base_len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (ft_error_handler(base, base_len))
		return ;
	ft_rec_putnbr_base(nbr, base_len, base);
}

/*
int	main(void)
{
	int		nbr;
	char	base[] = "0123456789";

	nbr = 8;
	ft_putnbr_base(nbr, base);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:24:19 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/30 18:47:53 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_nbr_base_to_str_base(int *tab,
	int count, char *base, int neg)
{
	char	*str;
	int		nbr;
	char	*str_start;
	int		i;

	str = (char *) malloc((count + neg + 1) * sizeof(int));
	if (str)
	{
		str_start = str;
		if (neg)
			*(str++) = '-';
		i = 0;
		while (i < count - 1)
		{
			nbr = tab[i++];
			*(str++) = base[nbr];
		}
		free (tab);
		*str = '\0';
		return (str_start);
	}
	free (tab);
	return (NULL);
}

void	ft_rec_convert_nbr_to_base(int nbr, int base_len, int *tab, int count)
{
	if (nbr >= base_len)
		ft_rec_convert_nbr_to_base(nbr / base_len, base_len, tab, count - 1);
	tab[count - 1] = nbr % base_len;
}

int	ft_tab_len(int nbr, int base_len)
{
	int	count;

	count = 1;
	while (nbr / base_len != 0)
	{
		nbr = nbr / base_len;
		count++;
	}
	return (count);
}

char	*ft_nbr_to_base(int nbr, char *base, int base_len)
{
	int		neg;
	int		count;
	int		*tab;
	char	*str;

	neg = 0;
	if (nbr < 0)
	{
		neg = 1;
		nbr = -nbr;
	}
	count = ft_tab_len(nbr, base_len);
	tab = (int *) malloc(count * sizeof(int));
	if (tab)
	{
		ft_rec_convert_nbr_to_base(nbr, base_len, tab, count);
		str = ft_convert_nbr_base_to_str_base(tab, count, base, neg);
		if (str)
			return (str);
	}
	return (NULL);
}

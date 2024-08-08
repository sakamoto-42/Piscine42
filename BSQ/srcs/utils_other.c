/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:23:01 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/07 18:53:55 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	free_2d(char **list)
{
	int	i;

	i = 0;
	while (list[i] != 0)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	int_free_2d(int **tab, t_ulli rows)
{
	t_ulli	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (i < rows)
	{
		if (tab[i] != NULL)
			free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:25:53 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/24 14:18:08 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char			*hexa_base;
	unsigned int	n1;
	unsigned int	n2;
	unsigned char	c;

	hexa_base = "0123456789abcdef";
	while (*str != '\0')
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
		{
			write(1, "\\", 1);
			c = (unsigned char) *str;
			n1 = c / 16;
			c = hexa_base[n1];
			write(1, &c, 1);
			c = (unsigned char) *str;
			n2 = c % 16;
			c = hexa_base[n2];
			write(1, &c, 1);
		}
		str++;
	}
}

/*
int	main(void)
{
	char	str[] = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(str);
}
*/

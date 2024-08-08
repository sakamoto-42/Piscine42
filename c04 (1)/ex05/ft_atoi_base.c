/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:16:48 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/24 23:34:29 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_char_base_to_dec(char c, int base_len, char *base)
{
	char	*ptr;

	ptr = base;
	while (ptr < base + base_len)
	{
		if (c == *ptr)
			return (ptr - base);
		ptr++;
	}
	return (-1);
}

int	ft_atoi_str_base_to_dec(char *str, int base_len, char *base)
{
	int	sign;
	int	n;
	int	nb;

	sign = 1;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str != '\0')
	{
		n = ft_char_base_to_dec(*str, base_len, base);
		if (n == -1)
			return (0);
		nb = nb * base_len + n;
		str++;
	}
	return (sign * nb);
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

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	nbr;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (ft_error_handler(base, base_len))
		return (0);
	nbr = ft_atoi_str_base_to_dec(str, base_len, base);
	return (nbr);
}

/*
int	main(void)
{
	char	str[] = "100";
	char	base[] = "01";
	int		nbr;

	nbr = ft_atoi_base(str, base);
	printf("%d", nbr);
}
*/

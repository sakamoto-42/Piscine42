/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:56:04 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/30 19:26:33 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_nbr_to_base(int nbr, char *base, int base_len);

int	ft_char_base_to_dec(char c, char *base, int base_len)
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

int	ft_atoi_base_to_dec(char *str, char *base, int base_len)
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
	while (*str)
	{
		n = ft_char_base_to_dec(*str, base, base_len);
		if (n == -1)
			return (0);
		nb = nb * base_len + n;
		str++;
	}
	return (sign * nb);
}

int	ft_base_len(char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	return (base_len);
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*converted_base;
	int		base_from_len;
	int		base_to_len;
	int		nbr_dec;

	base_from_len = ft_base_len(base_from);
	base_to_len = ft_base_len(base_to);
	if (ft_error_handler(base_from, base_from_len)
		|| ft_error_handler(base_to, base_to_len))
	{
		return (NULL);
	}
	nbr_dec = ft_atoi_base_to_dec(nbr, base_from, base_from_len);
	converted_base = ft_nbr_to_base(nbr_dec, base_to, base_to_len);
	return (converted_base);
}
/*
int	main(void)
{
	char	*nbr = " \f\n\r\t\v+--+--++1234567890";
	char	*base_from = "0123456789";
	char	*base_to = "0123456789";
	char	*res;

	res = ft_convert_base(nbr, base_from, base_to); 
	if (!res)
		printf("ERROR");
	else
		printf("%s", res);
	free (res);
	return (0);
}
*/

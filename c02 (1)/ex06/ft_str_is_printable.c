/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:28:26 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/20 17:34:14 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str >= 32 && *str <= 126)
		str++;
	if (*str == '\0')
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	char	*src;
	int		res;

	src = "\b\t\rabc";
	res = ft_str_is_printable(src);
	printf("%d\n", res);
	src = "abc123";
	res = ft_str_is_printable(src);
	printf("%d\n", res);
}
*/

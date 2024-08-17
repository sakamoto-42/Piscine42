/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:13:34 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/20 17:17:10 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	while (*str >= '0' && *str <= '9')
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

	src = "abc123";
	res = ft_str_is_numeric(src);
	printf("%d\n", res);
	src = "123";
	res = ft_str_is_numeric(src);
	printf("%d\n", res);
}
*/

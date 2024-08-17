/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:18:11 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/20 17:21:39 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	while (*str >= 'a' && *str <= 'z')
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

	src = "ABCabc";
	res = ft_str_is_lowercase(src);
	printf("%d\n", res);
	src = "abc";
	res = ft_str_is_lowercase(src);
	printf("%d\n", res);
}
*/

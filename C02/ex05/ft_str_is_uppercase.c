/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:22:38 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/21 11:09:56 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	while (*str >= 'A' && *str <= 'Z')
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

	src = "abcABC";
	res = ft_str_is_uppercase(src);
	printf("%d\n", res);
	src = "ABC";
	res = ft_str_is_uppercase(src);
	printf("%d\n", res);
}
*/

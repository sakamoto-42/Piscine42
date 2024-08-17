/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:02:36 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/21 11:09:19 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	while ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
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
	res = ft_str_is_alpha(src);
	printf("%d\n", res);
	src = "abc";
	res = ft_str_is_alpha(src);
	printf("%d\n", res);
}
*/

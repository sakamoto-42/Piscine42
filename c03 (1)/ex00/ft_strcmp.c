/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:46:30 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/22 08:59:06 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		c1 = (unsigned char) s1[i];
		c2 = (unsigned char) s2[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char	str1a[] = "ABC";
	char	str2a[] = "ABC";

	char	str1b[] = "ABC";
	char	str2b[] = "AB";

	char	str1c[] = "ABA";
	char	str2c[] = "ABZ";

	char	str1d[] = "ABJ";
	char	str2d[] = "ABC";

	char	str1e[] = "\201";
	char	str2e[] = "A";

	int		res;

	res = ft_strcmp(str1a, str2a);
	printf("%d\n", res);
	res = ft_strcmp(str1b, str2b);
	printf("%d\n", res);
	res = ft_strcmp(str1c, str2c);
	printf("%d\n", res);
	res = ft_strcmp(str1d, str2d);
	printf("%d\n", res);
	res = ft_strcmp(str1e, str2e);
	printf("%d\n", res);
}
*/

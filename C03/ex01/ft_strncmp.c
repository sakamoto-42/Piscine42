/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:31:58 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/24 22:51:35 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
 j = 0;
	while ((i < n) && (s1[i] != '\0' || s2[j] != '\0'))
	{
		if (s1[i] != s2[j])
			return (s1[i] - s2[j]);
		i++;
  j++;
	}
	return ((s1[i] - s2[j]);
}

/*
int	main(void)
{
	unsigned int	res;
	unsigned int	n;

	char	str1a[] = "ABC";
	char	str2a[] = "ABD";

	char	str1b[] = "BAC";
	char	str2b[] = "AB";

	char	str1c[] = "AAA";
	char	str2c[] = "BAZ";

	char	str1d[] = "ABC";
	char	str2d[] = "ABJ";

	char	str1e[] = "\201";
	char	str2e[] = "A";

	n = 2;
	res = ft_strncmp(str1a, str2a, n);
	printf("%d\n", res);

	n = 2;
	res = ft_strncmp(str1b, str2b, n);
	printf("%d\n", res);

	n = 0;
	res = ft_strncmp(str1c, str2c, n);
	printf("%d\n", res);

	n = 3;
	res = ft_strncmp(str1d, str2d, n);
	printf("%d\n", res);

	n = 1;
	res = ft_strncmp(str1e, str2e, n);
	printf("%d\n", res);
}
*/

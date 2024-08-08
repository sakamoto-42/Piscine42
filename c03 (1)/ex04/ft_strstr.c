/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:24:24 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/31 09:16:55 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*str_start;
	char	*to_find_start;

	if (*to_find == '\0')
		return (str);
	if (*str == '\0')
		return (NULL);
	to_find_start = to_find;
	while (*str != '\0')
	{
		str_start = str;
		to_find = to_find_start;
		while (*str == *to_find && *to_find != '\0')
		{
			str++;
			to_find++;
		}
		if (*to_find == '\0')
			return (str_start);
		str = str_start + 1;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	haystack[] = "abc_imnothere_imherefirst_imheresecond";
	char	needle[] = "imherei";
	char	*substring;

	substring = malloc(25 * sizeof(char));
	printf("%s\n", haystack);
	printf("%s\n", needle);
	substring = ft_strstr(haystack, needle);
	if (substring)
		printf("%s\n", substring);
}*/

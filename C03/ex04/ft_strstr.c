/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:24:24 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/24 18:09:19 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*substring_ptr;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
			substring_ptr = str + i;
		while (str[i] == to_find[j] && (str[i] != '\0' || to_find[j] != '\0'))
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
			return (substring_ptr);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	haystack[] = "abc_imnothere_imherefirst_imheresecond";
	char	needle[] = "imhere";
	char	*substring;

	substring = malloc(25 * sizeof(char));
	printf("%s\n", haystack);
	printf("%s\n", needle);
	substring = ft_strstr(haystack, needle);
	printf("%s\n", substring);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:50:08 by juduchar          #+#    #+#             */
/*   Updated: 2024/08/05 10:48:48 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
//#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*dest;
	int		i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	dest = malloc((src_len + 1) * sizeof(char));
	if (dest)
	{
		i = 0;
		while (i < src_len)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	errno = ENOMEM;
	return (NULL);
}
/*
int	main(void)
{
	char	*src;
	char	*dest;

	src = malloc((6 + 1) * sizeof(char));
	src = "Coucou";
	printf("%s\n", src);
	dest = ft_strdup(src);
	printf("%s", dest);
	free(dest);
	return (0);
}
*/

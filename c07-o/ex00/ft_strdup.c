/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:50:08 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/28 10:27:54 by juduchar         ###   ########.fr       */
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
	dest = (char *) malloc((src_len + 1) * sizeof(*src));
	if (dest)
	{
		i = 0;
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	else
	{
		errno = ENOMEM;
		return (NULL);
	}
}

/*
int	main(void)
{
	char	src[] = "Coucou";
	char	*dest;

	printf("%s\n", src);
	dest = ft_strdup(src);
	printf("%s", dest);
	free(dest);
	return (0);
}
*/

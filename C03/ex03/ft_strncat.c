/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:03:05 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/22 13:19:35 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_len;
	unsigned int	i;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

/*
int	main(void)
{
	char			dest[14] = "Hello ";
	char			src[] = "World ! OVERFLOW !";
	unsigned int	nb;

	nb = 7;
	printf("%s\n", dest);
	printf("%s\n", src);
	ft_strncat(dest, src, nb);
	printf("%s\n", dest);
}
*/

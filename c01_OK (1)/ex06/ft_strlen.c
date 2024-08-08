/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:40:37 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/18 18:40:22 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;
	int	strlen;

	i = 0;
	while (str[i] != '\0')
		i++;
	strlen = i;
	return (strlen);
}

/*
int	main(void)
{
	char	*str;
	int		len;

	str = "Hello World!";
	len = ft_strlen(str);
	printf("%d", len);
}
*/

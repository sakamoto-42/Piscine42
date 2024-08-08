/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_map2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:24:25 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/07 18:25:24 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_copy_line(char *dest_line, char *src_line)
{
	int	i;

	i = 0;
	while (src_line[i] != '\n')
	{
		dest_line[i] = src_line[i];
		i++;
	}
	dest_line[i] = '\0';
	return (dest_line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:51:21 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/25 12:13:22 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;

	if (argc - 1 >= 1)
	{
		i = 1;
		while (i < argc)
		{
			while (*argv[i] != '\0')
			{
				write(1, argv[i], 1);
				argv[i]++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:19:08 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/25 14:33:17 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_sort_params(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;
	int		strcmp;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			strcmp = ft_strcmp(argv[i], argv[j]);
			if (strcmp > 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_print_sorted_params(int argc, char **argv)
{
	int	str_i;

	str_i = 1;
	while (str_i < argc)
	{
		while (*argv[str_i] != '\0')
		{
			write(1, argv[str_i], 1);
			argv[str_i]++;
		}
		write(1, "\n", 1);
		str_i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc - 1 >= 1)
	{
		ft_sort_params(argc, argv);
		ft_print_sorted_params(argc, argv);
	}
}

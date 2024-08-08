/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:03:50 by juduchar          #+#    #+#             */
/*   Updated: 2024/08/07 20:23:28 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/utils.h"

int	main(int argc, char **argv)
{
	if (argc - 1 >= 1)
	{
		if (!(ft_init_bsq_with_args(argc, argv)))
			ft_putstr("Error\n");
	}
	else if (argc - 1 == 0)
	{
		if (!(ft_init_bsq_with_no_args()))
			ft_putstr("Error\n");
	}
	return (0);
}

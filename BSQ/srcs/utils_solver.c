/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:16:47 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/07 18:25:39 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	get_min_nbr(t_calcu nb)
{
	if (nb.corner <= nb.left && nb.corner <= nb.up)
		return (nb.corner);
	if (nb.left <= nb.up && nb.left <= nb.corner)
		return (nb.left);
	if (nb.up <= nb.left && nb.up <= nb.corner)
		return (nb.up);
	return (-1);
}

void	line_solver(int **tab, t_map_infos *info, int diag)
{
	t_calcu	calcu;

	info->x = diag;
	info->y = diag;
	while (tab[info->y][info->x] != -2)
	{
		if (tab[info->y][info->x] != 0)
		{
			calcu.left = tab[info->y][info->x - 1];
			calcu.up = tab[info->y - 1][info->x];
			calcu.corner = tab[info->y - 1][info->x - 1];
			tab[info->y][info->x] = get_min_nbr(calcu) + 1;
		}
		info->x++;
	}
}

void	collumn_solver(int **tab, t_map_infos *info, int diag)
{
	t_calcu	calcu;

	info->x = diag;
	info->y = diag;
	while (tab[info->y][info->x] != -2)
	{
		if (tab[info->y][info->x] != 0)
		{
			calcu.left = tab[info->y][info->x - 1];
			calcu.up = tab[info->y - 1][info->x];
			calcu.corner = tab[info->y - 1][info->x - 1];
			tab[info->y][info->x] = get_min_nbr(calcu) + 1;
		}
		info->y++;
	}
}

void	solver(int **tab, t_map_infos *info)
{
	unsigned long long int	diag;

	diag = 1;
	while (diag < info->size)
	{
		collumn_solver(tab, info, diag);
		line_solver(tab, info, diag);
		diag++;
	}
}

t_map_infos	find_bigest_nbr(int **tab, t_map_infos *info)
{
	info->nb = 0;
	info->x = 0;
	info->y = 0;
	while (info->y < info->size)
	{
		info->x = 0;
		while (info->x < info->size_line)
		{
			if (info->nb < tab[info->y][info->x])
			{
				info->nb = tab[info->y][info->x];
				info->j = info->x;
				info->i = info->y;
			}
			info->x++;
		}
		info->y++;
	}
	info->nb--;
	info->x = info->j - (info->nb);
	info->y = info->i - (info->nb);
	return (*info);
}

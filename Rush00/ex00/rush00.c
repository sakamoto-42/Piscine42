/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:49:22 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/21 09:14:28 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_rows(int max_col, char border_char, char middle_char)
{
	int	current_col;

	current_col = 1;
	ft_putchar(border_char);
	current_col++;
	while (current_col <= max_col - 1)
	{	
		ft_putchar(middle_char);
		current_col++;
	}
	if (max_col != 1)
		ft_putchar(border_char);
}

void	rush(int x, int y)
{
	int		max_col;
	int		max_row;
	int		current_row;

	max_col = x;
	max_row = y;
	if (max_col <= 0 || max_row <= 0)
		return ;
	else if (max_col <= 2147483647 && max_row <= 2147483647)
	{
		current_row = 1;
		while (current_row <= max_row)
		{
			if (current_row == 1 || current_row == max_row)
				ft_print_rows(max_col, 'o', '-');
			else
				ft_print_rows(max_col, '|', ' ');
			ft_putchar('\n');
			current_row++;
		}
	}
	else
		return ;
}

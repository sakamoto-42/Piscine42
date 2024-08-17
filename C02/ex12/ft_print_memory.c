/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:26:00 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/24 22:00:49 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_addr_hexa_first_char(void *addr)
{
	unsigned long	addr_first_char;
	int				shift_val;
	unsigned char	current_byte;
	char			*hex;

	addr_first_char = (unsigned long long addr);
	shift_val = (sizeof(addr_first_char) * 8) - 8;
	hex = "0123456789abcdef";
	while (shift_val >= 0)
	{
		current_byte = (addr_first_char >> shift_val) & (0xFF);
		write(1, &hex[c / 16], 1);
		write(1, &hex[c % 16], 1);
		shift_val -= 8;
	}
}

void	ft_print_content_hexa(unsigned char * str, unsigned int size)
{
	unsigned int	i;
}

void	ft_print_content(void *str, unsigned int offset)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && i < offset)
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *str, unsigned int size)
{
	unsigned int	offset;
	unsigned char	*str;

	offset = 0;
	str = (unsigned char *) addr;
	while (offset < size)
	{
		ft_print_addr_hexa_first_char(str + offset);
		write(1, ":", 1);
		ft_print_content_hexa(str + offset, size - offset);
		write(1, " ", 1);
		ft_print_content(str + offset, size - offset);
		write(1, "\n", 1);
		offset += 16;
	}	
	return (addr);
}

int	main(void)
{
	char	str[] = "Bonjour les aminches\t\n\tc\t est fou\ttout\tce qu on peut faire avec\n\t\nprint_memory\n\n\n\tlol\nlol\n \n";

	ft_print_memory(str, 92);
}

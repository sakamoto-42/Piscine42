/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:05:16 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/24 11:32:26 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_handle_alpha_chars(char *str, int *is_first_letter)
{
	if (*str >= 'a' && *str <= 'z')
	{
		if (*is_first_letter)
		{
			*str -= 32;
			*is_first_letter = 0;
		}
	}
	else if (*str >= 'A' && *str <= 'Z')
	{
		if (!(*is_first_letter))
			*str += 32;
		else
			*is_first_letter = 0;
	}
}

char	*ft_strcapitalize(char *str)
{
	int		is_first_letter;
	char	*str_start;

	str_start = str;
	is_first_letter = 1;
	while (*str != '\0')
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
			ft_handle_alpha_chars(str, &is_first_letter);
		else if (*str >= '0' && *str <= '9')
			is_first_letter = 0;
		else
			is_first_letter = 1;
		str++;
	}
	return (str_start);
}

/*
int	main(void)
{
	char	src1[] = "saLut, comment tu vAs ? ";
	char	src2[] = "42mots QuaranTe-dEux; cinquAnte+et+un";

	printf("%s", src1);
	printf("%s\n", src2);
	ft_strcapitalize(src1);
	ft_strcapitalize(src2);
	printf("%s", src1);
	printf("%s", src2);
}
*/

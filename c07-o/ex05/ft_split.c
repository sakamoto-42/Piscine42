/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 08:35:04 by juduchar          #+#    #+#             */
/*   Updated: 2024/07/31 11:05:42 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_split(char *str, char *charset)
{
	/*
	if (*charset == '\0')
		// retourner un tableau avec la chaine str en 1er element et 0 en dernier element
	if (*str == '\0')
		// retourner un tableau avec 0 en 1er element
	else*/
	//char	*first_word;
	char	*str_start;
	char	*charset_start;
	int		found;
	char	*str_end;
	char	**str_tab;

	// tableau de 1 chaine de caracteres
	str_tab = (char **) malloc(1 * sizeof(char **));
	*str_tab = (char *) malloc((7 + 1) * sizeof(char *));

	found = 0;
	str_start = str;
	charset_start = charset;

	while (*str != '\0' && !found)
	{
		str_end = str;
		charset = charset_start;
		while (*str == *charset && *charset != '\0')
		{
			str++;
			charset++;
		}
		if (*charset == '\0')
		{
			found = 1;
		}
		else
			str = str_end + 1;
	}
	printf("%c", *str);
	//printf("%c", *str_start);
	str_end--;
	//printf("%c", *str_end);
	while (str_start <= str_end)
	{
		*str_tab[0] = *str_start;
		printf("%c", *str_tab[0]);
		str_tab[0]++;
		str_start++;
	}
	return (0);
		// 2) faire un strstr pour trouver l'adresse de debut du haystack et celle de fin
		// 3) aller de base str a cette adresse de debut du haystack
		// 4) la mettre dans le 1er element du tableau
		// 5) reprendre au 1) mais avec l'adresse de fin du haystack + 1
		// 6) s'arreter au caractere '\0' de str
		// 7) ajouter 0 en dernier element du tableau
		// 8) transmettre une chaine non modifiable ???
}

int	main(void)
{
	char	*str;
	char	*charset;

	str = "Bonjour -:mon -:login -:est -:juduchar";
	charset = " -:";
	ft_split(str, charset);
}

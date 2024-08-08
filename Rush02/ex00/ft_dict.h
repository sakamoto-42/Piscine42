/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:14:14 by juduchar          #+#    #+#             */
/*   Updated: 2024/08/04 16:59:42 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_H
# define FT_DICT_H

typedef struct s_dict
{
	int		key_size;
	char	*key_str;
	char	value_size;
	char	*value_str;
	int		end;
}	t_dict;

#endif

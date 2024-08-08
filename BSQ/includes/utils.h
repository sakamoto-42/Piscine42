/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:16:26 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/07 18:54:13 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h> // DELETE
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//____________STRUCT____________
typedef unsigned long long int	t_ulli;

typedef struct s_incr
{
	unsigned long long int	i;
	unsigned long long int	j;
	unsigned long long int	x;
	unsigned long long int	y;

}	t_incr;

typedef struct s_calcu
{
	int	corner;
	int	left;
	int	up;

}	t_calcu;

typedef struct s_file
{
	int		file;
	char	buff[1];
	int		size;

}	t_file;

typedef struct s_map_infos
{
	unsigned long long int		size;
	unsigned long long int		size_line;
	char						empty;
	char						obstacle;
	char						full;
	unsigned long long int		i;
	unsigned long long int		j;
	unsigned long long int		x;
	unsigned long long int		y;
	int							nb;
}	t_map_infos;
//____________END_STRUCT____________

//____________STRING____________
t_ulli			ft_strlen(char *str);
int				ft_strslen(char **str);
char			*ft_strcpy(char *dest, char *src);
void			ft_swap(char **a, char **b);
void			ft_putstr(char *str);
//____________SOLVER___________
void			ft_bsq(t_map_infos map_infos, char **map);
void			solver(int **tab, t_map_infos *info);
void			collumn_solver(int **tab, t_map_infos *info, int diag);
void			line_solver(int **tab, t_map_infos *info, int diag);
int				get_min_nbr(t_calcu nb);
t_map_infos		find_bigest_nbr(int **tab, t_map_infos *info);
int				ft_init_bsq_with_args(int argc, char **argv);
//____________MAP___________
void			char_to_int_cpy(char *str, int *tab, t_map_infos info);
int				**init_map_tab(char **map, t_map_infos *info);
t_map_infos		ft_get_map_infos(char *str_map);
char			**ft_get_map(char *str_map, t_map_infos map_infos);
char			**replace_full_map(int **tab, char **map, t_map_infos *info);
void			aff_map(char **map, t_map_infos *info);
//____________PARSING___________
int				file_count_char(char *file_name);
char			*file_to_str(char *file_name);
int				ft_get_line_len(char *line);
char			*ft_copy_line(char *dest_line, char *src_line);
t_map_infos		get_map_size(char *str_map, t_map_infos *info);
t_map_infos		get_map_size_line(char *str_map, t_map_infos *info);
int	ft_init_bsq_with_no_args(void);
//____________ERROR___________
int				check_all_error(char **map, t_map_infos *map_info);
int				check_map_size_error(char **map, t_map_infos *info);
int				is_in_charset(char c, t_map_infos *info);
int				check_char_in_map(char **map, t_map_infos *info);
int				check_avalaible_charset(t_map_infos *info);
//____________OTHER___________
void			free_2d(char **list);
void			int_free_2d(int **tab, t_ulli rows);
void			ft_putchar(char c);
void			ft_putnbr(int nb);

#endif

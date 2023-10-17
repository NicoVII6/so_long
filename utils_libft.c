/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:18:48 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/08 13:18:48 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_struct.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (-1)
		else
			i++; 
	}
	return (0)
}

// comparer le type de file ac le type valide .ber que doit avoir notre map
int		ft_type_cmp(const char *str, const char *suffix)
{
	size_t str_len;
	size_t suffix_len;
	const char	*str_suffix; 

	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);

	if (str_len < suffix_len)
		return (-1);
	
	str_suffix = str + (str_len - suffix_len); // pointe sur la position du suffix dans str

	return (ft_strcmp(str_suffix, suffix)); // compare le suffix de str ac le suffix valide suppose
}

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/* returns the number of lines of a 2D string array which NULL terminates */
int		ft_array_linecount(char **arr)
{
	int		count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}
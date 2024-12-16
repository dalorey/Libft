/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:57:56 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/16 19:14:08 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> // printf --- BORRAR!!!

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const unsigned char	*b = (const unsigned char *)big;
	const unsigned char	*l = (const unsigned char *)little;
	size_t				i;
	size_t				j;

	if (*l == 0)
		return ((char *)b);
	if (len == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (b[i] != 0)
	{
		while ((b[i] != l[j]) && (b[i] != 0) && (l[j] != 0))
			i++;
		while ((b[i + j] == l[j]) && (j < len) && (b[i + j] != 0) && (l[j] != 0))
		{
			//printf("Checking little (position %zu): %c; %c\n", j, b[i+j], l[j]);
			j++;
		}
		if (j == len)
			return ((char *)b + i);
		else if (b[i] == 0)
			return (NULL);
		else if (l[i] == 0)
			return (NULL);
		i++;
		j = 0;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:50:22 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/16 11:41:01 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		result;
	size_t	i;

	result = 0;
	i = 0;
	while (result == 0 && (s1[i] != 0 || s2[i] != 0) && (i < n))
	{
		result = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (result);
}

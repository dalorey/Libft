/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:36:32 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/18 10:19:00 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int val, size_t n)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		s[i] = (unsigned char)val;
		i++;
	}
	return (str);
}

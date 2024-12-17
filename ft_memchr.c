/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:31:57 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/16 12:11:27 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char	*s = (unsigned char *)src;
	size_t				i;

	i = 0;
	while ((i < n) && (s[0] != (unsigned char)c))
	{
		i++;
		s++;
	}
	if (i != n)
		return ((void *)s);
	return (NULL);
}
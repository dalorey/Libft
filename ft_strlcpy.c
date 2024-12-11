/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:46:41 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/09 21:30:29 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t				src_len;
	size_t				i;
	const unsigned char	*s = (unsigned char *)src;
	unsigned char		*d;

	src_len = ft_strlen (src);
	if (size > 0)
	{
		d = (unsigned char *)dest;
		i = 0;
		while ((i < size - 1) && (s[i] != '\0'))
		{
			d[i] = s[i];
			i++;
		}
		d[i] = '\0';
	}
	return (src_len);
}

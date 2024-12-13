/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:23 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/11 20:19:04 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const unsigned char	*s = (unsigned char *)src;
	unsigned char		*d;
	size_t				dst_len;
	size_t				src_len;
	size_t				i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dst_len)
		return (size + src_len);
	if (size >= dst_len)
	{
		d = (unsigned char *)dst;
		i = 0;
		while ((dst_len + i < size - 1) && (s[i] != 0))
		{
			d[dst_len + i] = s[i];
			i++;
		}
		d[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:23 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/11 19:47:41 by dlorenzo         ###   ########.fr       */
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
	if (size != 0)
	{
		d = (unsigned char *)dst;
		i = 0;
		while ((i + dst_len < size - 1) && (s[i] != 0))
		{
			d[i + dst_len] = s[i];
			i++;
		}
		d[i + dst_len] = '\0';
	}
	return (dst_len + src_len);
}

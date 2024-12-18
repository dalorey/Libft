/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:03:24 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/18 18:12:43 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;
	size_t	i;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return ((char *)substr);
	}
	if (((size_t)start + len) > str_len)
		len = str_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = str[i + start];
		i++;
	}
	substr[i] = '\0';
	return ((char *)substr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:34:10 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/20 11:10:23 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	unsigned char	*s;

	s = (unsigned char *)malloc(ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	s = (unsigned char *)ft_memcpy(s, str, ft_strlen(str) + 1);
	return ((char *)s);
}

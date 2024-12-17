/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:34:10 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/17 14:09:10 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned char	*t;

	t = (unsigned char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!t)
		return (NULL);
	t = (unsigned char *)ft_memcpy(t, s, ft_strlen(s) + 1);
	return ((char *)t);
}

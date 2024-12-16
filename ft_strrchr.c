/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:29:29 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/16 18:10:44 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	const unsigned char	*s = (unsigned char *)src;
	const unsigned char	*t = NULL;
	int					i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			t = (const unsigned char *)(s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		t = (const unsigned char *)(s + i);
	return ((char *)t);
}

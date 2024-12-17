/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:25:52 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/17 14:11:00 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h> // SIZE_MAX;

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*m;

	m = NULL;
	if (nmemb && size && (nmemb > SIZE_MAX / size))
		return ((void *)m);
	m = malloc(nmemb * size);
	if (!m)
		return (NULL);
	ft_memset(m, 0, nmemb * size);
	return ((void *)m);
}

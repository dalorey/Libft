/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_v1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:23:03 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/05 19:23:14 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dst;
	// size_t	len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = malloc(s1_len + s2_len + 1);
	if (!dst)
		return (NULL);
	// len = ft_strlcpy(dst, s1, s1_len + 1);
	ft_strlcpy(dst, s1, s1_len + 1);
	// len = ft_strlcat(dst, s2, s1_len + s2_len + 1);
	ft_strlcat(dst, s2, s1_len + s2_len + 1);
	return (dst);
}

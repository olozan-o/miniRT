/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:20:33 by olozano-          #+#    #+#             */
/*   Updated: 2021/11/26 20:20:38 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s_out;
	size_t	i;

	i = 0;
	if (!s)
		return ;
	s_out = (char *)s;
	while (i < n)
	{
		s_out[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*cpy;

	if (!(cpy = malloc(nmemb * size)))
		return (NULL);
	ft_bzero(cpy, size * nmemb);
	return (cpy);
}

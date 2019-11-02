/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-la-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:37:05 by lde-la-g          #+#    #+#             */
/*   Updated: 2019/10/30 23:41:29 by lde-la-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*strn;
	size_t	i;

	i = 0;
	if (!(strn = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		strn[i] = '\0';
		i++;
	}
	strn[i] = '\0';
	return (strn);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 09:58:43 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/22 10:15:01 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill(char tab[100], unsigned long i, int base)
{
	char	*chif;
	int		j;

	chif = ft_strdup("0123456789abcdef");
	j = 98;
	while (i)
	{
		tab[j] = chif[i % base];
		i = i / base;
		j--;
	}
	free(chif);
}

char		*ft_itoa_base_ul(unsigned long i, int base)
{
	char	tab[100];
	char	*c;

	bzero(tab, 100);
	if (i == 0)
	{
		tab[0] = '0';
		return (ft_strdup(tab));
	}
	ft_fill(tab, i, base);
	c = tab;
	while (*c == 0)
	{
		c++;
	}
	return (ft_strdup(c));
}

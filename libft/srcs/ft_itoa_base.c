/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 10:33:19 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/25 09:39:46 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	ft_fill(char tab[100], long long int i, int base, int neg)
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
	if (neg)
		tab[j] = '-';
	free(chif);
}

char		*ft_itoa_base(long long int i, int base)
{
	int		neg;
	char	tab[100];
	char	*c;

	bzero(tab, 100);
	neg = 0;
	if (i == 0)
		return (ft_strdup("0"));
	if (i == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (i < 0)
	{
		i = -i;
		if (base == 10)
			neg = 1;
	}
	ft_fill(tab, i, base, neg);
	c = tab;
	while (*c == 0)
	{
		c++;
	}
	return (ft_strdup(c));
}

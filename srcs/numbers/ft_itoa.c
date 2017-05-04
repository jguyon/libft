/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:58:22 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/22 15:02:10 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_numbers.h"
#include "ft_strings.h"

static size_t	num_len(unsigned int n)
{
	size_t	len;

	len = 1;
	while (n /= 10)
		++len;
	return (len);
}

static void		num_cpy(unsigned int n, char *str, size_t len)
{
	while (len)
	{
		--len;
		str[len] = n % 10 + '0';
		n /= 10;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = num_len(FT_ABS(n));
	if (n < 0)
		++len;
	if (!(str = ft_strnew(len)))
		return (NULL);
	num_cpy(FT_ABS(n), str, len);
	if (n < 0)
		str[0] = '-';
	return (str);
}

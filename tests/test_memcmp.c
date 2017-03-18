/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:01:35 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 18:11:42 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_memory.h"
#include <string.h>

static void	test_equal(t_tap *t)
{
	char	mem[] = "qwertyuiopasdfghjklzxcvbnm01234567890";
	char	cmp[sizeof(mem)];
	int		res;

	memcpy(cmp, mem, sizeof(mem));
	res = ft_memcmp(cmp, mem, sizeof(mem));
	FT_TAP_IEQ(t, res, 0);
}

static void	test_greater(t_tap *t)
{
	char	mem[] = "qwertyuiopasdfghjklzxcvbnm01234567890";
	char	cmp[sizeof(mem)];
	int		res;

	memcpy(cmp, mem, sizeof(mem));
	cmp[7] = 255;
	res = ft_memcmp(cmp, mem, sizeof(mem));
	FT_TAP_IEQ(t, res, 255 - mem[7]);
}

static void	test_lower(t_tap *t)
{
	char	mem[] = "qwertyuiopasdfghjklzxcvbnm01234567890";
	char	cmp[sizeof(mem)];
	int		res;

	memcpy(cmp, mem, sizeof(mem));
	cmp[7] = 1;
	res = ft_memcmp(cmp, mem, sizeof(mem));
	FT_TAP_IEQ(t, res, 1 - mem[7]);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_equal);
	FT_TAP_TEST(t, test_greater);
	FT_TAP_TEST(t, test_lower);
}

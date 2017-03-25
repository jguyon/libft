/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:54:44 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 17:20:15 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_memory.h"
#include <string.h>

static void	test_size_zero(t_tap *t)
{
	char	mem_ft[16];
	char	mem_lc[sizeof(mem_ft)];
	char	*res_ft;
	char	*res_lc;

	memset(mem_ft, 1, sizeof(mem_ft));
	memset(mem_lc, 1, sizeof(mem_ft));
	res_ft = ft_memset(mem_ft, 2, 0);
	res_lc = memset(mem_lc, 2, 0);
	FT_TAP_IEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, memcmp(mem_ft, mem_lc, sizeof(mem_ft)) == 0);
}

static void test_size_full(t_tap *t)
{
	char	mem_ft[16];
	char	mem_lc[sizeof(mem_ft)];
	char	*res_ft;
	char	*res_lc;

	memset(mem_ft, 1, sizeof(mem_ft));
	memset(mem_lc, 1, sizeof(mem_lc));
	res_ft = ft_memset(mem_ft, 2, sizeof(mem_ft));
	res_lc = memset(mem_lc, 2, sizeof(mem_ft));
	FT_TAP_IEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, memcmp(mem_ft, mem_lc, sizeof(mem_ft)) == 0);
}

static void	test_size_partial(t_tap *t)
{
	char	mem_ft[32];
	char	mem_lc[sizeof(mem_ft)];
	char	*res_ft;
	char	*res_lc;

	memset(mem_ft, 1, sizeof(mem_ft));
	memset(mem_lc, 1, sizeof(mem_lc));
	res_ft = ft_memset(mem_ft + 3, 2, sizeof(mem_ft) - 5);
	res_lc = memset(mem_lc + 3, 2, sizeof(mem_ft) - 5);
	FT_TAP_IEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, memcmp(mem_ft, mem_lc, sizeof(mem_ft)) == 0);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_size_zero);
	FT_TAP_TEST(t, test_size_full);
	FT_TAP_TEST(t, test_size_partial);
}

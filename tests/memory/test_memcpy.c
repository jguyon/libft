/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:28:09 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 17:35:23 by jguyon           ###   ########.fr       */
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
	char	src[sizeof(mem_ft)];

	bzero(mem_ft, sizeof(mem_ft));
	bzero(mem_lc, sizeof(mem_ft));
	memset(src, 1, sizeof(mem_ft));
	res_ft = ft_memcpy(mem_ft, src, 0);
	res_lc = memcpy(mem_lc, src, 0);
	FT_TAP_IEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, memcmp(mem_ft, mem_lc, sizeof(mem_ft)) == 0);
}

static void	test_size_full(t_tap *t)
{
	char	mem_ft[16];
	char	mem_lc[sizeof(mem_ft)];
	char	*res_ft;
	char	*res_lc;
	char	src[sizeof(mem_ft)];

	bzero(mem_ft, sizeof(mem_ft));
	bzero(mem_lc, sizeof(mem_ft));
	memset(src, 1, sizeof(mem_ft));
	res_ft = ft_memcpy(mem_ft, src, sizeof(mem_ft));
	res_lc = memcpy(mem_lc, src, sizeof(mem_ft));
	FT_TAP_IEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, memcmp(mem_ft, mem_lc, sizeof(mem_ft)) == 0);
}

static void	test_size_partial(t_tap *t)
{
	char	mem_ft[32];
	char	mem_lc[sizeof(mem_ft)];
	char	*res_ft;
	char	*res_lc;
	char	src[sizeof(mem_ft)];

	bzero(mem_ft, sizeof(mem_ft));
	bzero(mem_lc, sizeof(mem_ft));
	memset(src, 1, sizeof(mem_ft));
	res_ft = ft_memcpy(mem_ft, src + 3, sizeof(mem_ft) - 5);
	res_lc = memcpy(mem_lc, src + 3, sizeof(mem_ft) - 5);
	FT_TAP_IEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, memcmp(mem_ft, mem_lc, sizeof(mem_ft)) == 0);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_size_zero);
	FT_TAP_TEST(t, test_size_full);
	FT_TAP_TEST(t, test_size_partial);
}

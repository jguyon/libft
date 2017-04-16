/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:47:50 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 17:54:10 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_memory.h"
#include <string.h>

static void	test_overlap_left(t_tap *t)
{
	char	mem_ft[32];
	char	mem_lc[sizeof(mem_ft)];
	char	*res_ft;
	char	*res_lc;

	bzero(mem_ft, sizeof(mem_ft));
	bzero(mem_lc, sizeof(mem_ft));
	memset(mem_ft + sizeof(mem_ft) / 2, 1, sizeof(mem_ft) / 2);
	memset(mem_lc + sizeof(mem_ft) / 2, 1, sizeof(mem_ft) / 2);
	res_ft = ft_memmove(mem_ft, mem_ft + 3, sizeof(mem_ft) - 3);
	res_lc = ft_memmove(mem_lc, mem_lc + 3, sizeof(mem_ft) - 3);
	FT_TAP_IEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, memcmp(mem_ft, mem_lc, sizeof(mem_ft)) == 0);
}

static void	test_overlap_right(t_tap *t)
{
	char	mem_ft[32];
	char	mem_lc[sizeof(mem_ft)];
	char	*res_ft;
	char	*res_lc;

	bzero(mem_ft, sizeof(mem_ft));
	bzero(mem_lc, sizeof(mem_ft));
	memset(mem_ft + sizeof(mem_ft) / 2, 1, sizeof(mem_ft) / 2);
	memset(mem_lc + sizeof(mem_ft) / 2, 1, sizeof(mem_ft) / 2);
	res_ft = ft_memmove(mem_ft + 3, mem_ft, sizeof(mem_ft) - 3);
	res_lc = ft_memmove(mem_lc + 3, mem_lc, sizeof(mem_ft) - 3);
	FT_TAP_IEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, memcmp(mem_ft, mem_lc, sizeof(mem_ft)) == 0);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_overlap_left);
	FT_TAP_TEST(t, test_overlap_right);
}

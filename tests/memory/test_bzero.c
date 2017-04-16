/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:22:19 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 17:26:50 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_memory.h"
#include <string.h>

static void	test_size_zero(t_tap *t)
{
	char	mem_ft[16];
	char	mem_lc[sizeof(mem_ft)];

	memset(mem_ft, 1, sizeof(mem_ft));
	memset(mem_lc, 1, sizeof(mem_ft));
	ft_bzero(mem_ft, 0);
	bzero(mem_lc, 0);
	FT_TAP_OK(t, memcmp(mem_ft, mem_lc, sizeof(mem_ft)) == 0);
}

static void	test_size_full(t_tap *t)
{
	char	mem_ft[16];
	char	mem_lc[sizeof(mem_ft)];

	memset(mem_ft, 1, sizeof(mem_ft));
	memset(mem_lc, 1, sizeof(mem_ft));
	ft_bzero(mem_ft, sizeof(mem_ft));
	bzero(mem_lc, sizeof(mem_ft));
	FT_TAP_OK(t, memcmp(mem_ft, mem_lc, sizeof(mem_ft)) == 0);
}

static void	test_size_partial(t_tap *t)
{
	char	mem_ft[32];
	char	mem_lc[sizeof(mem_ft)];

	memset(mem_ft, 1, sizeof(mem_ft));
	memset(mem_lc, 1, sizeof(mem_ft));
	ft_bzero(mem_ft + 3, sizeof(mem_ft) - 5);
	bzero(mem_lc + 3, sizeof(mem_ft) - 5);
	FT_TAP_OK(t, memcmp(mem_ft, mem_lc, sizeof(mem_ft)) == 0);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_size_zero);
	FT_TAP_TEST(t, test_size_full);
	FT_TAP_TEST(t, test_size_partial);
}

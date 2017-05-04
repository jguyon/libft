/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memccpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:37:36 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 17:46:45 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_memory.h"
#include <string.h>

static void	test_found(t_tap *t)
{
	char	mem_ft[32];
	char	mem_lc[sizeof(mem_ft)];
	char	*res_ft;
	char	*res_lc;

	bzero(mem_ft, sizeof(mem_ft));
	bzero(mem_lc, sizeof(mem_ft));
	res_ft = ft_memccpy(mem_ft, "hello world", '\0', sizeof(mem_ft));
	res_lc = memccpy(mem_lc, "hello world", '\0', sizeof(mem_ft));
	FT_TAP_IEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, memcmp(mem_ft, mem_lc, sizeof(mem_ft)) == 0);
}

static void	test_not_found(t_tap *t)
{
	char	mem_ft[32];
	char	mem_lc[sizeof(mem_ft)];
	char	*res_ft;
	char	*res_lc;
	char	src[sizeof(mem_ft)];

	bzero(mem_ft, sizeof(mem_ft));
	bzero(mem_lc, sizeof(mem_ft));
	memset(src, 1, sizeof(mem_ft));
	res_ft = ft_memccpy(mem_ft, src, '\0', sizeof(mem_ft));
	res_lc = memccpy(mem_lc, src, '\0', sizeof(mem_ft));
	FT_TAP_OK(t, res_ft == NULL);
	FT_TAP_OK(t, res_ft == res_lc);
	FT_TAP_OK(t, memcmp(mem_ft, mem_lc, sizeof(mem_ft)) == 0);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_found);
	FT_TAP_TEST(t, test_not_found);
}

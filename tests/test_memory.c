/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:46:07 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/03 17:46:43 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_memory.h"
#include <string.h>

static void	test_memset(t_tap *t)
{
	char	mem_ft[200];
	char	mem_lc[200];
	char	*res_ft;
	char	*res_lc;

	bzero(mem_ft, sizeof(mem_ft));
	bzero(mem_lc, sizeof(mem_lc));
	ft_tap_plan(t, 4);
	res_ft = ft_memset(mem_ft, 1, 200);
	res_lc = memset(mem_lc, 1, 200);
	FT_TAP_UEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, !memcmp(mem_ft, mem_lc, 200));
	res_ft = ft_memset(mem_ft + 3, 2, 197);
	res_lc = memset(mem_lc + 3, 2, 197);
	FT_TAP_UEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, !memcmp(mem_ft, mem_lc, 200));
}

static void	test_bzero(t_tap *t)
{
	char	mem_ft[200];
	char	mem_lc[200];

	memset(mem_ft, 1, sizeof(mem_ft));
	memset(mem_lc, 1, sizeof(mem_lc));
	ft_tap_plan(t, 1);
	ft_bzero(mem_ft + 3, 194);
	bzero(mem_lc + 3, 194);
	FT_TAP_OK(t, !memcmp(mem_ft, mem_lc, 200));
}

static void	test_memcpy(t_tap *t)
{
	char	mem_ft[200];
	char	mem_lc[200];
	char	*res_ft;
	char	*res_lc;
	char	src[200];

	bzero(mem_ft, sizeof(mem_ft));
	bzero(mem_lc, sizeof(mem_lc));
	memset(src, 1, 100);
	memset(src + 100, 2, 100);
	ft_tap_plan(t, 4);
	res_ft = ft_memcpy(mem_ft, src, 200);
	res_lc = memcpy(mem_lc, src, 200);
	FT_TAP_UEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, !memcmp(mem_ft, mem_lc, 200));
	res_ft = ft_memcpy(mem_ft + 3, src, 197);
	res_lc = memcpy(mem_lc + 3, src, 197);
	FT_TAP_UEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, !memcmp(mem_ft, mem_lc, 200));
}

static void	test_memccpy(t_tap *t)
{
	char	mem_ft[256];
	char	mem_lc[256];
	char	*res_ft;
	char	*res_lc;
	char	src[256];

	ft_tap_plan(t, 4);
	bzero(mem_ft, sizeof(mem_ft));
	bzero(mem_lc, sizeof(mem_lc));
	bzero(src, sizeof(src));
	res_ft = ft_memccpy(mem_ft, "hello world", 'o', 12);
	res_lc = memccpy(mem_lc, "hello world", 'o', 12);
	FT_TAP_UEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, !memcmp(mem_ft, mem_lc, 256));
	bzero(mem_ft, sizeof(mem_ft));
	bzero(mem_lc, sizeof(mem_lc));
	memset(src, 'a', 256);
	src[197] = 'b';
	ft_memccpy(mem_ft, src, 'b', 243);
	memccpy(mem_lc, src, 'b', 243);
	FT_TAP_UEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, !memcmp(mem_ft, mem_lc, 256));
}

static void	test_memmove(t_tap *t)
{
	char	mem_ft[256];
	char	mem_lc[256];
	char	*res_ft;
	char	*res_lc;

	bzero(mem_ft, sizeof(mem_ft));
	bzero(mem_lc, sizeof(mem_lc));
	ft_tap_plan(t, 4);
	strcpy(mem_ft, "hello world hello world hello world");
	strcpy(mem_lc, "hello world hello world hello world");
	res_ft = ft_memmove(mem_ft, mem_ft + 3, 200);
	res_lc = memmove(mem_lc, mem_lc + 3, 200);
	FT_TAP_UEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, !memcmp(mem_ft, mem_lc, 256));
	res_ft = ft_memmove(mem_ft + 3, mem_ft, 200);
	res_lc = memmove(mem_lc + 3, mem_lc, 200);
	FT_TAP_UEQ(t, res_ft - mem_ft, res_lc - mem_lc);
	FT_TAP_OK(t, !memcmp(mem_ft, mem_lc, 256));
}

static void	test_memchr(t_tap *t)
{
	void	*mem = "abcdef\0ghijklmnopqrstuvwxyz0123456789";

	ft_tap_plan(t, 3);
	FT_TAP_UEQ(t, ft_memchr(mem, '0', 37) - mem, memchr(mem, '0', 37) - mem);
	FT_TAP_UEQ(t, ft_memchr(mem, '\0', 37) - mem, memchr(mem, '\0', 37) - mem);
	FT_TAP_UEQ(t, ft_memchr(mem, '@', 37) - mem, memchr(mem, '@', 37) - mem);
}

static void	test_memcmp(t_tap *t)
{
	char	*mem = "abcdef\0ghijklmnopqrstuvwxyz0123456789";
	char	cmp[37];

	memcpy(cmp, mem, 37);
	ft_tap_plan(t, 3);
	FT_TAP_IEQ(t, ft_memcmp(mem, cmp, 37), memcmp(mem, cmp, 37));
	--cmp[20];
	FT_TAP_IEQ(t, ft_memcmp(mem, cmp, 37), memcmp(mem, cmp, 37));
	++cmp[6];
	FT_TAP_IEQ(t, ft_memcmp(mem, cmp, 37), memcmp(mem, cmp, 37));
}

void		test_memory(t_tap *t)
{
	FT_TAP_TEST(t, test_memset);
	FT_TAP_TEST(t, test_bzero);
	FT_TAP_TEST(t, test_memcpy);
	FT_TAP_TEST(t, test_memccpy);
	FT_TAP_TEST(t, test_memmove);
	FT_TAP_TEST(t, test_memchr);
	FT_TAP_TEST(t, test_memcmp);
}

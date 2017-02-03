/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:38:49 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/03 22:22:59 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>

static void	printf_cmp(t_tap *t, const char *format, ...)
{
	int		res_ft;
	int		res_lc;
	char	str_ft[4096];
	char	str_lc[4096];
	va_list	args_ft;
	va_list	args_lc;

	va_start(args_ft, format);
	va_copy(args_lc, args_ft);
	res_ft = ft_vsnprintf(str_ft, sizeof(str_ft), format, args_ft);
	res_lc = vsnprintf(str_lc, sizeof(str_lc), format, args_lc);
	va_end(args_ft);
	va_end(args_lc);
	FT_TAP_IEQ(t, res_ft, res_lc);
	if (res_ft > 0 && res_lc > 0)
		FT_TAP_SEQ(t, str_ft, str_lc);
}

static void	printf_eq(t_tap *t, int res, const char *str,
				const char *format, ...)
{
	int		res_ft;
	char	str_ft[4096];
	va_list	args;

	va_start(args, format);
	res_ft = ft_vsnprintf(str_ft, sizeof(str_ft), format, args);
	va_end(args);
	FT_TAP_IEQ(t, res_ft, res);
	if (res_ft > 0 && res > 0)
		FT_TAP_SEQ(t, str_ft, str);
}

static void	test_basics(t_tap *t)
{
	printf_cmp(t, "");
	printf_cmp(t, "hello");
	printf_cmp(t, "I\nhave\tescaped\vchars");
	printf_cmp(t, "%% // %% // %%");
}

static void	test_args(t_tap *t)
{
	printf_cmp(t, "%*s // %*s", 10, "hello", -10, "hello");
	printf_cmp(t, "%.*s // %.*s", 3, "hello", -3, "hello");
	printf_cmp(t, "%*.*s // %*.*s", 10, 3, "hello", -10, 3, "hello");
}

static void	test_err(t_tap *t)
{
	printf_eq(t, -1, NULL, "%");
	printf_eq(t, -1, NULL, "%a", 12);
	printf_eq(t, -1, NULL, "%0llj", 12);
}

static void	test_strs(t_tap *t)
{
	setlocale(LC_ALL, "");

	printf_cmp(t, "%s // %s", "Hello, world!", NULL);
	printf_cmp(t, "%10s // %10s // %10s", "hello", "hellohello", "hellohellohello");
	printf_cmp(t, "%.s // %.10s // %.10s // %.10s", "hello", "hello", "hellohello", "hellohellohello");
	printf_cmp(t, "%10.5s // %10.5s", "hello", "hellohello");
	printf_cmp(t, "%-s // %-10s", "hello", "hello");
	printf_cmp(t, "%ls // %10ls // %.5ls", L"$¢€", L"$¢€", L"$¢€");
	printf_cmp(t, "%c // %c", 'h', '\0');
	printf_cmp(t, "%10c // %1c", 'h', 'a');
	printf_cmp(t, "%10lc // %10lc", L'€', L'h');
}

static void	test_ints(t_tap *t)
{
	printf_cmp(t, "%d // %d // %d", 42, -42, 0);
	printf_cmp(t, "%d // %d // %d // %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN);
	printf_cmp(t, "%hhd // %hhd // %hhd // %hhd", SCHAR_MAX, SCHAR_MIN, SHRT_MAX, SHRT_MIN);
	printf_cmp(t, "%hd // %hd // %hd // %hd", SHRT_MAX, SHRT_MIN, INT_MAX, INT_MIN);
	printf_cmp(t, "%ld // %ld // %ld // %ld", LONG_MAX, LONG_MIN, LLONG_MAX, LLONG_MIN);
	printf_cmp(t, "%lld // %lld // %lld // %lld", LLONG_MAX, LLONG_MIN, INTMAX_MAX, INTMAX_MIN);
	printf_cmp(t, "%jd // %jd", INTMAX_MAX, INTMAX_MIN);
	printf_cmp(t, "%zd // %zd", SSIZE_MAX, INTMAX_MIN);
	printf_cmp(t, "%5d // %5d // %5d", 42, -42, INT_MAX);
	printf_cmp(t, "%.5d // %.5d // %.5d", 42, -42, INT_MAX);
	printf_cmp(t, ".d // .d", 42, 0);
	printf_cmp(t, "%5.5d // %5.5d // %5.5d", 42, -42, INT_MAX);
	printf_cmp(t, "%-5d // %-5d // %-5d", 42, -42, INT_MAX);
	printf_cmp(t, "%05d // %05d // %05d", 42, -42, INT_MAX);
	printf_cmp(t, "%0-5d // %0-5d // %0-5d", 42, -42, INT_MAX);
	printf_cmp(t, "%+d // %+d", 42, -42);
	printf_cmp(t, "% d // % d", 42, -42);
	printf_cmp(t, "%+ d // %+ d", 42, -42);
	printf_cmp(t, "%0+22.12hhi", 42);
	printf_cmp(t, "%u // %u // %u", 42, -42, 0);
	printf_cmp(t, "%u // %u", UINT_MAX, ULONG_MAX);
	printf_cmp(t, "%hhu // %hhu", UCHAR_MAX, USHRT_MAX);
	printf_cmp(t, "%hu // %hu", USHRT_MAX, UINT_MAX);
	printf_cmp(t, "%lu // %lu", ULONG_MAX, ULLONG_MAX);
	printf_cmp(t, "%llu // %llu", ULLONG_MAX, UINTMAX_MAX);
	printf_cmp(t, "%ju", UINTMAX_MAX);
	printf_cmp(t, "%zu // %zu", SIZE_MAX, INT_MIN);
	printf_cmp(t, "%0 22.12hhu", 42);
	printf_cmp(t, "%+o // %#o // %.5o // %#.5o", 42, 42, 42, 42);
	printf_cmp(t, "%#o // %#.5o // %#.2o", 0, 0, 42);
	printf_cmp(t, "%+x // %#X // %.5X // %#.5X", 42, 42, 42, 42);
	printf_cmp(t, "%p // %10.5p", "hello", "hello");
	printf_eq(t, 3, "0x0", "%p", NULL);
}

static void	test_ptrs(t_tap *t)
{
	int			n;
	long		ln;
	long long	lln;
	short		hn;
	signed char	hhn;
	intmax_t	jn;
	ssize_t		zn;

	printf_eq(t, 12, "hello  world", "hello %n world", &n);
	FT_TAP_IEQ(t, n, 6);
	printf_eq(t, 12, "hello  world", "hello %ln world", &ln);
	FT_TAP_IEQ(t, ln, 6);
	printf_eq(t, 12, "hello  world", "hello %lln world", &lln);
	FT_TAP_IEQ(t, lln, 6);
	printf_eq(t, 12, "hello  world", "hello %hn world", &hn);
	FT_TAP_IEQ(t, hn, 6);
	printf_eq(t, 12, "hello  world", "hello %hhn world", &hhn);
	FT_TAP_IEQ(t, hhn, 6);
	printf_eq(t, 12, "hello  world", "hello %jn world", &jn);
	FT_TAP_IEQ(t, jn, 6);
	printf_eq(t, 12, "hello  world", "hello %zn world", &zn);
	FT_TAP_IEQ(t, zn, 6);
}

void		test_printf(t_tap *t)
{
	FT_TAP_TEST(t, test_basics);
	FT_TAP_TEST(t, test_args);
	FT_TAP_TEST(t, test_err);
	FT_TAP_TEST(t, test_strs);
	FT_TAP_TEST(t, test_ints);
	FT_TAP_TEST(t, test_ptrs);
}

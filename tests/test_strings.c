/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:51:30 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/05 00:35:51 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "test_libft.h"
#include "ft_strings.h"
#include <stdlib.h>
#include <string.h>

static void	test_strlen(t_tap *t)
{
	char	str[256];

	ft_tap_plan(t, 4);
	strcpy(str, "hello");
	FT_TAP_UEQ(t, ft_strlen(str), strlen(str));
	strcpy(str, "hello world hello world hello world hello world");
	FT_TAP_UEQ(t, ft_strlen(str), strlen(str));
	strcpy(str, "");
	FT_TAP_UEQ(t, ft_strlen(str), strlen(str));
	strcpy(str, "hello world");
	FT_TAP_UEQ(t, ft_strlen(str), strlen(str));
}

static void	test_strnlen(t_tap *t)
{
	char	str[256];

	ft_tap_plan(t, 2);
	strcpy(str, "hello world hello world hello world hello world hello world");
	FT_TAP_UEQ(t, ft_strnlen(str, 256), strnlen(str, 256));
	FT_TAP_UEQ(t, ft_strnlen(str + 1, 17), strnlen(str + 1, 17));
}

static void	test_strdup(t_tap *t)
{
	char	*str_ft;
	char	*str_lc;

	ft_tap_plan(t, 3);
	str_ft = ft_strdup("qwertyuiopasdfghjklzxcvbnm0123456789");
	str_lc = strdup("qwertyuiopasdfghjklzxcvbnm0123456789");
	FT_TAP_OK(t, !strcmp(str_ft, str_lc));
	free(str_ft);
	free(str_lc);
	str_ft = ft_strdup("hello");
	str_lc = strdup("hello");
	FT_TAP_OK(t, !strcmp(str_ft, str_lc));
	free(str_ft);
	free(str_lc);
	str_ft = ft_strdup("");
	str_lc = strdup("");
	FT_TAP_OK(t, !strcmp(str_ft, str_lc));
	free(str_ft);
	free(str_lc);
}

static void	test_strcpy(t_tap *t)
{
	char	str_ft[256];
	char	str_lc[256];
	char	*res_ft;
	char	*res_lc;
	char	*src = "qwertyuiopasdfghjklzxcvbnm0123456789";

	memset(str_ft, 'a', sizeof(str_ft));
	memset(str_lc, 'a', sizeof(str_lc));
	ft_tap_plan(t, 6);
	res_ft = ft_strcpy(str_ft, src);
	res_lc = strcpy(str_lc, src);
	FT_TAP_UEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
	res_ft = ft_strcpy(str_ft, src + 30);
	res_lc = strcpy(str_lc, src + 30);
	FT_TAP_UEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
	res_ft = ft_strcpy(str_ft, src + 36);
	res_lc = strcpy(str_lc, src + 36);
	FT_TAP_UEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
}

static void	test_strncpy(t_tap *t)
{
	char	str_ft[256];
	char	str_lc[256];
	char	*res_ft;
	char	*res_lc;
	char	*src = "qwertyuiopasdfghjklzxcvbnm0123456789";

	memset(str_ft, 'a', sizeof(str_ft));
	memset(str_lc, 'a', sizeof(str_lc));
	ft_tap_plan(t, 6);
	res_ft = ft_strncpy(str_ft, src, 30);
	res_lc = strncpy(str_lc, src, 30);
	FT_TAP_UEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
	res_ft = ft_strncpy(str_ft, src + 30, 6);
	res_lc = strncpy(str_lc, src + 30, 6);
	FT_TAP_UEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
	res_ft = ft_strncpy(str_ft, src + 36, 3);
	res_lc = strncpy(str_lc, src + 36, 3);
	FT_TAP_UEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
}

static void	test_strcat(t_tap *t)
{
	char	str_ft[256];
	char	str_lc[256];
	char	*res_ft;
	char	*res_lc;
	char	*src = "qwertyuiopasdfghjklzxcvbnm0123456789";

	bzero(str_ft, sizeof(str_ft));
	bzero(str_lc, sizeof(str_lc));
	ft_tap_plan(t, 6);
	res_ft = ft_strcat(str_ft, src);
	res_lc = strcat(str_lc, src);
	FT_TAP_UEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
	res_ft = ft_strcat(str_ft, src + 30);
	res_lc = strcat(str_lc, src + 30);
	FT_TAP_UEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
	res_ft = ft_strcat(str_ft, src + 36);
	res_lc = strcat(str_lc, src + 36);
	FT_TAP_UEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
}

static void	test_strncat(t_tap *t)
{
	char	str_ft[256];
	char	str_lc[256];
	char	*res_ft;
	char	*res_lc;
	char	*src = "qwertyuiopasdfghjklzxcvbnm0123456789";

	bzero(str_ft, sizeof(str_ft));
	bzero(str_lc, sizeof(str_lc));
	ft_tap_plan(t, 4);
	res_ft = ft_strncat(str_ft, src, 40);
	res_lc = strncat(str_lc, src, 40);
	FT_TAP_UEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
	res_ft = ft_strncat(str_ft, src, 30);
	res_lc = strncat(str_lc, src, 30);
	FT_TAP_UEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
}

#ifdef linux
static size_t	strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dlen;

	d = dst;
	s = src;
	n = size;
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = size - dlen;

	if (n == 0)
		return (dlen + strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*(d++) = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
#endif

void		test_strlcat(t_tap *t)
{
	char	str_ft[256];
	char	str_lc[256];
	size_t	res_ft;
	size_t	res_lc;
	char	*src = "qwertyuiopasdfghjklzxcvbnm0123456789";

	bzero(str_ft, sizeof(str_ft));
	bzero(str_lc, sizeof(str_lc));
	ft_tap_plan(t, 6);
	res_ft = ft_strlcat(str_ft, src, 37);
	res_lc = strlcat(str_lc, src, 37);
	FT_TAP_UEQ(t, res_ft, res_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
	res_ft = ft_strlcat(str_ft, src, 47);
	res_lc = strlcat(str_lc, src, 47);
	FT_TAP_UEQ(t, res_ft, res_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
	res_ft = ft_strlcat(str_ft, src, 256);
	res_lc = strlcat(str_lc, src, 256);
	FT_TAP_UEQ(t, res_ft, res_lc);
	FT_TAP_OK(t, !memcmp(str_ft, str_lc, 256));
}

#ifdef __APPLE__
static char	*strchrnul(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s && *s != c)
		++s;
	return ((char *)s);
}
#endif

void		test_strchrnul(t_tap *t)
{
	char	*str = "qwertyuiopasdfghjklzxcvbnm0123456789";

	ft_tap_plan(t, 4);
	FT_TAP_UEQ(t, ft_strchrnul(str, 't') - str, strchrnul(str, 't') - str);
	FT_TAP_UEQ(t, ft_strchrnul(str, '7') - str, strchrnul(str, '7') - str);
	FT_TAP_UEQ(t, ft_strchrnul(str, '\0') - str, strchrnul(str, '\0') - str);
	FT_TAP_UEQ(t, ft_strchrnul(str, '$') - str, strchrnul(str, '$') - str);
}

void		test_strchr(t_tap *t)
{
	char	*str = "qwertyuiopasdfghjklzxcvbnm0123456789";

	ft_tap_plan(t, 4);
	FT_TAP_UEQ(t, ft_strchr(str, 't') - str, strchr(str, 't') - str);
	FT_TAP_UEQ(t, ft_strchr(str, '7') - str, strchr(str, '7') - str);
	FT_TAP_UEQ(t, ft_strchr(str, '\0') - str, strchr(str, '\0') - str);
	FT_TAP_UEQ(t, ft_strchr(str, '$') - str, strchr(str, '$') - str);
}

void		test_strrchr(t_tap *t)
{
	char	*str = "qwertyuiopasdfghjklzxcvbnm0123456789";

	ft_tap_plan(t, 4);
	FT_TAP_UEQ(t, ft_strrchr(str, 't') - str, strrchr(str, 't') - str);
	FT_TAP_UEQ(t, ft_strrchr(str, '7') - str, strrchr(str, '7') - str);
	FT_TAP_UEQ(t, ft_strrchr(str, '\0') - str, strrchr(str, '\0') - str);
	FT_TAP_UEQ(t, ft_strrchr(str, '$') - str, strrchr(str, '$') - str);
}

void		test_strcmp(t_tap *t)
{
	char	*str = "qwertyuiopasdfghjklzxcvbnm0123456789";
	char	cpy[38];

	strcpy(cpy, str);
	ft_tap_plan(t, 6);
	FT_TAP_OK(t, ft_strcmp(str, cpy) == 0 && strcmp(str, cpy) == 0);
	cpy[28] = '~';
	FT_TAP_OK(t, ft_strcmp(str, cpy) < 0 && strcmp(str, cpy) < 0);
	cpy[4] = '\0';
	FT_TAP_OK(t, ft_strcmp(str, cpy) > 0 && strcmp(str, cpy) > 0);
	strcpy(cpy + 1, str);
	FT_TAP_OK(t, ft_strcmp(str, cpy + 1) == 0 && strcmp(str, cpy + 1) == 0);
	cpy[29] = '~';
	FT_TAP_OK(t, ft_strcmp(str, cpy + 1) < 0 && strcmp(str, cpy + 1) < 0);
	cpy[5] = '\0';
	FT_TAP_OK(t, ft_strcmp(str, cpy + 1) > 0 && strcmp(str, cpy + 1) > 0);
}

void		test_strncmp(t_tap *t)
{
	char	*str = "qwertyuiopasdfghjklzxcvbnm0123456789";
	char	cpy[38];

	strcpy(cpy, str);
	ft_tap_plan(t, 8);
	FT_TAP_OK(t, ft_strncmp(str, cpy, 38) == 0 && strncmp(str, cpy, 38) == 0);
	FT_TAP_OK(t, ft_strncmp(str, cpy, 5) == 0 && strncmp(str, cpy, 5) == 0);
	cpy[28] = '~';
	FT_TAP_OK(t, ft_strncmp(str, cpy, 28) == 0 && strncmp(str, cpy, 28) == 0);
	FT_TAP_OK(t, ft_strncmp(str, cpy, 29) < 0 && strncmp(str, cpy, 29) < 0);
	cpy[4] = '\0';
	FT_TAP_OK(t, ft_strncmp(str, cpy, 4) == 0 && strncmp(str, cpy, 4) == 0);
	FT_TAP_OK(t, ft_strncmp(str, cpy, 5) > 0 && strncmp(str, cpy, 5) > 0);
	strcpy(cpy + 1, str);
	FT_TAP_OK(t, ft_strncmp(str, cpy + 1, 37) == 0
		&& strncmp(str, cpy + 1, 37) == 0);
	FT_TAP_OK(t, ft_strncmp(str, cpy + 1, 5) == 0
		&& strncmp(str, cpy + 1, 5) == 0);
}

void		test_strstr(t_tap *t)
{
	char	str[256] = "qwertyuiopasdfghjklzxcvbnm0123456789q";

	ft_tap_plan(t, 5);
	FT_TAP_UEQ(t, ft_strstr(str, "012") - str, strstr(str, "012") - str);
	FT_TAP_UEQ(t, ft_strstr(str, "0124") - str, strstr(str, "0124") - str);
	FT_TAP_UEQ(t, ft_strstr(str, "qz") - str, strstr(str, "qz") - str);
	FT_TAP_UEQ(t, ft_strstr(str, "") - str, strstr(str, "") - str);
	FT_TAP_UEQ(t, ft_strstr(str, "qw") - str, strstr(str, "qw") - str);
}

#ifdef linux
static char	*strnstr(const char *s, const char *find, size_t slen)
{
	char	c;
	char	sc;
	size_t	len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if ((sc = *s++) == '\0' || slen-- < 1)
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}
#endif

void		test_strnstr(t_tap *t)
{
	char	str[256] = "qwertyuiopasdfghjklzxcvbnm0123456789";

	ft_tap_plan(t, 3);
	FT_TAP_UEQ(t, ft_strnstr(str, "0123456789", 36) - str,
			   strnstr(str, "0123456789", 36) - str);
	FT_TAP_UEQ(t, ft_strnstr(str, "0123456789", 35) - str,
			   strnstr(str, "0123456789", 35) - str);
	FT_TAP_UEQ(t, ft_strnstr(str, "0123456789", 25) - str,
			   strnstr(str, "0123456789", 25) - str);
}

void		test_strclr(t_tap *t)
{
	char	str[256] = "qwertyuiopasdfghjklzxcvbnm0123456789";
	char	zro[256];

	bzero(zro, sizeof(zro));
	ft_tap_plan(t, 1);
	ft_strclr(str);
	FT_TAP_OK(t, !memcmp(str, zro, 36));
}

void		test_strjoin(t_tap *t)
{
	char	s1[] = "qwertyuiopasdfghjklzxcvbnm";
	char	s2[] = "0123456789";
	char	*join = NULL;

	ft_tap_plan(t, 2);
	join = ft_strjoin(s1, s2);
	FT_TAP_OK(t, !memcmp(s1, join, 26));
	FT_TAP_OK(t, !memcmp(s2, join + 26, 11));
	free(join);
}

void		test_strsub(t_tap *t)
{
	char	str[] = "qwertyuiopasdfghjklzxcvbnm0123456789";
	char	*sub = NULL;

	ft_tap_plan(t, 1);
	sub = ft_strsub(str, 3, 31);
	FT_TAP_OK(t, !memcmp(sub, str + 3, 31));
	free(sub);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_strlen);
	FT_TAP_TEST(t, test_strnlen);
	FT_TAP_TEST(t, test_strdup);
	FT_TAP_TEST(t, test_strcpy);
	FT_TAP_TEST(t, test_strncpy);
	FT_TAP_TEST(t, test_strcat);
	FT_TAP_TEST(t, test_strncat);
	FT_TAP_TEST(t, test_strlcat);
	FT_TAP_TEST(t, test_strchrnul);
	FT_TAP_TEST(t, test_strchr);
	FT_TAP_TEST(t, test_strrchr);
	FT_TAP_TEST(t, test_strcmp);
	FT_TAP_TEST(t, test_strncmp);
	FT_TAP_TEST(t, test_strstr);
	FT_TAP_TEST(t, test_strnstr);
	FT_TAP_TEST(t, test_strclr);
	FT_TAP_TEST(t, test_strjoin);
	FT_TAP_TEST(t, test_strsub);
}

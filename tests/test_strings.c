/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:59:10 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/03 17:48:43 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

TFT_TEST(test_strlen)
{
	char	str[256] = {0};

	strcpy(str, "hello");
	TFT_ASSERT(ft_strlen(str) == strlen(str));
	strcpy(str, "hello world hello world hello world hello world");
	TFT_ASSERT(ft_strlen(str) == strlen(str));
	strcpy(str, "");
	TFT_ASSERT(ft_strlen(str) == strlen(str));
	strcpy(str, "hello world");
	TFT_ASSERT(ft_strlen(str) == strlen(str));
}

TFT_TEST(test_strnlen)
{
	char	str[256] = {0};

	strcpy(str, "hello world hello world hello world hello world hello world");
	TFT_ASSERT(ft_strnlen(str, 256) == strnlen(str, 256));
	TFT_ASSERT(ft_strnlen(str + 1, 17) == strnlen(str + 1, 17));
}

TFT_TEST(test_strdup)
{
	char	*str_ft;
	char	*str_lc;

	str_ft = ft_strdup("qwertyuiopasdfghjklzxcvbnm0123456789");
	str_lc = strdup("qwertyuiopasdfghjklzxcvbnm0123456789");
	TFT_ASSERT(strcmp(str_ft, str_lc) == 0);
	free(str_ft);
	free(str_lc);
	str_ft = ft_strdup("hello");
	str_lc = strdup("hello");
	TFT_ASSERT(strcmp(str_ft, str_lc) == 0);
	free(str_ft);
	free(str_lc);
	str_ft = ft_strdup("");
	str_lc = strdup("");
	TFT_ASSERT(strcmp(str_ft, str_lc) == 0);
	free(str_ft);
	free(str_lc);
}

TFT_TEST(test_strcpy)
{
	char	str_ft[256];
	char	str_lc[256];
	char	*src = "qwertyuiopasdfghjklzxcvbnm0123456789";

	TFT_ASSERT(strcmp(ft_strcpy(str_ft, src), strcpy(str_lc, src)) == 0);
	TFT_ASSERT(strcmp(ft_strcpy(str_ft, src + 30), strcpy(str_lc, src + 30)) == 0);
	TFT_ASSERT(strcmp(ft_strcpy(str_ft, src + 36), strcpy(str_lc, src + 36)) == 0);
}

TFT_TEST(test_strncpy)
{
	char	str_ft[256];
	char	str_lc[256];
	char	*src = "qwertyuiopasdfghjklzxcvbnm0123456789";

	memset(str_ft, 'a', 256);
	memset(str_lc, 'a', 256);
	TFT_ASSERT(memcmp(ft_strncpy(str_ft, src, 30), strncpy(str_lc, src, 30), 256) == 0);
	memset(str_ft, 'a', 256);
	memset(str_lc, 'a', 256);
	TFT_ASSERT(memcmp(ft_strncpy(str_ft, src + 30, 6), strncpy(str_lc, src + 30, 6), 256) == 0);
	memset(str_ft, 'a', 256);
	memset(str_lc, 'a', 256);
	TFT_ASSERT(memcmp(ft_strncpy(str_ft, src + 36, 3), strncpy(str_lc, src + 36, 3), 256) == 0);
}

TFT_TEST(test_strcat)
{
	char	str_ft[256] = {0};
	char	str_lc[256] = {0};
	char	*src = "qwertyuiopasdfghjklzxcvbnm0123456789";

	TFT_ASSERT(strcmp(ft_strcat(str_ft, src), strcat(str_lc, src)) == 0);
	TFT_ASSERT(strcmp(ft_strcat(str_ft, src), strcat(str_lc, src)) == 0);
	TFT_ASSERT(strcmp(ft_strcat(str_ft, ""), strcat(str_lc, "")) == 0);
}

TFT_TEST(test_strncat)
{
	char	str_ft[256] = {0};
	char	str_lc[256] = {0};
	char	*src = "qwertyuiopasdfghjklzxcvbnm0123456789";

	TFT_ASSERT(strcmp(ft_strncat(str_ft, src, 40), strncat(str_lc, src, 40)) == 0);
	TFT_ASSERT(strcmp(ft_strncat(str_ft, src, 30), strncat(str_lc, src, 30)) == 0);
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

TFT_TEST(test_strlcat)
{
	char	str_ft[256] = {0};
	char	str_lc[256] = {0};
	char	*src = "qwertyuiopasdfghjklzxcvbnm0123456789";

	TFT_ASSERT(ft_strlcat(str_ft, src, 37) == strlcat(str_lc, src, 37));
	TFT_ASSERT(strcmp(str_ft, str_lc) == 0);
	TFT_ASSERT(ft_strlcat(str_ft, src, 47) == strlcat(str_lc, src, 47));
	TFT_ASSERT(strcmp(str_ft, str_lc) == 0);
	TFT_ASSERT(ft_strlcat(str_ft, src, 256) == strlcat(str_lc, src, 256));
	TFT_ASSERT(strcmp(str_ft, str_lc) == 0);
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

TFT_TEST(test_strchrnul)
{
	char	*str = "qwertyuiopasdfghjklzxcvbnm0123456789";

	TFT_ASSERT(ft_strchrnul(str, 't') == strchrnul(str, 't'));
	TFT_ASSERT(ft_strchrnul(str, '7') == strchrnul(str, '7'));
	TFT_ASSERT(ft_strchrnul(str, '\0') == strchrnul(str, '\0'));
	TFT_ASSERT(ft_strchrnul(str, '$') == strchrnul(str, '$'));
}

TFT_TEST(test_strchr)
{
	char	*str = "qwertyuiopasdfghjklzxcvbnm0123456789";

	TFT_ASSERT(ft_strchr(str, 't') == strchr(str, 't'));
	TFT_ASSERT(ft_strchr(str, '7') == strchr(str, '7'));
	TFT_ASSERT(ft_strchr(str, '\0') == strchr(str, '\0'));
	TFT_ASSERT(ft_strchr(str, '$') == strchr(str, '$'));
}

TFT_TEST(test_strrchr)
{
	char	*str = "qwertyuiopasdfghjklzxcvbnm0123456789q";

	TFT_ASSERT(ft_strrchr(str, 't') == strrchr(str, 't'));
	TFT_ASSERT(ft_strrchr(str, '7') == strrchr(str, '7'));
	TFT_ASSERT(ft_strrchr(str, '\0') == strrchr(str, '\0'));
	TFT_ASSERT(ft_strrchr(str, '$') == strrchr(str, '$'));
	TFT_ASSERT(ft_strrchr(str, 'q') == strrchr(str, 'q'));
}

TFT_TEST(test_strcmp)
{
	char	*str = "qwertyuiopasdfghjklzxcvbnm0123456789";
	char	cpy[38];

	strcpy(cpy, str);
	TFT_ASSERT(ft_strcmp(str, cpy) == 0 && strcmp(str, cpy) == 0);
	cpy[28] = '~';
	TFT_ASSERT(ft_strcmp(str, cpy) < 0 && strcmp(str, cpy) < 0);
	cpy[4] = '\0';
	TFT_ASSERT(ft_strcmp(str, cpy) > 0 && strcmp(str, cpy) > 0);
	strcpy(cpy + 1, str);
	TFT_ASSERT(ft_strcmp(str, cpy + 1) == 0 && strcmp(str, cpy + 1) == 0);
	cpy[29] = '~';
	TFT_ASSERT(ft_strcmp(str, cpy + 1) < 0 && strcmp(str, cpy + 1) < 0);
	cpy[5] = '\0';
	TFT_ASSERT(ft_strcmp(str, cpy + 1) > 0 && strcmp(str, cpy + 1) > 0);
}

TFT_TEST(test_strncmp)
{
	char	str[37] = "qwertyuiopasdfghjklzxcvbnm0123456789";
	char	cpy[38];

	strcpy(cpy, str);
	TFT_ASSERT(ft_strncmp(str, cpy, 38) == 0 && strncmp(str, cpy, 38) == 0);
	TFT_ASSERT(ft_strncmp(str, cpy, 5) == 0 && strncmp(str, cpy, 5) == 0);
	cpy[28] = '~';
	TFT_ASSERT(ft_strncmp(str, cpy, 28) == 0 && strncmp(str, cpy, 28) == 0);
	TFT_ASSERT(ft_strncmp(str, cpy, 29) < 0 && strncmp(str, cpy, 29) < 0);
	cpy[4] = '\0';
	TFT_ASSERT(ft_strncmp(str, cpy, 4) == 0 && strncmp(str, cpy, 4) == 0);
	TFT_ASSERT(ft_strncmp(str, cpy, 5) > 0 && strncmp(str, cpy, 5) > 0);
	strcpy(cpy + 1, str);
	TFT_ASSERT(ft_strncmp(str, cpy + 1, 37) == 0 && strncmp(str, cpy + 1, 37) == 0);
	TFT_ASSERT(ft_strncmp(str, cpy + 1, 5) == 0 && strncmp(str, cpy + 1, 5) == 0);
	cpy[29] = '~';
	TFT_ASSERT(ft_strncmp(str, cpy + 1, 28) == 0 && strncmp(str, cpy + 1, 28) == 0);
	TFT_ASSERT(ft_strncmp(str, cpy + 1, 29) < 0 && strncmp(str, cpy + 1, 29) < 0);
	cpy[5] = '\0';
	TFT_ASSERT(ft_strncmp(str, cpy + 1, 4) == 0 && strncmp(str, cpy + 1, 4) == 0);
	TFT_ASSERT(ft_strncmp(str, cpy + 1, 5) > 0 && strncmp(str, cpy + 1, 5) > 0);
}

TFT_TEST(test_strstr)
{
	char	str[256] = "qwertyuiopasdfghjklzxcvbnm0123456789q";

	TFT_ASSERT(ft_strstr(str, "012") == strstr(str, "012"));
	TFT_ASSERT(ft_strstr(str, "0124") == strstr(str, "0124"));
	TFT_ASSERT(ft_strstr(str, "qz") == strstr(str, "qz"));
	TFT_ASSERT(ft_strstr(str, "") == strstr(str, ""));
	TFT_ASSERT(ft_strstr(str, "qw") == strstr(str, "qw"));
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

TFT_TEST(test_strnstr)
{
	char	str[256] = "qwertyuiopasdfghjklzxcvbnm0123456789";

	TFT_ASSERT(ft_strnstr(str, "0123456789", 36) == strnstr(str, "0123456789", 36));
	TFT_ASSERT(ft_strnstr(str, "0123456789", 35) == strnstr(str, "0123456789", 35));
	TFT_ASSERT(ft_strnstr(str, "0123456789", 25) == strnstr(str, "0123456789", 25));
}

TFT_TEST(test_strclr)
{
	char	str[] = "qwertyuiopasdfghjklzxcvbnm0123456789";
	char	zro[256] = {0};

	ft_strclr(str);
	TFT_ASSERT(memcmp(str, zro, 36) == 0);
}

TFT_TEST(test_strjoin)
{
	char	s1[] = "qwertyuiopasdfghjklzxcvbnm";
	char	s2[] = "0123456789";
	char	*join = NULL;

	join = ft_strjoin(s1, s2);
	TFT_ASSERT(memcmp(s1, join, 26) == 0);
	TFT_ASSERT(memcmp(s2, join + 26, 11) == 0);
	free(join);
}

TFT_TEST(test_strsub)
{
	char	str[] = "qwertyuiopasdfghjklzxcvbnm0123456789";
	char	*sub = NULL;

	sub = ft_strsub(str, 3, 31);
	TFT_ASSERT(ft_memcmp(sub, str + 3, 31) == 0);
	free(sub);
}

void	test_strings(void)
{
	TFT_RUN(test_strlen);
	TFT_RUN(test_strnlen);
	TFT_RUN(test_strdup);
	TFT_RUN(test_strcpy);
	TFT_RUN(test_strncpy);
	TFT_RUN(test_strcat);
	TFT_RUN(test_strncat);
	TFT_RUN(test_strlcat);
	TFT_RUN(test_strchrnul);
	TFT_RUN(test_strchr);
	TFT_RUN(test_strrchr);
	TFT_RUN(test_strcmp);
	TFT_RUN(test_strncmp);
	TFT_RUN(test_strstr);
	TFT_RUN(test_strnstr);
	TFT_RUN(test_strclr);
	TFT_RUN(test_strjoin);
	TFT_RUN(test_strsub);
}

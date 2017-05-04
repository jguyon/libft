/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:24:18 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 19:31:01 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"
#include <string.h>

static void	test_from_empty(t_tap *t)
{
	char	str[32];
	size_t	res;
	char	src[] = "";

	strcpy(str, "hello world");
	res = ft_strlcat(str, src, sizeof(str));
	FT_TAP_UEQ(t, res, 11);
	FT_TAP_SEQ(t, str, "hello world");
}

static void	test_to_empty(t_tap *t)
{
	char	str[32];
	size_t	res;
	char	src[] = "hello world";

	strcpy(str, "");
	res = ft_strlcat(str, src, sizeof(str));
	FT_TAP_UEQ(t, res, 11);
	FT_TAP_SEQ(t, str, "hello world");
}

static void	test_lower(t_tap *t)
{
	char	str[32];
	size_t	res;
	char	src[] = "hello world";

	strcpy(str, "hello");
	res = ft_strlcat(str, src, sizeof(str));
	FT_TAP_UEQ(t, res, 16);
	FT_TAP_SEQ(t, str, "hellohello world");
}

static void	test_greater(t_tap *t)
{
	char	str[32];
	size_t	res;
	char	src[] = "hello world";

	strcpy(str, "hello");
	res = ft_strlcat(str, src, 10);
	FT_TAP_UEQ(t, res, 16);
	FT_TAP_SEQ(t, str, "hellohell");
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_from_empty);
	FT_TAP_TEST(t, test_to_empty);
	FT_TAP_TEST(t, test_lower);
	FT_TAP_TEST(t, test_greater);
}

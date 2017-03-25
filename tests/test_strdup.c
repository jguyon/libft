/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:34:12 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 18:38:03 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"
#include <stdlib.h>

static void	test_empty(t_tap *t)
{
	char	src[] = "";
	char	*str;

	str = ft_strdup(src);
	FT_TAP_OK(t, str != NULL);
	FT_TAP_SEQ(t, str, src);
	free(str);
}

static void	test_non_empty(t_tap *t)
{
	char	src[] = "hello world";
	char	*str;

	str = ft_strdup(src);
	FT_TAP_OK(t, str != NULL);
	FT_TAP_SEQ(t, str, src);
	free(str);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_empty);
	FT_TAP_TEST(t, test_non_empty);
}

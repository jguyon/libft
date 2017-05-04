/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fwrite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:01:42 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 22:25:02 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_streams.h"

static void	test_none(t_tap *t)
{
	t_stream	*stm;
	char		buf[256] = "";

	stm = ft_fmemopen(buf, sizeof(buf), "w");
	FT_TAP_UEQ(t, ft_fwrite("", 1, 0, stm), 0);
	ft_fclose(stm);
	FT_TAP_SEQ(t, buf, "");
}

static void	test_bytes(t_tap *t)
{
	t_stream	*stm;
	char		buf[256] = "";

	stm = ft_fmemopen(buf, sizeof(buf), "w");
	FT_TAP_UEQ(t, ft_fwrite("qwerty", 1, 3, stm), 3);
	ft_fclose(stm);
	FT_TAP_SEQ(t, buf, "qwe");
}

static void	test_multiple_bytes(t_tap *t)
{
	t_stream	*stm;
	char		buf[256] = "";

	stm = ft_fmemopen(buf, sizeof(buf), "w");
	FT_TAP_UEQ(t, ft_fwrite("qwertyuiop", 2, 3, stm), 3);
	ft_fclose(stm);
	FT_TAP_SEQ(t, buf, "qwerty");
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_none);
	FT_TAP_TEST(t, test_bytes);
	FT_TAP_TEST(t, test_multiple_bytes);
}

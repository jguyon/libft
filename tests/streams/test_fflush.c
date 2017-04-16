/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fflush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:34:41 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 22:43:39 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_streams.h"

static void	test_manual(t_tap *t)
{
	t_stream	*stm;
	char		buf[256] = "";

	stm = ft_fmemopen(buf, sizeof(buf), "w");
	ft_fputs("hello", stm);
	ft_fputs(" ", stm);
	ft_fputs("world", stm);
	FT_TAP_SEQ(t, buf, "");
	ft_fflush(stm);
	FT_TAP_SEQ(t, buf, "hello world");
	ft_fclose(stm);
}

static void	test_auto(t_tap *t)
{
	t_stream	*stm;
	char		buf[256] = "";

	stm = ft_fmemopen(buf, sizeof(buf), "w");
	ft_setvbuf(stm, NULL, FT_IOFBF, 8);
	ft_fputs("hello", stm);
	FT_TAP_SEQ(t, buf, "");
	ft_fputs(" ", stm);
	FT_TAP_SEQ(t, buf, "");
	ft_fputs("world", stm);
	FT_TAP_SEQ(t, buf, "hello wo");
	ft_fclose(stm);
	FT_TAP_SEQ(t, buf, "hello world");
}

static void	test_none(t_tap *t)
{
	t_stream	*stm;
	char		buf[256] = "";

	stm = ft_fmemopen(buf, sizeof(buf), "w");
	ft_setvbuf(stm, NULL, FT_IONBF, 0);
	ft_fputs("hello", stm);
	FT_TAP_SEQ(t, buf, "hello");
	ft_fputs(" ", stm);
	FT_TAP_SEQ(t, buf, "hello ");
	ft_fputs("world", stm);
	FT_TAP_SEQ(t, buf, "hello world");
	ft_fclose(stm);
	FT_TAP_SEQ(t, buf, "hello world");
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_manual);
	FT_TAP_TEST(t, test_auto);
	FT_TAP_TEST(t, test_none);
}

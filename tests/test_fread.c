/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:50:41 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 23:01:03 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_streams.h"

static void	test_none(t_tap *t)
{
	t_stream	*stm;
	char		buf[] = "hello";
	char		mem[256] = {0};

	stm = ft_fmemopen(buf, sizeof(buf), "r");
	FT_TAP_UEQ(t, ft_fread(mem, 1, 0, stm), 0);
	FT_TAP_SEQ(t, mem, "");
	ft_fclose(stm);
}

static void	test_bytes(t_tap *t)
{
	t_stream	*stm;
	char		buf[] = "hello world";
	char		mem[256] = {0};

	stm = ft_fmemopen(buf, sizeof(buf), "r");
	FT_TAP_UEQ(t, ft_fread(mem, 1, 5, stm), 5);
	FT_TAP_SEQ(t, mem, "hello");
	ft_fclose(stm);
}

static void	test_multi_bytes(t_tap *t)
{
	t_stream	*stm;
	char		buf[] = "hello world";
	char		mem[256] = {0};

	stm = ft_fmemopen(buf, sizeof(buf), "r");
	FT_TAP_UEQ(t, ft_fread(mem, 2, 3, stm), 3);
	FT_TAP_SEQ(t, mem, "hello ");
	ft_fclose(stm);
}

static void	test_eof(t_tap *t)
{
	t_stream	*stm;
	char		buf[] = "hello world";
	char		mem[256] = {0};

	stm = ft_fmemopen(buf, sizeof(buf), "r");
	FT_TAP_UEQ(t, ft_fread(mem, 1, 5, stm), 5);
	FT_TAP_SEQ(t, mem, "hello");
	FT_TAP_UEQ(t, ft_fread(&(mem[5]), 1, 24, stm), 7);
	FT_TAP_SEQ(t, mem, "hello world");
	FT_TAP_UEQ(t, ft_fread(mem, 1, 24, stm), 0);
	FT_TAP_SEQ(t, mem, "hello world");
	FT_TAP_OK(t, ft_feof(stm));
	ft_fclose(stm);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_none);
	FT_TAP_TEST(t, test_bytes);
	FT_TAP_TEST(t, test_multi_bytes);
	FT_TAP_TEST(t, test_eof);
}

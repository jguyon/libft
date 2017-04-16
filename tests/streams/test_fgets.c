/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fgets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 23:06:44 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 23:14:35 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_streams.h"

static void	test_no_newline(t_tap *t)
{
	t_stream	*stm;
	char		buf[] = "hello world";
	char		mem[256];

	stm = ft_fmemopen(buf, sizeof(buf), "r");
	FT_TAP_OK(t, ft_fgets(mem, 6, stm) == mem);
	FT_TAP_SEQ(t, mem, "hello");
	ft_fclose(stm);
}

static void	test_newline(t_tap *t)
{
	t_stream	*stm;
	char		buf[] = "hello\nworld";
	char		mem[256];

	stm = ft_fmemopen(buf, sizeof(buf), "r");
	FT_TAP_OK(t, ft_fgets(mem, 11, stm) == mem);
	FT_TAP_SEQ(t, mem, "hello\n");
	ft_fclose(stm);
}

static void	test_eof(t_tap *t)
{
	t_stream	*stm;
	char		buf[] = "hello\nworld";
	char		mem[256];

	stm = ft_fmemopen(buf, sizeof(buf), "r");
	FT_TAP_OK(t, ft_fgets(mem, 24, stm) == mem);
	FT_TAP_SEQ(t, mem, "hello\n");
	FT_TAP_OK(t, ft_fgets(mem, 24, stm) == mem);
	FT_TAP_SEQ(t, mem, "world");
	FT_TAP_OK(t, ft_fgets(mem, 24, stm) == NULL);
	FT_TAP_OK(t, ft_feof(stm));
	FT_TAP_SEQ(t, mem, "");
	ft_fclose(stm);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_no_newline);
	FT_TAP_TEST(t, test_newline);
	FT_TAP_TEST(t, test_eof);
}

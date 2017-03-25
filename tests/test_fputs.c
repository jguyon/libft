/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:30:25 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 22:33:29 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_streams.h"

static void	test_empty(t_tap *t)
{
	t_stream	*stm;
	char		buf[256] = "";

	stm = ft_fmemopen(buf, sizeof(buf), "w");
	FT_TAP_IEQ(t, ft_fputs("", stm), 0);
	ft_fclose(stm);
	FT_TAP_SEQ(t, buf, "");
}

static void	test_nonempty(t_tap *t)
{
	t_stream	*stm;
	char		buf[256] = "";

	stm = ft_fmemopen(buf, sizeof(buf), "w");
	FT_TAP_IEQ(t, ft_fputs("hello", stm), 0);
	ft_fclose(stm);
	FT_TAP_SEQ(t, buf, "hello");
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_empty);
	FT_TAP_TEST(t, test_nonempty);
}

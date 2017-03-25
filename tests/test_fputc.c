/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fputc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:25:59 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 22:29:54 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_streams.h"

static void	test_byte(t_tap *t)
{
	t_stream	*stm;
	char		buf[256] = "";

	stm = ft_fmemopen(buf, sizeof(buf), "w");
	FT_TAP_IEQ(t, ft_fputc('a', stm), 'a');
	ft_fclose(stm);
	FT_TAP_SEQ(t, buf, "a");
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_byte);
}

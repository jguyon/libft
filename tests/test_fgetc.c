/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fgetc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 23:01:49 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 23:06:10 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_streams.h"

static void	test_byte(t_tap *t)
{
	t_stream	*stm;
	char		buf[] = "h";

	stm = ft_fmemopen(buf, sizeof(buf), "r");
	FT_TAP_IEQ(t, ft_fgetc(stm), 'h');
	ft_fclose(stm);
}

static void	test_eof(t_tap *t)
{
	t_stream	*stm;
	char		buf[] = "h";

	stm = ft_fmemopen(buf, sizeof(buf), "r");
	FT_TAP_IEQ(t, ft_fgetc(stm), 'h');
	FT_TAP_IEQ(t, ft_fgetc(stm), '\0');
	FT_TAP_IEQ(t, ft_fgetc(stm), FT_EOF);
	ft_fclose(stm);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_byte);
	FT_TAP_TEST(t, test_eof);
}

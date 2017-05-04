/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:55:23 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 18:00:25 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_memory.h"
#include <string.h>

static void	test_found(t_tap *t)
{
	void	*mem = "qwertyuiopasdfghjklzxcvbnm01234567890";
	void	*res_ft;
	void	*res_lc;

	res_ft = ft_memchr(mem, '0', sizeof(mem));
	res_lc = memchr(mem, '0', sizeof(mem));
	FT_TAP_IEQ(t, res_ft - mem, res_lc - mem);
}

static void	test_not_found(t_tap *t)
{
	void	*mem = "qwertyuiopasdfghjklzxcvbnm01234567890";
	void	*res_ft;
	void	*res_lc;

	res_ft = ft_memchr(mem, '@', sizeof(mem));
	res_lc = memchr(mem, '@', sizeof(mem));
	FT_TAP_IEQ(t, res_ft - mem, res_lc - mem);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_found);
	FT_TAP_TEST(t, test_not_found);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_darr_extract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 21:21:39 by jguyon            #+#    #+#             */
/*   Updated: 2017/05/03 18:39:51 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_darrays.h"
#include <stdlib.h>

static void	test_empty(t_tap *t)
{
	t_darray	darr;

	FT_TAP_IEQ(t, ft_darr_init(&darr, sizeof(char), 0), 0);
	FT_TAP_OK(t, ft_darr_extract(&darr) == NULL);
}

static void	test_nonempty(t_tap *t)
{
	t_darray	darr;
	char		c;
	char		*str;

	FT_TAP_IEQ(t, ft_darr_init(&darr, sizeof(*str), 0), 0);
	FT_TAP_IEQ(t, ft_darr_set(&darr, 2, NULL), 0);
	c = 'h';
	FT_TAP_IEQ(t, ft_darr_set(&darr, 0, &c), 0);
	c = 'i';
	FT_TAP_IEQ(t, ft_darr_set(&darr, 1, &c), 0);
	FT_TAP_OK(t, (str = (char *)ft_darr_extract(&darr)) != NULL);
	FT_TAP_SEQ(t, str, "hi");
	free(str);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_empty);
	FT_TAP_TEST(t, test_nonempty);
}

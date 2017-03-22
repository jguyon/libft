/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:01:10 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 20:05:12 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_dlists.h"

typedef struct	s_num {
	int				n;
	t_dlist_node	node;
}				t_num;

static void		test_empty(t_tap *t)
{
	t_dlist	lst;

	FT_DLST_INIT(&lst, t_num, node);
	FT_TAP_OK(t, ft_dlst_empty(&lst));
	FT_TAP_NOTOK(t, ft_dlst_singular(&lst));
}

static void		test_singular(t_tap *t)
{
	t_dlist	lst;
	t_num	num;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(num.node));
	FT_TAP_NOTOK(t, ft_dlst_empty(&lst));
	FT_TAP_OK(t, ft_dlst_singular(&lst));
}

static void		test_multiple(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[2];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	FT_TAP_NOTOK(t, ft_dlst_empty(&lst));
	FT_TAP_NOTOK(t, ft_dlst_singular(&lst));
}

void			run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_empty);
	FT_TAP_TEST(t, test_singular);
	FT_TAP_TEST(t, test_multiple);
}

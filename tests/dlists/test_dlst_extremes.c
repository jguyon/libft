/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_extremes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:55:27 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 20:00:42 by jguyon           ###   ########.fr       */
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
	FT_TAP_OK(t, ft_dlst_first(&lst) == NULL);
	FT_TAP_OK(t, ft_dlst_last(&lst) == NULL);
}

static void		test_singular(t_tap *t)
{
	t_dlist	lst;
	t_num	num;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(num.node));
	FT_TAP_OK(t, ft_dlst_first(&lst) == &(num.node));
	FT_TAP_OK(t, ft_dlst_last(&lst) == &(num.node));
}

static void		test_multiple(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[3];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	ft_dlst_pushr(&lst, &(nums[2].node));
	FT_TAP_OK(t, ft_dlst_first(&lst) == &(nums[0].node));
	FT_TAP_OK(t, ft_dlst_last(&lst) == &(nums[2].node));
}

void			run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_empty);
	FT_TAP_TEST(t, test_singular);
	FT_TAP_TEST(t, test_multiple);
}

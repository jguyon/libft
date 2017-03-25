/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_neighbors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:48:05 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 19:54:34 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_dlists.h"

typedef struct	s_num {
	int				n;
	t_dlist_node	node;
}				t_num;

static void		test_extremities(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[2];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	FT_TAP_OK(t, ft_dlst_prev(&lst, &(nums[0].node)) == NULL);
	FT_TAP_OK(t, ft_dlst_next(&lst, &(nums[1].node)) == NULL);
}

static void		test_middle(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[2];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	FT_TAP_OK(t, ft_dlst_prev(&lst, &(nums[1].node)) == &(nums[0].node));
	FT_TAP_OK(t, ft_dlst_next(&lst, &(nums[0].node)) == &(nums[1].node));
}

void			run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_extremities);
	FT_TAP_TEST(t, test_middle);
}

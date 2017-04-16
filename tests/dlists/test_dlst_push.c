/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:30:04 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 15:55:49 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_dlists.h"

typedef struct	s_num {
	int				n;
	t_dlist_node	node;
}				t_num;

static void	test_push_left_empty(t_tap *t)
{
	t_dlist	lst;
	t_num	num;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushl(&lst, &(num.node));
	FT_TAP_OK(t, lst.head.next == &(num.node));
	FT_TAP_OK(t, lst.head.prev == &(num.node));
	FT_TAP_OK(t, num.node.next == &(lst.head));
	FT_TAP_OK(t, num.node.prev == &(lst.head));
}

static void	test_push_right_empty(t_tap *t)
{
	t_dlist	lst;
	t_num	num;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(num.node));
	FT_TAP_OK(t, lst.head.next == &(num.node));
	FT_TAP_OK(t, lst.head.prev == &(num.node));
	FT_TAP_OK(t, num.node.next == &(lst.head));
	FT_TAP_OK(t, num.node.prev == &(lst.head));
}

static void	test_push_first(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[2];

	nums[0].n = 1;
	nums[1].n = 2;
	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushl(&lst, &(nums[1].node));
	ft_dlst_pushl(&lst, &(nums[0].node));
	FT_TAP_OK(t, lst.head.next == &(nums[0].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.prev == &(lst.head));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[1].node.next == &(lst.head));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
}

static void	test_push_last(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[2];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	FT_TAP_OK(t, lst.head.next == &(nums[0].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.prev == &(lst.head));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[1].node.next == &(lst.head));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_push_left_empty);
	FT_TAP_TEST(t, test_push_right_empty);
	FT_TAP_TEST(t, test_push_first);
	FT_TAP_TEST(t, test_push_last);
}

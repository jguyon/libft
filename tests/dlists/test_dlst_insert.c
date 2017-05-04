/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:51:46 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 16:04:13 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_dlists.h"

typedef struct	s_num {
	int				n;
	t_dlist_node	node;
}				t_num;

static void	test_first(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[2];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushl(&lst, &(nums[1].node));
	ft_dlst_insertl(&(nums[1].node), &(nums[0].node));
	FT_TAP_OK(t, lst.head.next == &(nums[0].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.prev == &(lst.head));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[1].node.next == &(lst.head));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
}

static void	test_last(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[2];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushl(&lst, &(nums[0].node));
	ft_dlst_insertr(&(nums[0].node), &(nums[1].node));
	FT_TAP_OK(t, lst.head.next == &(nums[0].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.prev == &(lst.head));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[1].node.next == &(lst.head));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
}

static void	test_left(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[3];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[2].node));
	ft_dlst_insertl(&(nums[2].node), &(nums[1].node));
	FT_TAP_OK(t, lst.head.next == &(nums[0].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[2].node));
	FT_TAP_OK(t, nums[0].node.prev == &(lst.head));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[1].node.next == &(nums[2].node));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
	FT_TAP_OK(t, nums[2].node.next == &(lst.head));
	FT_TAP_OK(t, nums[2].node.prev == &(nums[1].node));
}

static void	test_right(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[3];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[2].node));
	ft_dlst_insertr(&(nums[0].node), &(nums[1].node));
	FT_TAP_OK(t, lst.head.next == &(nums[0].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[2].node));
	FT_TAP_OK(t, nums[0].node.prev == &(lst.head));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[1].node.next == &(nums[2].node));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
	FT_TAP_OK(t, nums[2].node.next == &(lst.head));
	FT_TAP_OK(t, nums[2].node.prev == &(nums[1].node));
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_first);
	FT_TAP_TEST(t, test_last);
	FT_TAP_TEST(t, test_left);
	FT_TAP_TEST(t, test_right);
}

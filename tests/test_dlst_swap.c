/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:43:45 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 18:38:37 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_dlists.h"

typedef struct	s_num {
	int				n;
	t_dlist_node	node;
}				t_num;

static void	test_separated(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[3];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	ft_dlst_pushr(&lst, &(nums[2].node));
	ft_dlst_swap(&(nums[0].node), &(nums[2].node));
	FT_TAP_OK(t, lst.head.next == &(nums[2].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[0].node));
	FT_TAP_OK(t, nums[2].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[2].node.prev == &(lst.head));
	FT_TAP_OK(t, nums[1].node.next == &(nums[0].node));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[2].node));
	FT_TAP_OK(t, nums[0].node.next == &(lst.head));
	FT_TAP_OK(t, nums[0].node.prev == &(nums[1].node));
}

static void	test_adjacent_asc(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[2];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	ft_dlst_swap(&(nums[0].node), &(nums[1].node));
	FT_TAP_OK(t, lst.head.next == &(nums[1].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[0].node));
	FT_TAP_OK(t, nums[1].node.next == &(nums[0].node));
	FT_TAP_OK(t, nums[1].node.prev == &(lst.head));
	FT_TAP_OK(t, nums[0].node.next == &(lst.head));
	FT_TAP_OK(t, nums[0].node.prev == &(nums[1].node));
}

static void	test_adjacent_desc(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[2];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	ft_dlst_swap(&(nums[1].node), &(nums[0].node));
	FT_TAP_OK(t, lst.head.next == &(nums[1].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[0].node));
	FT_TAP_OK(t, nums[1].node.next == &(nums[0].node));
	FT_TAP_OK(t, nums[1].node.prev == &(lst.head));
	FT_TAP_OK(t, nums[0].node.next == &(lst.head));
	FT_TAP_OK(t, nums[0].node.prev == &(nums[1].node));
}

static void	test_same(t_tap *t)
{
	t_dlist	lst;
	t_num	num;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(num.node));
	ft_dlst_swap(&(num.node), &(num.node));
	FT_TAP_OK(t, lst.head.next == &(num.node));
	FT_TAP_OK(t, lst.head.prev == &(num.node));
	FT_TAP_OK(t, num.node.next == &(lst.head));
	FT_TAP_OK(t, num.node.prev == &(lst.head));
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_separated);
	FT_TAP_TEST(t, test_adjacent_asc);
	FT_TAP_TEST(t, test_adjacent_desc);
	FT_TAP_TEST(t, test_same);
}

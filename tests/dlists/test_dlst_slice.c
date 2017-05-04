/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:03:14 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 19:22:22 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_dlists.h"

typedef struct	s_num {
	int				n;
	t_dlist_node	node;
}				t_num;

static void		test_partial_list(t_tap *t)
{
	t_dlist	src;
	t_dlist	dst;
	t_num	nums[4];

	FT_DLST_INIT(&src, t_num, node);
	FT_DLST_INIT(&dst, t_num, node);
	ft_dlst_pushr(&src, &(nums[0].node));
	ft_dlst_pushr(&src, &(nums[1].node));
	ft_dlst_pushr(&src, &(nums[2].node));
	ft_dlst_pushr(&src, &(nums[3].node));
	ft_dlst_slice(&dst, &(nums[1].node), &(nums[2].node));
	FT_TAP_OK(t, src.head.next == &(nums[0].node));
	FT_TAP_OK(t, src.head.prev == &(nums[3].node));
	FT_TAP_OK(t, nums[0].node.prev == &(src.head));
	FT_TAP_OK(t, nums[0].node.next == &(nums[3].node));
	FT_TAP_OK(t, nums[3].node.prev == &(nums[0].node));
	FT_TAP_OK(t, nums[3].node.next == &(src.head));
	FT_TAP_OK(t, dst.head.next == &(nums[1].node));
	FT_TAP_OK(t, dst.head.prev == &(nums[2].node));
	FT_TAP_OK(t, nums[1].node.next == &(nums[2].node));
	FT_TAP_OK(t, nums[1].node.prev == &(dst.head));
	FT_TAP_OK(t, nums[2].node.next == &(dst.head));
	FT_TAP_OK(t, nums[2].node.prev == &(nums[1].node));
}

static void		test_whole_list(t_tap *t)
{
	t_dlist	src;
	t_dlist	dst;
	t_num	nums[2];

	FT_DLST_INIT(&src, t_num, node);
	FT_DLST_INIT(&dst, t_num, node);
	ft_dlst_pushr(&src, &(nums[0].node));
	ft_dlst_pushr(&src, &(nums[1].node));
	ft_dlst_slice(&dst, &(nums[0].node), &(nums[1].node));
	FT_TAP_OK(t, src.head.next == &(src.head));
	FT_TAP_OK(t, src.head.prev == &(src.head));
	FT_TAP_OK(t, dst.head.next == &(nums[0].node));
	FT_TAP_OK(t, dst.head.prev == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.prev == &(dst.head));
	FT_TAP_OK(t, nums[1].node.next == &(dst.head));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
}

static void		test_one_node(t_tap *t)
{
	t_dlist	src;
	t_dlist	dst;
	t_num	nums[2];

	FT_DLST_INIT(&src, t_num, node);
	FT_DLST_INIT(&dst, t_num, node);
	ft_dlst_pushr(&src, &(nums[0].node));
	ft_dlst_pushr(&src, &(nums[1].node));
	ft_dlst_slice(&dst, &(nums[0].node), &(nums[0].node));
	FT_TAP_OK(t, src.head.next == &(nums[1].node));
	FT_TAP_OK(t, src.head.prev == &(nums[1].node));
	FT_TAP_OK(t, nums[1].node.next == &(src.head));
	FT_TAP_OK(t, nums[1].node.prev == &(src.head));
	FT_TAP_OK(t, dst.head.next == &(nums[0].node));
	FT_TAP_OK(t, dst.head.prev == &(nums[0].node));
	FT_TAP_OK(t, nums[0].node.next == &(dst.head));
	FT_TAP_OK(t, nums[0].node.prev == &(dst.head));
}

void			run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_partial_list);
	FT_TAP_TEST(t, test_whole_list);
	FT_TAP_TEST(t, test_one_node);
}

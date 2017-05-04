/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_splice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:22:57 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 19:36:49 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_dlists.h"

typedef struct	s_num {
	int				n;
	t_dlist_node	node;
}				t_num;

static void		test_first(t_tap *t)
{
	t_dlist	src;
	t_dlist	dst;
	t_num	nums[3];

	FT_DLST_INIT(&src, t_num, node);
	FT_DLST_INIT(&dst, t_num, node);
	ft_dlst_pushr(&src, &(nums[0].node));
	ft_dlst_pushr(&src, &(nums[1].node));
	ft_dlst_pushr(&dst, &(nums[2].node));
	ft_dlst_splicel(&(nums[2].node), &src);
	FT_TAP_OK(t, dst.head.next == &(nums[0].node));
	FT_TAP_OK(t, dst.head.prev == &(nums[2].node));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.prev == &(dst.head));
	FT_TAP_OK(t, nums[1].node.next == &(nums[2].node));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
	FT_TAP_OK(t, nums[2].node.next == &(dst.head));
	FT_TAP_OK(t, nums[2].node.prev == &(nums[1].node));
}

static void		test_last(t_tap *t)
{
	t_dlist	src;
	t_dlist	dst;
	t_num	nums[3];

	FT_DLST_INIT(&src, t_num, node);
	FT_DLST_INIT(&dst, t_num, node);
	ft_dlst_pushr(&dst, &(nums[0].node));
	ft_dlst_pushr(&src, &(nums[1].node));
	ft_dlst_pushr(&src, &(nums[2].node));
	ft_dlst_splicer(&(nums[0].node), &src);
	FT_TAP_OK(t, dst.head.next == &(nums[0].node));
	FT_TAP_OK(t, dst.head.prev == &(nums[2].node));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.prev == &(dst.head));
	FT_TAP_OK(t, nums[1].node.next == &(nums[2].node));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
	FT_TAP_OK(t, nums[2].node.next == &(dst.head));
	FT_TAP_OK(t, nums[2].node.prev == &(nums[1].node));
}

static void		test_left(t_tap *t)
{
	t_dlist	src;
	t_dlist	dst;
	t_num	nums[3];

	FT_DLST_INIT(&src, t_num, node);
	FT_DLST_INIT(&dst, t_num, node);
	ft_dlst_pushr(&dst, &(nums[0].node));
	ft_dlst_pushr(&src, &(nums[1].node));
	ft_dlst_pushr(&dst, &(nums[2].node));
	ft_dlst_splicel(&(nums[2].node), &src);
	FT_TAP_OK(t, dst.head.next == &(nums[0].node));
	FT_TAP_OK(t, dst.head.prev == &(nums[2].node));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.prev == &(dst.head));
	FT_TAP_OK(t, nums[1].node.next == &(nums[2].node));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
	FT_TAP_OK(t, nums[2].node.next == &(dst.head));
	FT_TAP_OK(t, nums[2].node.prev == &(nums[1].node));
}

static void		test_right(t_tap *t)
{
	t_dlist	src;
	t_dlist	dst;
	t_num	nums[3];

	FT_DLST_INIT(&src, t_num, node);
	FT_DLST_INIT(&dst, t_num, node);
	ft_dlst_pushr(&dst, &(nums[0].node));
	ft_dlst_pushr(&src, &(nums[1].node));
	ft_dlst_pushr(&dst, &(nums[2].node));
	ft_dlst_splicer(&(nums[0].node), &src);
	FT_TAP_OK(t, dst.head.next == &(nums[0].node));
	FT_TAP_OK(t, dst.head.prev == &(nums[2].node));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.prev == &(dst.head));
	FT_TAP_OK(t, nums[1].node.next == &(nums[2].node));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
	FT_TAP_OK(t, nums[2].node.next == &(dst.head));
	FT_TAP_OK(t, nums[2].node.prev == &(nums[1].node));
}

void			run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_first);
	FT_TAP_TEST(t, test_last);
	FT_TAP_TEST(t, test_left);
	FT_TAP_TEST(t, test_right);
}

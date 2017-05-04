/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:37:29 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 19:46:49 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_dlists.h"

typedef struct	s_num {
	int				n;
	t_dlist_node	node;
}				t_num;

static void		test_empty_left(t_tap *t)
{
	t_dlist	src;
	t_dlist	dst;
	t_num	nums[2];

	FT_DLST_INIT(&src, t_num, node);
	FT_DLST_INIT(&dst, t_num, node);
	ft_dlst_pushr(&src, &(nums[0].node));
	ft_dlst_pushr(&src, &(nums[1].node));
	ft_dlst_joinl(&dst, &src);
	FT_TAP_OK(t, dst.head.next == &(nums[0].node));
	FT_TAP_OK(t, dst.head.prev == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.prev == &(dst.head));
	FT_TAP_OK(t, nums[1].node.next == &(dst.head));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
}

static void		test_empty_right(t_tap *t)
{
	t_dlist	src;
	t_dlist	dst;
	t_num	nums[2];

	FT_DLST_INIT(&src, t_num, node);
	FT_DLST_INIT(&dst, t_num, node);
	ft_dlst_pushr(&src, &(nums[0].node));
	ft_dlst_pushr(&src, &(nums[1].node));
	ft_dlst_joinr(&dst, &src);
	FT_TAP_OK(t, dst.head.next == &(nums[0].node));
	FT_TAP_OK(t, dst.head.prev == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.prev == &(dst.head));
	FT_TAP_OK(t, nums[1].node.next == &(dst.head));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
}

static void		test_nonempty_left(t_tap *t)
{
	t_dlist	src;
	t_dlist	dst;
	t_num	nums[2];

	FT_DLST_INIT(&src, t_num, node);
	FT_DLST_INIT(&dst, t_num, node);
	ft_dlst_pushr(&src, &(nums[0].node));
	ft_dlst_pushr(&dst, &(nums[1].node));
	ft_dlst_joinl(&dst, &src);
	FT_TAP_OK(t, dst.head.next == &(nums[0].node));
	FT_TAP_OK(t, dst.head.prev == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.prev == &(dst.head));
	FT_TAP_OK(t, nums[1].node.next == &(dst.head));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
}

static void		test_nonempty_right(t_tap *t)
{
	t_dlist	src;
	t_dlist	dst;
	t_num	nums[2];

	FT_DLST_INIT(&src, t_num, node);
	FT_DLST_INIT(&dst, t_num, node);
	ft_dlst_pushr(&dst, &(nums[0].node));
	ft_dlst_pushr(&src, &(nums[1].node));
	ft_dlst_joinr(&dst, &src);
	FT_TAP_OK(t, dst.head.next == &(nums[0].node));
	FT_TAP_OK(t, dst.head.prev == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.next == &(nums[1].node));
	FT_TAP_OK(t, nums[0].node.prev == &(dst.head));
	FT_TAP_OK(t, nums[1].node.next == &(dst.head));
	FT_TAP_OK(t, nums[1].node.prev == &(nums[0].node));
}

void			run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_empty_left);
	FT_TAP_TEST(t, test_empty_right);
	FT_TAP_TEST(t, test_nonempty_left);
	FT_TAP_TEST(t, test_nonempty_right);
}

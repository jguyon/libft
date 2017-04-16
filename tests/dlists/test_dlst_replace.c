/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:34:30 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 17:43:28 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_dlists.h"

typedef struct	s_num {
	int				n;
	t_dlist_node	node;
}				t_num;

static void	test_singular(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[2];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_replace(&(nums[0].node), &(nums[1].node));
	FT_TAP_OK(t, lst.head.next == &(nums[1].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[1].node));
	FT_TAP_OK(t, nums[1].node.next == &(lst.head));
	FT_TAP_OK(t, nums[1].node.prev == &(lst.head));
}

static void	test_multiple(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[4];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	ft_dlst_pushr(&lst, &(nums[2].node));
	ft_dlst_replace(&(nums[1].node), &(nums[3].node));
	FT_TAP_OK(t, lst.head.next == &(nums[0].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[2].node));
	FT_TAP_OK(t, nums[0].node.next == &(nums[3].node));
	FT_TAP_OK(t, nums[0].node.prev == &(lst.head));
	FT_TAP_OK(t, nums[3].node.next == &(nums[2].node));
	FT_TAP_OK(t, nums[3].node.prev == &(nums[0].node));
	FT_TAP_OK(t, nums[2].node.next == &(lst.head));
	FT_TAP_OK(t, nums[2].node.prev == &(nums[3].node));
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_singular);
	FT_TAP_TEST(t, test_multiple);
}

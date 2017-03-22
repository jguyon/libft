/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:05:07 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 17:17:41 by jguyon           ###   ########.fr       */
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
	t_num	num;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushl(&lst, &(num.node));
	ft_dlst_remove(&(num.node));
	FT_TAP_OK(t, lst.head.next == &(lst.head));
	FT_TAP_OK(t, lst.head.prev == &(lst.head));
}

static void	test_multiple(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[3];

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	ft_dlst_pushr(&lst, &(nums[2].node));
	ft_dlst_remove(&(nums[1].node));
	FT_TAP_OK(t, lst.head.next == &(nums[0].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[2].node));
	FT_TAP_OK(t, nums[0].node.next == &(nums[2].node));
	FT_TAP_OK(t, nums[0].node.prev == &(lst.head));
	FT_TAP_OK(t, nums[2].node.next == &(lst.head));
	FT_TAP_OK(t, nums[2].node.prev == &(nums[0].node));
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_singular);
	FT_TAP_TEST(t, test_multiple);
}

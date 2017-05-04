/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:18:02 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 17:33:35 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_dlists.h"

typedef struct	s_num {
	int				n;
	t_dlist_node	node;
}				t_num;

static void	test_empty(t_tap *t)
{
	t_dlist	lst;

	FT_DLST_INIT(&lst, t_num, node);
	FT_TAP_OK(t, ft_dlst_popl(&lst) == NULL);
	FT_TAP_OK(t, ft_dlst_popr(&lst) == NULL);
}

static void	test_left_singular(t_tap *t)
{
	t_dlist			lst;
	t_num			num;
	t_dlist_node	*node;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(num.node));
	node = ft_dlst_popl(&lst);
	FT_TAP_OK(t, node == &(num.node));
	FT_TAP_OK(t, lst.head.next == &(lst.head));
	FT_TAP_OK(t, lst.head.prev == &(lst.head));
}

static void	test_right_singular(t_tap *t)
{
	t_dlist			lst;
	t_num			num;
	t_dlist_node	*node;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(num.node));
	node = ft_dlst_popr(&lst);
	FT_TAP_OK(t, node == &(num.node));
	FT_TAP_OK(t, lst.head.next == &(lst.head));
	FT_TAP_OK(t, lst.head.prev == &(lst.head));
}

static void	test_left_multiple(t_tap *t)
{
	t_dlist			lst;
	t_num			nums[2];
	t_dlist_node	*node;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	node = ft_dlst_popl(&lst);
	FT_TAP_OK(t, node == &(nums[0].node));
	FT_TAP_OK(t, lst.head.next == &(nums[1].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[1].node));
	FT_TAP_OK(t, nums[1].node.next == &(lst.head));
	FT_TAP_OK(t, nums[1].node.prev == &(lst.head));
}

static void	test_right_multiple(t_tap *t)
{
	t_dlist			lst;
	t_num			nums[2];
	t_dlist_node	*node;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	node = ft_dlst_popr(&lst);
	FT_TAP_OK(t, node == &(nums[1].node));
	FT_TAP_OK(t, lst.head.next == &(nums[0].node));
	FT_TAP_OK(t, lst.head.prev == &(nums[0].node));
	FT_TAP_OK(t, nums[0].node.next == &(lst.head));
	FT_TAP_OK(t, nums[0].node.prev == &(lst.head));
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_empty);
	FT_TAP_TEST(t, test_left_singular);
	FT_TAP_TEST(t, test_right_singular);
	FT_TAP_TEST(t, test_left_multiple);
	FT_TAP_TEST(t, test_right_multiple);
}

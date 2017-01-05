/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:53:12 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/05 23:56:40 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

typedef struct	s_num {
	unsigned long	n;
	t_dlist_node	node;
}				t_num;

TFT_TEST(test_dlist_traverse_left)
{
	t_dlist			list;
	t_num			nums[64];
	size_t			i;
	t_dlist_node	*curr;

	i = 0;
	FT_DLIST_INIT(&list, t_num, node);
	while (i < 64)
	{
		nums[i].n = i;
		ft_dlist_push_back(&list, FT_DLIST_NODE(&list, &(nums[i])));
		++i;
	}
	curr = ft_dlist_first(&list);
	i = 0;
	while (curr)
	{
		TFT_ASSERT(FT_DLIST_ENTRY(&list, curr) == &(nums[i]));
		curr = ft_dlist_next(&list, curr);
		++i;
	}
	i = 0;
	while ((curr = ft_dlist_pop_front(&list)))
	{
		TFT_ASSERT(!!ft_dlist_singular(&list) == !!(i == 62));
		TFT_ASSERT(!!ft_dlist_empty(&list) == !!(i == 63));
		TFT_ASSERT(FT_DLIST_ENTRY(&list, curr) == &(nums[i]));
		++i;
	}
}

TFT_TEST(test_dlist_traverse_right)
{
	t_dlist			list;
	t_num			nums[64];
	size_t			i;
	t_dlist_node	*curr;

	i = 0;
	FT_DLIST_INIT(&list, t_num, node);
	while (i < 64)
	{
		nums[i].n = i;
		ft_dlist_push_front(&list, FT_DLIST_NODE(&list, &(nums[i])));
		++i;
	}
	curr = ft_dlist_last(&list);
	i = 0;
	while (curr)
	{
		TFT_ASSERT(FT_DLIST_ENTRY(&list, curr) == &(nums[i]));
		curr = ft_dlist_prev(&list, curr);
		++i;
	}
	i = 0;
	while ((curr = ft_dlist_pop_back(&list)))
	{
		TFT_ASSERT(!!ft_dlist_singular(&list) == !!(i == 62));
		TFT_ASSERT(!!ft_dlist_empty(&list) == !!(i == 63));
		TFT_ASSERT(FT_DLIST_ENTRY(&list, curr) == &(nums[i]));
		++i;
	}
}

void	test_dlists(void)
{
	TFT_RUN(test_dlist_traverse_left);
	TFT_RUN(test_dlist_traverse_right);
}

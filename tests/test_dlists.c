/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:53:12 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/07 12:55:29 by jguyon           ###   ########.fr       */
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
	FT_DLST_INIT(&list, t_num, node);
	while (i < 64)
	{
		nums[i].n = i;
		ft_dlst_pushr(&list, FT_DLST_NODE(&list, &(nums[i])));
		++i;
	}
	curr = ft_dlst_first(&list);
	i = 0;
	while (curr)
	{
		TFT_ASSERT(FT_DLST_ENTRY(&list, curr) == &(nums[i]));
		curr = ft_dlst_next(&list, curr);
		++i;
	}
	i = 0;
	while ((curr = ft_dlst_popl(&list)))
	{
		TFT_ASSERT(!!ft_dlst_singular(&list) == !!(i == 62));
		TFT_ASSERT(!!ft_dlst_empty(&list) == !!(i == 63));
		TFT_ASSERT(FT_DLST_ENTRY(&list, curr) == &(nums[i]));
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
	FT_DLST_INIT(&list, t_num, node);
	while (i < 64)
	{
		nums[i].n = i;
		ft_dlst_pushl(&list, FT_DLST_NODE(&list, &(nums[i])));
		++i;
	}
	curr = ft_dlst_last(&list);
	i = 0;
	while (curr)
	{
		TFT_ASSERT(FT_DLST_ENTRY(&list, curr) == &(nums[i]));
		curr = ft_dlst_prev(&list, curr);
		++i;
	}
	i = 0;
	while ((curr = ft_dlst_popr(&list)))
	{
		TFT_ASSERT(!!ft_dlst_singular(&list) == !!(i == 62));
		TFT_ASSERT(!!ft_dlst_empty(&list) == !!(i == 63));
		TFT_ASSERT(FT_DLST_ENTRY(&list, curr) == &(nums[i]));
		++i;
	}
}

TFT_TEST(test_dlist_insert)
{
	t_dlist	list;
	t_num	nums[4];

	FT_DLST_INIT(&list, t_num, node);
	ft_dlst_pushl(&list, &(nums[0].node));
	ft_dlst_insertr(&(nums[0].node), &(nums[2].node));
	ft_dlst_insertl(&(nums[2].node), &(nums[1].node));
	TFT_ASSERT(ft_dlst_first(&list) == &(nums[0].node));
	TFT_ASSERT(ft_dlst_last(&list) == &(nums[2].node));
	TFT_ASSERT(ft_dlst_next(&list, &(nums[0].node)) == &(nums[1].node));
	ft_dlst_swap(&(nums[0].node), &(nums[2].node));
	TFT_ASSERT(ft_dlst_first(&list) == &(nums[2].node));
	TFT_ASSERT(ft_dlst_last(&list) == &(nums[0].node));
	TFT_ASSERT(ft_dlst_prev(&list, &(nums[0].node)) == &(nums[1].node));
	ft_dlst_replace(&(nums[1].node), &(nums[3].node));
	TFT_ASSERT(ft_dlst_prev(&list, &(nums[0].node)) == &(nums[3].node));
	ft_dlst_remove(&(nums[3].node));
	TFT_ASSERT(ft_dlst_prev(&list, &(nums[0].node)) == &(nums[2].node));
	TFT_ASSERT(ft_dlst_next(&list, &(nums[2].node)) == &(nums[0].node));
}

static int	iterate(void *entry, void *acc)
{
	if (((t_num *)entry)->n >= 32)
		return (0);
	*((size_t *)acc) += 1;
	((t_num *)entry)->n *= 10;
	return (1);
}

static int	remove_node_of(void *entry, void *acc)
{
	(void)acc;
	ft_dlst_remove(&(((t_num *)entry)->node));
	return (1);
}

TFT_TEST(test_dlist_iterate_left)
{
	t_dlist			list;
	t_num			nums[64];
	size_t			i;
	t_dlist_node	*curr;

	FT_DLST_INIT(&list, t_num, node);
	i = 0;
	while (i < 64)
	{
		nums[i].n = i;
		ft_dlst_pushr(&list, &(nums[i].node));
		++i;
	}
	i = 0;
	ft_dlst_foreachl(&list, &i, &iterate);
	TFT_ASSERT(i == 32);
	i = 0;
	curr = ft_dlst_first(&list);
	while (curr)
	{
		if (i < 32)
			TFT_ASSERT(((t_num *)FT_DLST_ENTRY(&list, curr))->n == i * 10);
		else
			TFT_ASSERT(((t_num *)FT_DLST_ENTRY(&list, curr))->n == i);
		curr = ft_dlst_next(&list, curr);
		++i;
	}
	ft_dlst_foreachl(&list, NULL, &remove_node_of);
	TFT_ASSERT(ft_dlst_empty(&list));
}

TFT_TEST(test_dlist_iterate_right)
{
	t_dlist			list;
	t_num			nums[64];
	size_t			i;
	t_dlist_node	*curr;

	FT_DLST_INIT(&list, t_num, node);
	i = 0;
	while (i < 64)
	{
		nums[i].n = i;
		ft_dlst_pushl(&list, &(nums[i].node));
		++i;
	}
	i = 0;
	ft_dlst_foreachr(&list, &i, &iterate);
	TFT_ASSERT(i == 32);
	i = 0;
	curr = ft_dlst_last(&list);
	while (curr)
	{
		if (i < 32)
			TFT_ASSERT(((t_num *)FT_DLST_ENTRY(&list, curr))->n == i * 10);
		else
			TFT_ASSERT(((t_num *)FT_DLST_ENTRY(&list, curr))->n == i);
		curr = ft_dlst_prev(&list, curr);
		++i;
	}
}

void	test_dlists(void)
{
	TFT_RUN(test_dlist_traverse_left);
	TFT_RUN(test_dlist_traverse_right);
	TFT_RUN(test_dlist_insert);
	TFT_RUN(test_dlist_iterate_left);
	TFT_RUN(test_dlist_iterate_right);
}

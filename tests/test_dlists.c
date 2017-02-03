/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:26:01 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/03 20:07:38 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_dlists.h"

typedef struct	s_num {
	unsigned long	n;
	t_dlist_node	node;
}				t_num;

static void		test_traverse_left(t_tap *t)
{
	t_dlist			list = FT_DLST(list, t_num, node);
	t_num			nums[64];
	size_t			i;
	t_dlist_node	*curr;

	ft_tap_plan(t, 256);
	i = 0;
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
		FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&list, curr),
			(uintmax_t)&(nums[i]));
		curr = ft_dlst_next(&list, curr);
		++i;
	}
	i = 0;
	while ((curr = ft_dlst_popl(&list)))
	{
		FT_TAP_IEQ(t, !!ft_dlst_singular(&list), !!(i == 62));
		FT_TAP_IEQ(t, !!ft_dlst_empty(&list), !!(i == 63));
		FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&list, curr),
				   (uintmax_t)&(nums[i]));
		++i;
	}
}

static void		test_traverse_right(t_tap *t)
{
	t_dlist			list = FT_DLST(list, t_num, node);
	t_num			nums[64];
	size_t			i;
	t_dlist_node	*curr;

	ft_tap_plan(t, 256);
	i = 0;
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
		FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&list, curr),
				   (uintmax_t)&(nums[i]));
		curr = ft_dlst_prev(&list, curr);
		++i;
	}
	i = 0;
	while ((curr = ft_dlst_popr(&list)))
	{
		FT_TAP_IEQ(t, !!ft_dlst_singular(&list), !!(i == 62));
		FT_TAP_IEQ(t, !!ft_dlst_empty(&list), !!(i == 63));
		FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&list, curr),
				   (uintmax_t)&(nums[i]));
		++i;
	}
}

static void		test_insert(t_tap *t)
{
	t_dlist	list;
	t_num	nums[4];

	ft_tap_plan(t, 9);
	FT_DLST_INIT(&list, t_num, node);
	ft_dlst_pushl(&list, &(nums[0].node));
	ft_dlst_insertr(&(nums[0].node), &(nums[2].node));
	ft_dlst_insertl(&(nums[2].node), &(nums[1].node));
	FT_TAP_UEQ(t, (uintmax_t)ft_dlst_first(&list), (uintmax_t)&(nums[0].node));
	FT_TAP_UEQ(t, (uintmax_t)ft_dlst_last(&list), (uintmax_t)&(nums[2].node));
	FT_TAP_UEQ(t, (uintmax_t)ft_dlst_next(&list, &(nums[0].node)),
		(uintmax_t)&(nums[1].node));
	ft_dlst_swap(&(nums[0].node), &(nums[2].node));
	FT_TAP_UEQ(t, (uintmax_t)ft_dlst_first(&list), (uintmax_t)&(nums[2].node));
	FT_TAP_UEQ(t, (uintmax_t)ft_dlst_last(&list), (uintmax_t)&(nums[0].node));
	FT_TAP_UEQ(t, (uintmax_t)ft_dlst_prev(&list, &(nums[0].node)),
			   (uintmax_t)&(nums[1].node));
	ft_dlst_replace(&(nums[1].node), &(nums[3].node));
	FT_TAP_UEQ(t, (uintmax_t)ft_dlst_prev(&list, &(nums[0].node)),
			   (uintmax_t)&(nums[3].node));
	ft_dlst_remove(&(nums[3].node));
	FT_TAP_UEQ(t, (uintmax_t)ft_dlst_prev(&list, &(nums[0].node)),
			   (uintmax_t)&(nums[2].node));
	FT_TAP_UEQ(t, (uintmax_t)ft_dlst_next(&list, &(nums[2].node)),
			   (uintmax_t)&(nums[0].node));
}

static int		iterate(void *entry, void *acc)
{
	if (((t_num *)entry)->n >= 32)
		return (0);
	*((size_t *)acc) += 1;
	((t_num *)entry)->n *= 10;
	return (1);
}

static int		remove_node_of(void *entry, void *acc)
{
	(void)acc;
	ft_dlst_remove(&(((t_num *)entry)->node));
	return (1);
}

void			test_iterate_left(t_tap *t)
{
	t_dlist			list;
	t_num			nums[64];
	size_t			i;
	t_dlist_node	*curr;

	ft_tap_plan(t, 66);
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
	FT_TAP_UEQ(t, i, 32);
	i = 0;
	curr = ft_dlst_first(&list);
	while (curr)
	{
		if (i < 32)
			FT_TAP_UEQ(t, ((t_num *)FT_DLST_ENTRY(&list, curr))->n, i * 10);
		else
			FT_TAP_UEQ(t, ((t_num *)FT_DLST_ENTRY(&list, curr))->n, i);
		curr = ft_dlst_next(&list, curr);
		++i;
	}
	ft_dlst_foreachl(&list, NULL, &remove_node_of);
	FT_TAP_OK(t, ft_dlst_empty(&list));
}

void			test_iterate_right(t_tap *t)
{
	t_dlist			list;
	t_num			nums[64];
	size_t			i;
	t_dlist_node	*curr;

	ft_tap_plan(t, 66);
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
	FT_TAP_UEQ(t, i, 32);
	i = 0;
	curr = ft_dlst_last(&list);
	while (curr)
	{
		if (i < 32)
			FT_TAP_UEQ(t, ((t_num *)FT_DLST_ENTRY(&list, curr))->n, i * 10);
		else
			FT_TAP_UEQ(t, ((t_num *)FT_DLST_ENTRY(&list, curr))->n, i);
		curr = ft_dlst_prev(&list, curr);
		++i;
	}
	ft_dlst_foreachr(&list, NULL, &remove_node_of);
	FT_TAP_OK(t, ft_dlst_empty(&list));
}

static int		sort_nums(void *e1, void *e2)
{
	return (((t_num *)e1)->n - ((t_num *)e2)->n);
}

static void		test_sort(t_tap *t)
{
	t_dlist			list;
	t_num			nums[64];
	size_t			i;
	t_dlist_node	*curr;

	ft_tap_plan(t, 130);
	FT_DLST_INIT(&list, t_num, node);
	i = 0;
	while (i < 64)
	{
		nums[i].n = i;
		ft_dlst_pushl(&list, &(nums[i].node));
		++i;
	}
	ft_dlst_sort(&list, &sort_nums);
	i = 0;
	curr = ft_dlst_first(&list);
	while (curr)
	{
		FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&list, curr),
			(uintmax_t)&(nums[i]));
		curr = ft_dlst_next(&list, curr);
		++i;
	}
	FT_TAP_UEQ(t, i, 64);
	i = 64;
	curr = ft_dlst_last(&list);
	while (curr)
	{
		--i;
		FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&list, curr),
			(uintmax_t)&(nums[i]));
		curr = ft_dlst_prev(&list, curr);
	}
	FT_TAP_UEQ(t, i, 0);
}

void			test_slice(t_tap *t)
{
	t_dlist			list;
	t_dlist			dst;
	t_num			nums[64];
	size_t			i;
	t_dlist_node	*curr;

	ft_tap_plan(t, 64);
	FT_DLST_INIT(&list, t_num, node);
	FT_DLST_INIT(&dst, t_num, node);
	i = 0;
	while (i < 64)
	{
		ft_dlst_pushr(&list, &(nums[i].node));
		++i;
	}
	ft_dlst_slice(&dst, &(nums[3].node), &(nums[32].node));
	i = 3;
	curr = ft_dlst_first(&dst);
	while (curr)
	{
		FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&dst, curr),
			(uintmax_t)&(nums[i]));
		curr = ft_dlst_next(&dst, curr);
		++i;
	}
	i = 0;
	curr = ft_dlst_first(&list);
	while (curr)
	{
		FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&list, curr),
			(uintmax_t)&(nums[i]));
		curr = ft_dlst_next(&list, curr);
		++i;
		if (i == 3)
			i = 33;
	}
}

void			test_splice(t_tap *t)
{
	t_dlist			dst;
	t_dlist			list1;
	t_dlist			list2;
	t_num			numd[64];
	t_num			num1[64];
	t_num			num2[64];
	size_t			i;
	t_dlist_node	*curr;

	ft_tap_plan(t, 193);
	FT_DLST_INIT(&dst, t_num, node);
	FT_DLST_INIT(&list1, t_num, node);
	FT_DLST_INIT(&list2, t_num, node);
	i = 0;
	while (i < 64)
	{
		ft_dlst_pushr(&dst, &(numd[i].node));
		ft_dlst_pushr(&list1, &(num1[i].node));
		ft_dlst_pushr(&list2, &(num2[i].node));
		++i;
	}
	ft_dlst_splicel(&(numd[3].node), &list1);
	ft_dlst_splicer(&(numd[32].node), &list2);
	i = 0;
	curr = ft_dlst_first(&dst);
	while (curr)
	{
		if (i < 3)
			FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&dst, curr),
				(uintmax_t)&(numd[i]));
		else if (i < 67)
			FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&dst, curr),
				(uintmax_t)&(num1[i - 3]));
		else if (i < 97)
			FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&dst, curr),
				(uintmax_t)&(numd[i - 64]));
		else if (i < 161)
			FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&dst, curr),
				(uintmax_t)&(num2[i - 97]));
		else
			FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&dst, curr),
				(uintmax_t)&(numd[i - 128]));
		curr = ft_dlst_next(&dst, curr);
		++i;
	}
	FT_TAP_UEQ(t, i, 192);
}

static void		test_join(t_tap *t)
{
	t_dlist			dst;
	t_dlist			list1;
	t_dlist			list2;
	t_num			numd[64];
	t_num			num1[64];
	t_num			num2[64];
	size_t			i;
	t_dlist_node	*curr;

	ft_tap_plan(t, 193);
	FT_DLST_INIT(&dst, t_num, node);
	FT_DLST_INIT(&list1, t_num, node);
	FT_DLST_INIT(&list2, t_num, node);
	i = 0;
	while (i < 64)
	{
		ft_dlst_pushr(&dst, &(numd[i].node));
		ft_dlst_pushr(&list1, &(num1[i].node));
		ft_dlst_pushr(&list2, &(num2[i].node));
		++i;
	}
	ft_dlst_joinl(&dst, &list1);
	ft_dlst_joinr(&dst, &list2);
	i = 0;
	curr = ft_dlst_first(&dst);
	while (curr)
	{
		if (i < 64)
			FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&dst, curr),
				(uintmax_t)&(num1[i]));
		else if (i < 128)
			FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&dst, curr),
				(uintmax_t)&(numd[i - 64]));
		else
			FT_TAP_UEQ(t, (uintmax_t)FT_DLST_ENTRY(&dst, curr),
				(uintmax_t)&(num2[i - 128]));
		curr = ft_dlst_next(&dst, curr);
		++i;
	}
	FT_TAP_UEQ(t, i, 192);
}

void			test_dlists(t_tap *t)
{
	FT_TAP_TEST(t, test_traverse_left);
	FT_TAP_TEST(t, test_traverse_right);
	FT_TAP_TEST(t, test_insert);
	FT_TAP_TEST(t, test_iterate_left);
	FT_TAP_TEST(t, test_iterate_right);
	FT_TAP_TEST(t, test_sort);
	FT_TAP_TEST(t, test_slice);
	FT_TAP_TEST(t, test_splice);
	FT_TAP_TEST(t, test_join);
}

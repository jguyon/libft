/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_foreach.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:06:16 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 21:27:23 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_dlists.h"

typedef struct	s_num {
	int				n;
	t_dlist_node	node;
}				t_num;

static int		iter(void *entry, void *acc)
{
	((t_num *)entry)->n = ++(*((int *)acc));
	return (1);
}

static void		test_iterate_left(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[3];
	int		i;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	ft_dlst_pushr(&lst, &(nums[2].node));
	i = 0;
	ft_dlst_foreachl(&lst, &i, &iter);
	FT_TAP_IEQ(t, nums[0].n, 1);
	FT_TAP_IEQ(t, nums[1].n, 2);
	FT_TAP_IEQ(t, nums[2].n, 3);
}

static void		test_iterate_right(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[3];
	int		i;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	ft_dlst_pushr(&lst, &(nums[2].node));
	i = 0;
	ft_dlst_foreachr(&lst, &i, &iter);
	FT_TAP_IEQ(t, nums[0].n, 3);
	FT_TAP_IEQ(t, nums[1].n, 2);
	FT_TAP_IEQ(t, nums[2].n, 1);
	FT_TAP_IEQ(t, i, 3);
}

static int		iter_until(void *entry, void *acc)
{
	(void)entry;
	++(*((int *)acc));
	return (*((int *)acc) == 2 ? 0 : 1);
}

static void		test_iterate_until_left(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[3];
	int		i;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	ft_dlst_pushr(&lst, &(nums[2].node));
	i = 0;
	ft_dlst_foreachl(&lst, &i, &iter_until);
	FT_TAP_IEQ(t, i, 2);
}

static void		test_iterate_until_right(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[3];
	int		i;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	ft_dlst_pushr(&lst, &(nums[2].node));
	i = 0;
	ft_dlst_foreachr(&lst, &i, &iter_until);
	FT_TAP_IEQ(t, i, 2);
}

static void		test_iterate_from_left(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[3];
	int		i;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	ft_dlst_pushr(&lst, &(nums[2].node));
	i = 0;
	ft_dlst_foreachl_from(&lst, &(nums[1].node), &i, &iter);
	FT_TAP_IEQ(t, nums[1].n, 1);
	FT_TAP_IEQ(t, nums[2].n, 2);
	FT_TAP_IEQ(t, i, 2);
}

static void		test_iterate_from_right(t_tap *t)
{
	t_dlist	lst;
	t_num	nums[3];
	int		i;

	FT_DLST_INIT(&lst, t_num, node);
	ft_dlst_pushr(&lst, &(nums[0].node));
	ft_dlst_pushr(&lst, &(nums[1].node));
	ft_dlst_pushr(&lst, &(nums[2].node));
	i = 0;
	ft_dlst_foreachr_from(&lst, &(nums[1].node), &i, &iter);
	FT_TAP_IEQ(t, nums[1].n, 1);
	FT_TAP_IEQ(t, nums[0].n, 2);
	FT_TAP_IEQ(t, i, 2);
}

void			run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_iterate_left);
	FT_TAP_TEST(t, test_iterate_right);
	FT_TAP_TEST(t, test_iterate_until_left);
	FT_TAP_TEST(t, test_iterate_until_right);
	FT_TAP_TEST(t, test_iterate_from_left);
	FT_TAP_TEST(t, test_iterate_from_right);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dlst_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:28:14 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/22 21:42:28 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_dlists.h"

typedef struct	s_num {
	int				n;
	t_dlist_node	node;
}				t_num;

static int		numcmp(void *e1, void *e2)
{
	return (((t_num *)e1)->n - ((t_num *)e2)->n);
}

static void		test_sort(t_tap *t)
{
	t_dlist			lst;
	t_num			nums[] = {{.n = 3}, {.n = 1}, {.n = 2}, {.n = 0}, {.n = 2}};
	t_num			*sorted[] = {&(nums[3]), &(nums[1]), &(nums[2]), &(nums[4]), &(nums[0])};
	size_t			i;
	t_dlist_node	*node;

	FT_DLST_INIT(&lst, t_num, node);
	i = 0;
	while (i < sizeof(nums) / sizeof(nums[0]))
	{
		ft_dlst_pushr(&lst, &(nums[i].node));
		++i;
	}
	ft_dlst_sort(&lst, &numcmp);
	i = 0;
	ft_tap_plan(t, sizeof(nums) / sizeof(nums[0]));
	while ((node = ft_dlst_popl(&lst)))
	{
		FT_TAP_OK(t, sorted[i] == FT_DLST_ENTRY(&lst, node));
		++i;
	}
}

void			run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_sort);
}

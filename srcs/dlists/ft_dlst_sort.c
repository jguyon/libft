/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:24:14 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/07 18:28:52 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_memory.h"
#include "libft/ft_dlists.h"

/*
** Merge two sorted null-terminated linked lists together
*/
static t_dlist_node	*merge_lists(t_dlist *list,
								 t_dlist_node *left, t_dlist_node *right,
								 t_dlist_compare cmp)
{
	t_dlist_node	*merged;
	t_dlist_node	**curr;

	merged = NULL;
	curr = &merged;
	while (left && right)
	{
		if (cmp(FT_DLST_ENTRY(list, left), FT_DLST_ENTRY(list, right)) > 0)
		{
			*curr = right;
			right = right->next;
		}
		else
		{
			*curr = left;
			left = left->next;
		}
		curr = &((*curr)->next);
	}
	*curr = left ? left : right;
	return (merged);
}

/*
** Rebuild a circular doubly-linked list from the sorted null-terminated list
*/
static void			restore_list(t_dlist *list, t_dlist_node *merged)
{
	if (!merged)
	{
		list->head.prev = &(list->head);
		list->head.next = &(list->head);
		return ;
	}
	list->head.next = merged;
	merged->prev = &(list->head);
	while (merged->next)
	{
		merged->next->prev = merged;
		merged = merged->next;
	}
	list->head.prev = merged;
	merged->next = &(list->head);
}

/*
** Merge sort algorithm
**
** The circular doubly-linked list is sorted as a standard null-terminated one
** before being converted back to avoid having to keep
** the prev links up to date.
*/
void				ft_dlst_sort(t_dlist *list, t_dlist_compare cmp)
{
	t_dlist_node	*parts[FT_DLST_SORT_PARTS + 1];
	t_dlist_node	*result;
	t_dlist_node	*next;
	size_t			i;

	ft_bzero(parts, sizeof(parts));
	list->head.prev->next = NULL;
	result = list->head.next;
	while (result)
	{
		next = result->next;
		result->next = NULL;
		i = 0;
		while (parts[i])
		{
			result = merge_lists(list, parts[i], result, cmp);
			parts[i++] = NULL;
		}
		i = i == FT_DLST_SORT_PARTS ? i - 1 : i;
		parts[i] = result;
		result = next;
	}
	i = 0;
	while (i < FT_DLST_SORT_PARTS)
		result = merge_lists(list, parts[i++], result, cmp);
	restore_list(list, result);
}

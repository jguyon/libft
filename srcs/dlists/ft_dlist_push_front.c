/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_push_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:16:30 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/05 12:18:45 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_dlists.h"

void	ft_dlist_push_front(t_dlist *list, t_dlist_node *new)
{
	new->prev = &(list->head);
	new->next = list->head.next;
	new->prev->next = new;
	new->next->prev = new;
}

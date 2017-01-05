/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_insertr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:55:07 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/06 00:28:49 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_dlists.h"

void	ft_dlst_insertr(t_dlist_node *node, t_dlist_node *new)
{
	new->prev = node;
	new->next = node->next;
	new->prev->next = new;
	new->next->prev = new;
}

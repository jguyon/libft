/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_insert_before.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:20:04 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/05 11:55:18 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_dlists.h"

void	ft_dlist_insert_before(t_dlist_node *node, t_dlist_node *new)
{
	new->prev = node->prev;
	new->next = node;
	new->prev->next = new;
	new->next->prev = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_insert_after.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:55:07 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/05 11:56:30 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_dlists.h"

void	ft_dlist_insert_after(t_dlist_node *node, t_dlist_node *new)
{
	new->prev = node;
	new->next = node->next;
	new->prev->next = new;
	new->next->prev = new;
}

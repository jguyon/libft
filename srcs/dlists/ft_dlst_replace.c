/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 00:54:32 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/06 00:56:46 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_dlists.h"

void	ft_dlst_replace(t_dlist_node *node, t_dlist_node *new)
{
	new->prev = node->prev;
	new->next = node->next;
	new->prev->next = new;
	new->next->prev = new;
}

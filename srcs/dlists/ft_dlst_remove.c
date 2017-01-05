/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:23:41 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/06 00:32:45 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_dlists.h"

void	ft_dlst_remove(t_dlist_node *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

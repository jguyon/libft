/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:12:09 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/05 13:13:07 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_dlists.h"

t_dlist_node	*ft_dlist_last(t_dlist *list)
{
	if (list->head.prev == &(list->head))
		return (NULL);
	return (list->head.prev);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_singular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:19:25 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/05 13:20:31 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_dlists.h"

int		ft_dlist_singular(t_dlist *list)
{
	return (list->head.next != &(list->head)
			&& list->head.next == list->head.prev);
}

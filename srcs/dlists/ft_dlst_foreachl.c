/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_foreachl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:38:06 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/07 11:56:30 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_dlists.h"

void	ft_dlst_foreachl(t_dlist *list, void *acc, t_dlist_iterator itr)
{
	ft_dlst_foreachl_from(list, list->head.next, acc, itr);
}

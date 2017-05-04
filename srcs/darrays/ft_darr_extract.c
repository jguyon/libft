/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_extract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 21:14:10 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/22 21:16:32 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darrays.h"
#include "ft_debug.h"

void	*ft_darr_extract(t_darray *arr)
{
	void	*array;

	FT_ASSERT(arr != NULL);
	array = arr->array;
	arr->size = 0;
	arr->array = NULL;
	return (array);
}

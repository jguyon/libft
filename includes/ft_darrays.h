/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darrays.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 23:14:03 by jguyon            #+#    #+#             */
/*   Updated: 2017/05/03 18:57:47 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DARRAYS_H
# define FT_DARRAYS_H

# include <stddef.h>
# include <stdint.h>

/*
** t_darray - dynamic array implementation
**
** /!\ If your array is an array of pointers, parameters indicated as
** pointer to a value should be the *address* of a pointer variable,
** not the pointer itself, since the value to store is the pointer
** and not what it points to.
**
** /!\ You need to keep track of the size of your array yourself
** (e.g. by keeping a count or leaving a null at the end), only the
** total capacity is kept internally.
*/
typedef struct	s_darray {
	size_t			item_size;
	size_t			size;
	void			*array;
}				t_darray;

/*
** ft_darr_init - initialize a darray
** @arr: array to initialize
** @item_size: size in bytes of an item in the array
** @size: full size of the array to create, in items
**
** Returns 0 if successful, -1 otherwise.
*/
int				ft_darr_init(t_darray *arr, size_t item_size, size_t size);

/*
** ft_darr_copy - copy a c array into a darray
** @arr: array to copy into
** @carr: c array to copy from
** @i: index where to begin the copy
** @size: size of @carr in items
**
** Returns 0 if successful, -1 otherwise.
*/
int				ft_darr_copy(t_darray *arr, const void *carr,
					size_t i, size_t size);

/*
** ft_darr_set - set a value in the array, growing it if necessary
** @arr: array to set the value in
** @i: index of the value to set
** @val: pointer to the value to set
**
** Returns 0 if successful, -1 otherwise.
** If @val is NULL, the value will be zeroed.
*/
int				ft_darr_set(t_darray *arr, size_t i, const void *val);

/*
** ft_darr_get - get a value in the array if it exists
** @arr - array to get a value from
** @i - index of the value to get
** @val - pointer to store the value in
**
** Returns -1 if @i is out of bounds, 0 otherwise.
** If @i has not yet been set (or is out of bounds), @val will be zeroed.
*/
int				ft_darr_get(t_darray *arr, size_t i, void *val);

/*
** ft_darr_extract - extract its array from a darray
** @arr: darray to extract from
**
** Can return NULL if no item was set in @arr.
** /!\ The resulting array is allocated and therefore needs to be freed.
*/
void			*ft_darr_extract(t_darray *arr);

#endif

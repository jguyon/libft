/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 23:14:03 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/20 00:00:47 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DARRAY_H
# define FT_DARRAY_H

# include <stddef.h>

/*
** t_darray - dynamic array implementation
** @item_size: size in bytes of an item in the array
** @size: current allocated size of the array, in items
** @array: the array, can be NULL if initialized with a size of 0
** @deflt: pointer to a default value
**
** Note that @size will often be much greater than needed to store
** the value with the biggest index that you set.
** If you want to track that size, you should use it as a null-terminated
** array or wrap this implementation by your own struct and functions
** (the latter would be smart anyway, void pointers are easy to mess up).
**
** /!\ If your array is an array of pointers, parameters indicated as
** pointer to a value should be the *address* of a pointer variable,
** not the pointer itself, since the value to store is the pointer
** and not what it points to.
*/
typedef struct	s_darray {
	size_t		item_size;
	size_t		size;
	void		*array;
	void		*deflt;
}				t_darray;

/*
** ft_darr_init - initialize a darray
** @arr: array to initialize
** @src: array to copy values from
** @item_size: size in bytes of an item in the array
** @size: full size of the array to create, in items
**
** Returns 0 if successful, -1 otherwise.
** @src can be NULL, in which case the array will be filled with 0,
** but if not it should be at lease @size items long.
*/
int				ft_darr_init(t_darray *arr, const void *src,
					size_t item_size, size_t size);

/*
** ft_darr_default - set the default for new or non-existent values
** @arr: array to set a default to
** @deflt: pointer to the default value
**
** If this function is not called or if @deflt is reset to NULL,
** new or non-existing values will simply be filled with zeros.
*/
void			ft_darr_default(t_darray *arr, void *deflt);

/*
** ft_darr_set - set a value in the array, growing it if necessary
** @arr: array to set the value in
** @i: index of the value to set
** @val: pointer to the value to set
**
** Returns 0 if successful, -1 otherwise.
** Note that if reallocation wasn't successful, the array stays intact,
** you can still use it as before.
*/
int				ft_darr_set(t_darray *arr, size_t i, void *val);

/*
** ft_darr_get - get a value in the array if it exists
** @arr - array to get a value from
** @i - index of the value to get
**
** Returns a pointer to the value if it exists, or the default value otherwise.
*/
void			*ft_darr_get(t_darray *arr, size_t i);

/*
** ft_darr_clear - clear memory and reset size to 0
** @arr: array to clear
**
** If the values stored are pointers, this will not free them,
** only the array itself is freed.
*/
void			ft_darr_clear(t_darray *arr);

#endif

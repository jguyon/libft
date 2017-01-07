/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlsts.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:34:54 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/07 12:12:44 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLISTS_H
# define FT_DLISTS_H

# include <stddef.h>

/*
** Embedded doubly linked list implementation
*/

/*
** t_dlist_node - list node type to embed in your entry struct
*/
typedef struct	s_dlist_node {
	struct s_dlist_node	*prev;
	struct s_dlist_node *next;
}				t_dlist_node;

/*
** t_dlist - list type from which to retrieve entries
*/
typedef struct	s_dlist {
	size_t			offset;
	t_dlist_node	head;
}				t_dlist;

/*
** t_dlist_iterator - function pointer type used to iterate over entries
*/
typedef int		(*t_dlist_iterator)(void *entry, void *acc);

/*
** FT_DLST_OFFSET - get the offset between your struct and the member node
** @type: type of the entry struct
** @mbr: name of the member containing the list node
*/
# define FT_DLST_OFFSET(type, mbr) ((size_t)(void *)&(((type *)0)->mbr))

/*
** FT_DLST_NODE - retrieve the node corresponding to an entry
** @lst: list containing @e
** @e: entry corresponding to the node
*/
# define FT_DLST_NODE(lst, e) ((t_dlist_node *)(((void *)(e)) + (lst)->offset))

/*
** FT_DLST_ENTRY - retrieve the entry corresponding to a node
** @lst: list containing @n
** @n: node corresponding to the entry
** @type: type of the entry
*/
# define FT_DLST_ENTRY(lst, n) (((void *)(n)) - (lst)->offset)

/*
** ft_dlst_init - initialize a list
** @list: list to initialize
** @offset: offset of the node member for the type of the entries
*/
void			ft_dlst_init(t_dlist *list, size_t offset);

/*
** FT_DLST_INIT - initialize a list for a given entry type
** @l: list to initialize
** @t: type of the entries
** @m: member name of the list node in @t
*/
# define FT_DLST_INIT(l, t, m) (ft_dlst_init(l, FT_DLST_OFFSET(t, m)))

/*
** ft_dlst_insertl - insert a new node before another
** @node: node after which to insert
** @new: node to insert
*/
void			ft_dlst_insertl(t_dlist_node *node, t_dlist_node *new);

/*
** ft_dlst_insertr - insert a new node after another
** @node: node after which to insert
** @new: node to insert
*/
void			ft_dlst_insertr(t_dlist_node *node, t_dlist_node *new);

/*
** ft_dlst_pushl - push a new node at the head of a list
** @list: list to insert into
** @new: node to insert
*/
void			ft_dlst_pushl(t_dlist *list, t_dlist_node *new);

/*
** ft_dlst_pushr - push a new node at the tail of a list
** @list: list to insert into
** @new: node to insert
*/
void			ft_dlst_pushr(t_dlist *list, t_dlist_node *new);

/*
** ft_dlst_remove - remove a node from a list
** @node: node to remove
*/
void			ft_dlst_remove(t_dlist_node *node);

/*
** ft_dlst_popl - removes a node from the head of a list
** @list: list to remove from
*/
t_dlist_node	*ft_dlst_popl(t_dlist *list);

/*
** ft_dlst_popr - removes a node from the tail of a list
** @list: list to remove from
*/
t_dlist_node	*ft_dlst_popr(t_dlist *list);

/*
** ft_dlst_replace - replaces a node by an orphan one
** @node: node to replace
** @new: node to insert
*/
void			ft_dlst_replace(t_dlist_node *node, t_dlist_node *new);

/*
** ft_dlst_swap - swaps two nodes
** @n1: first node
** @n2: second node
*/
void			ft_dlst_swap(t_dlist_node *n1, t_dlist_node *n2);

/*
** ft_dlst_prev - retrieve the previous node in a list
** @list: list containing @node
** @node: node to get the previous node of
*/
t_dlist_node	*ft_dlst_prev(t_dlist *list, t_dlist_node *node);

/*
** ft_dlst_next - retrieve the next node in a list
** @list: list containing @node
** @node: node to get the next node of
*/
t_dlist_node	*ft_dlst_next(t_dlist *list, t_dlist_node *node);

/*
** ft_dlst_first - retrieve the first node in a list
** @list: list to retrieve from
*/
t_dlist_node	*ft_dlst_first(t_dlist *list);

/*
** ft_dlst_first - retrieve the last node in a list
** @list: list to retrieve from
*/
t_dlist_node	*ft_dlst_last(t_dlist *list);

/*
** ft_dlst_empty - check if a list contains no node
** @list: list to test
*/
int				ft_dlst_empty(t_dlist *list);

/*
** ft_dlst_singular - check if a list contains only one node
** @list: list to test
*/
int				ft_dlst_singular(t_dlist *list);

/*
** ft_dlst_foreachl - iterate over the entries of a list from left to right
** @list: list to iterate over
** @acc: data to pass to @itr
** @itr: function to call with each entry, iteration stops if it returns 0
*/
void			ft_dlst_foreachl(t_dlist *list, void *acc,
									t_dlist_iterator itr);

/*
** ft_dlst_foreachr - iterate over the entries of a list from right to left
** @list: list to iterate over
** @acc: data to pass to @itr
** @itr: function to call with each entry, iteration stops if it returns 0
*/
void			ft_dlst_foreachr(t_dlist *list, void *acc,
									t_dlist_iterator itr);

/*
** ft_dlst_foreachl_from - iterate over a list from a specific entry
** @list: list to iterate over
** @first: first node to iterate over
** @acc: data to pass to @itr
** @itr: function to call with each entry, iteration stops if it returns 0
*/
void			ft_dlst_foreachl_from(t_dlist *list, t_dlist_node *first,
										void *acc, t_dlist_iterator itr);

/*
** ft_dlst_foreachr_from - iterate over a list from a specific entry
** @list: list to iterate over
** @first: first node to iterate over
** @acc: data to pass to @itr
** @itr: function to call with each entry, iteration stops if it returns 0
*/
void			ft_dlst_foreachr_from(t_dlist *list, t_dlist_node *first,
									  void *acc, t_dlist_iterator itr);

#endif

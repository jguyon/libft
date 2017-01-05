/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlists.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:34:54 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/06 00:04:41 by jguyon           ###   ########.fr       */
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
** FT_DLIST_OFFSET - get the offset between your struct and the member node
** @type: type of the entry struct
** @mbr: name of the member containing the list node
*/
# define FT_DLIST_OFFSET(type, mbr) ((size_t)(char *)&(((type *)0)->mbr))

/*
** FT_DLIST_NODE - retrieve the node corresponding to an entry
** @lst: list containing @e
** @e: entry corresponding to the node
*/
# define FT_DLIST_NODE(lst, e) ((t_dlist_node *)(((void *)(e)) + (lst)->offset))

/*
** FT_DLIST_ENTRY - retrieve the entry corresponding to a node
** @lst: list containing @n
** @n: node corresponding to the entry
** @type: type of the entry
*/
# define FT_DLIST_ENTRY(lst, n) (((void *)(n)) - (lst)->offset)

/*
** ft_dlist_init - initialize a list
** @list: list to initialize
** @offset: offset of the node member for the type of the entries
*/
void			ft_dlist_init(t_dlist *list, size_t offset);

/*
** FT_DLIST_INIT - initialize a list for a given entry type
** @l: list to initialize
** @t: type of the entries
** @m: member name of the list node in @t
*/
# define FT_DLIST_INIT(l, t, m) (ft_dlist_init(l, FT_DLIST_OFFSET(t, m)))

/*
** ft_dlist_insert_before - insert a new node before another
** @node: node after which to insert
** @new: node to insert
*/
void			ft_dlist_insert_before(t_dlist_node *node, t_dlist_node *new);

/*
** ft_dlist_insert_after - insert a new node after another
** @node: node after which to insert
** @new: node to insert
*/
void			ft_dlist_insert_after(t_dlist_node *node, t_dlist_node *new);

/*
** ft_dlist_push_front - push a new node at the head of a list
** @list: list to insert into
** @new: node to insert
*/
void			ft_dlist_push_front(t_dlist *list, t_dlist_node *new);

/*
** ft_dlist_push_back - push a new node at the tail of a list
** @list: list to insert into
** @new: node to insert
*/
void			ft_dlist_push_back(t_dlist *list, t_dlist_node *new);

/*
** ft_dlist_remove - remove a node from a list
** @node: node to remove
*/
void			ft_dlist_remove(t_dlist_node *node);

/*
** ft_dlist_pop_front - removes a node from the head of a list
** @list: list to remove from
*/
t_dlist_node	*ft_dlist_pop_front(t_dlist *list);

/*
** ft_dlist_pop_back - removes a node from the tail of a list
** @list: list to remove from
*/
t_dlist_node	*ft_dlist_pop_back(t_dlist *list);

/*
** ft_dlist_prev - retrieve the previous node in a list
** @list: list containing @node
** @node: node to get the previous node of
*/
t_dlist_node	*ft_dlist_prev(t_dlist *list, t_dlist_node *node);

/*
** ft_dlist_next - retrieve the next node in a list
** @list: list containing @node
** @node: node to get the next node of
*/
t_dlist_node	*ft_dlist_next(t_dlist *list, t_dlist_node *node);

/*
** ft_dlist_first - retrieve the first node in a list
** @list: list to retrieve from
*/
t_dlist_node	*ft_dlist_first(t_dlist *list);

/*
** ft_dlist_first - retrieve the last node in a list
** @list: list to retrieve from
*/
t_dlist_node	*ft_dlist_last(t_dlist *list);

/*
** ft_dlist_empty - check if a list contains no node
** @list: list to test
*/
int				ft_dlist_empty(t_dlist *list);

/*
** ft_dlist_singular - check if a list contains only one node
** @list: list to test
*/
int				ft_dlist_singular(t_dlist *list);

#endif

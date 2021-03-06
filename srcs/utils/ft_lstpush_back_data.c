/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:02:07 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 12:02:11 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_lstpush_back_data(t_data *lst, t_stack *node)
{
	if (!lst->size)
	{
		lst->head = node;
		node->prev = node;
		node->next = node;
		lst->size += 1;
		return ;
	}
	node->next = lst->head;
	node->prev = lst->head->prev;
	lst->head->prev = node;
	node->prev->next = node;
	lst->size += 1;
}

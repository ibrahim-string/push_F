/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:03:06 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/19 16:50:57 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos(t_stack *stack, int element)//done
{
	t_stack	*courant;
	int		i;

	courant = stack;
	i = 0;
	while (courant)
	{
		if (courant->data == element)
			return (i);
		i++;
		courant = courant-> next;
	}
	return (-1);
}

int	min_element(t_stack *stackA)//done
{
	int	min_element;

	min_element = INT_MAX;
	while (stackA)
	{
		if (stackA->data < min_element)
			min_element = stackA->data;
		stackA = stackA -> next;
	}
	return (min_element);
}

int	ft_lstsize(t_stack *lst) //done
{
	int		i;
	t_stack	*courant;

	i = 0;
	courant = lst;
	while (courant != NULL)
	{
		i++;
		courant = courant -> next;
	}
	return (i);
}

int	find_max_elememt(t_stack *stackB)//done
{
	int		max_element;
	t_stack	*courant;

	max_element = INT_MIN;
	courant = stackB;
	while (courant)
	{
		if (courant->data > max_element)
			max_element = courant->data;
		courant = courant->next;
	}
	return (max_element);
}

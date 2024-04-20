/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:33:05 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/20 11:19:31 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stackb(t_stack **stackA, t_stack **stackB)//done
{
	while (ft_lstsize(*stackA) != 0)
	{
		execute_print_move(stackA, stackB, "pb\n");
	}
}

void	the_rest_of_case(t_stack **stackA, int j)//done
{
	if (j == 1)
	{
		sa(*stackA);
		ft_printf("sa\n");
	}
	else
	{
		rra(stackA);
		ft_printf("rra\n");
	}
}

void	sort_three_element(t_stack **stackA)//done
{
	t_stack	*courant;
	t_stack	*last;
	t_stack	*tmp;

	last = *stackA;
	tmp = (*stackA)->next;
	courant = *stackA;
	while (last->next != NULL)
		last = last->next;
	while (!is_stack_sorted(*stackA, 0))
	{
		if (courant->data > last->data)
			the_rest_of_case(stackA, 0);
		else if (courant -> data > tmp->data)
			the_rest_of_case(stackA, 1);
		else if (tmp->data > last->data)
			the_rest_of_case(stackA, 0);
		courant = *stackA;
		last = *stackA;
		while (last->next != NULL)
			last = last->next;
		tmp = (*stackA)->next;
	}
}

void	sort_five_element(t_stack **stackA, t_stack **stackB)//done
{
	int	i;
	int	min;

	i = 0;
	while (i++ < 2)
	{
		min = min_element(*stackA);
		while (pos(*stackA, min) != 0)
		{
			if (pos(*stackA, min) <= ft_lstsize(*stackA) / 2)
			{
				ra(stackA);
				ft_printf("ra\n");
			}
			else
			{
				rra(stackA);
				ft_printf("rra\n");
			}
		}
		pb(stackA, stackB);
		ft_printf("pb\n");
	}
	sort_three_element(stackA);
	push_back_to_stacka(stackA, stackA);
}

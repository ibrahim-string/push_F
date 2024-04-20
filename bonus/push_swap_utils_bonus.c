/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:03:02 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/19 16:32:58 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

int	is_stack_sorted(t_stack *s, int element)//done
{
	t_stack	*courant;
	t_stack	*courant1;

	courant = s;
	courant1 = s->next;
	while (courant1 != NULL)
	{
		if (element == 1 && courant->data < courant1->data)
			return (0);
		else if (element == 0 && courant->data > courant1->data)
			return (0);
		courant = courant->next;
		courant1 = courant1->next;
	}
	return (1);
}
// void	printstack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d \n", stack->data);
// 		stack = stack -> next;
// 	}
// }

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	push(t_stack **stackA, int data)//done
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		printf("Allocation Failure");
		return ;
	}
	node -> data = data;
	node -> next = *stackA;
	*stackA = node;
}

t_stack	*pop(t_stack **stack_s)//done
{
	t_stack	*tmp;
	t_stack	*courant;

	tmp = *stack_s;
	courant = (*stack_s)-> next;
	tmp -> data = (*stack_s)-> data;
	*stack_s = courant;
	return (tmp);
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

// int main(int argc, char **argv)
// {
//     (void)argc;
//     int i = 0;
//     char **tab = ft_split(argv[1],' ');
//     while(tab[i])
//     {
//         printf("data = %s\n",tab[i]);
//         i++;
//     }
//     if(check_type(tab))
//     {
//         printf("na\n");
//     }
// }

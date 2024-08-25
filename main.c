/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:49 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/20 15:58:42 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stackA, int data)//done
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		ft_printf("Allocation Failure");
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

void	sort_stacka(t_stack **stackA)//done
{
	int	min;

	min = min_element(*stackA);
	while (pos(*stackA, min) != 0)
	{
		if (pos(*stackA, min) <= ft_lstsize(*stackA) / 2)
		{
			ra(stackA);
			ft_printf("ra\n");
		}
		else if (pos(*stackA, min) > ft_lstsize(*stackA) / 2)
		{
			rra(stackA);
			ft_printf("rra\n");
		}
	}
}

void	fill_the_stack(int argc, char **argv, t_stack **stackA)//done
{
	long	*arr;
	int		size;

	size = nbr_of_arguments(argc, argv);
	arr = check_arguments(argc, argv);
	while (size > 0)
	{
		push(stackA, arr[size - 1]);
		size--;
	}
	free(arr);
}
int check_syntax_errors(Token *tokens)
{
    int open_parentheses = 0;
    Token *current = tokens;
    Token *prev = NULL;

    while (current)
    {
        // Check for unmatched parentheses
        if (current->type == TOKEN_OPEN_PARENTH)
            open_parentheses++;
        else if (current->type == TOKEN_CLOSE_PARENTH)
            open_parentheses--;

        if (open_parentheses < 0)
        {
            printf("Syntax Error: Unmatched closing parenthesis.\n");
            return 1;
        }

        // Check for consecutive operators or missing arguments
        if (prev)
        {
            if ((prev->type == TOKEN_PIPE || prev->type == TOKEN_DOUBLE_PIPE ||
                 prev->type == TOKEN_DOUBLE_AMP || prev->type == TOKEN_REDIR_OUT ||
                 prev->type == TOKEN_REDIR_IN || prev->type == TOKEN_REDIR_APPEND ||
                 prev->type == TOKEN_REDIR_HERE_DOC) &&
                (current->type == TOKEN_PIPE || current->type == TOKEN_DOUBLE_PIPE ||
                 current->type == TOKEN_DOUBLE_AMP || current->type == TOKEN_REDIR_OUT ||
                 current->type == TOKEN_REDIR_IN || current->type == TOKEN_REDIR_APPEND ||
                 current->type == TOKEN_REDIR_HERE_DOC))
            {
                printf("Syntax Error: Consecutive operators detected: %s and %s.\n", prev->value, current->value);
                return 1;
            }

            // Check for operators at the beginning or end of the input
            if ((prev->type == TOKEN_PIPE || prev->type == TOKEN_DOUBLE_PIPE ||
                 prev->type == TOKEN_DOUBLE_AMP || prev->type == TOKEN_REDIR_OUT ||
                 prev->type == TOKEN_REDIR_IN || prev->type == TOKEN_REDIR_APPEND ||
                 prev->type == TOKEN_REDIR_HERE_DOC) && !current->next)
            {
                printf("Syntax Error: Operator '%s' at the end of input.\n", prev->value);
                return 1;
            }
        }

        prev = current;
        current = current->next;
    }

    if (open_parentheses > 0)
    {
        printf("Syntax Error: Unmatched opening parenthesis.\n");
        return 1;
    }

    return 0;
}
#include "minishell.h"

// Function prototypes (if needed)
int check_syntax_errors(Token *tokens);

// Other functions and code
void print_ast(t_ast *ast, int depth) { /* ... */ }
t_queue *push_queue(t_queue *queue, Token *node) { /* ... */ }
t_ast *push_to_ast_stack(t_ast *ast_stack, t_ast *ast_node) { /* ... */ }
t_ast *pop_ast_stack(t_ast **ast_stack) { /* ... */ }
void print_queue(t_queue *queue) { /* ... */ }
void print_tokens(Token *tokens) { /* ... */ }

// Syntax error checking function
int check_syntax_errors(Token *tokens)
{
    // Function implementation here
    /* ... */
}

// Main function
int main(void)
{
    char *input;
    Token **tokens;
    t_queue *queue;

    tokens = NULL;
    while (1)
    {
        input = readline("Minishell$ ");
        tokens = tokenize(input);

        // Check for syntax errors
        if (check_syntax_errors(*tokens))
        {
            printf("Syntax error detected, please fix your input.\n");
            continue;
        }

        queue = generate_postfix(*tokens);
        while (queue)
        {
            printf("%s ", queue->node->value);
            queue = queue->next;
        }
        printf("\n");

        // t_ast *ast = generate_ast_from_postfix(*tokens);
        // print_ast(ast, 5);
    }
    return (0);
}

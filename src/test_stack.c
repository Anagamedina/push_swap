/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:20:59 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/30 11:09:08 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *stack)
{
    t_stack *current;

    current = stack;
    while(current != NULL)
    {
        printf("stack  es %d\n", current->value);
        current = current->next;
    }
}

void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
    printf("Pila A:\n");
    print_stack(stack_a);
    printf("Pila B:\n");
    print_stack(stack_b);
}


void print_push_costs(t_stack *stack)
{
    while(stack)
    {
        printf("Nodo %d, Costo de push: %d\n", stack->value, stack->push_cost);
        stack = stack->next;
    }
}

void	print_stacks_x(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = stack_a;
	current_b = stack_b;
	printf("%s\t\t\t%s\n", "Stack A", "Stack B");
	printf("%s\t\t\t%s\n", "-------", "-------");
	while (current_a != NULL || current_b != NULL)
	{
		if (current_a != NULL)
		{
			printf("[%d]-> %d", current_a->index, current_a->value);
			current_a = current_a->next;
		}
		else
			printf("[xx]-> xxxx");
		printf("\t\t");
		if (current_b != NULL)
		{
			printf("[%d]-> %d", current_b->index, current_b->value);
			current_b = current_b->next;
		}
		else
			printf("[xx]-> xxxx");
		printf("\n");
	}
	if (stack_a == NULL)
		printf("Stack A empty!\n");
	if (stack_b == NULL)
		printf("Stack B empty!\n");
}

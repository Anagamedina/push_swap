/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:43:20 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/30 16:52:50 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target_node(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_index;

	while (stack_b)
	{
		best_index = LONG_MAX;
		target_node = NULL;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_index)
			{
				best_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (target_node == NULL)
			stack_b->target_node = find_value_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void set_price(t_stack *stack_a, t_stack *stack_b)
{
    int l_a = stack_len(stack_a);
    int len_b = stack_len(stack_b);

    while (stack_b)
    {
        // Inicializar el costo de empuje
        stack_b->push_cost = stack_b->index;

        // Ajustar el costo basado en la posición relativa
        if (stack_b->index < 0)
            stack_b->push_cost = len_b + stack_b->index;

        // Ajustar el costo con respecto al nodo objetivo
        if (stack_b->target_node->index >= 0)
            stack_b->push_cost += stack_b->target_node->index;
        else
            stack_b->push_cost += l_a + stack_b->target_node->index;

        stack_b = stack_b->next;
    }
}


t_stack	*find_cheapest_node(t_stack *stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = stack_b;
	if (!stack_b)
		return (NULL);
	while (stack_b)
	{
		if (stack_b->push_cost < cheapest_node->push_cost)
			cheapest_node = stack_b;
		stack_b = stack_b->next;
	}
	return (cheapest_node);
}

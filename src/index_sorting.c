/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:31:54 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/30 13:48:22 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_positive_positions(t_stack **stack_a, t_stack **stack_b, t_stack *best_index)
{
	if (best_index->index > 0 && best_index->target_node->index > 0)
	{
		while (best_index != *stack_b && best_index->target_node != *stack_a)
		{
			rb(stack_b);
			ra(stack_a);
		}
		while (best_index != *stack_b)
			rb(stack_b);
		while(best_index->target_node != *stack_a)
			ra(stack_a);
	}
}


void	handle_negative_positions(t_stack **stack_a, t_stack **stack_b, t_stack	*best_index)
{
	if (best_index->index < 0 && best_index->target_node->index < 0)
    {
        while (best_index != *stack_b && best_index->target_node != *stack_a)
        {
            rrb(stack_b);
            rra(stack_a);
        }
        while (best_index != *stack_b)
            rrb(stack_b);
        while (best_index->target_node != *stack_a)
            rra(stack_a);
    }

}

void handle_mixed_positions(t_stack **stack_a, t_stack **stack_b, t_stack *best_index)
{
    if (best_index->index > 0 && best_index->target_node->index < 0)
    {
        // Mueve ambos nodos hacia la posición correcta usando rotaciones simultáneas
        while (best_index != *stack_b && best_index->target_node != *stack_a)
        {
            rb(stack_b);
            rra(stack_a);
        }
    }
    else if (best_index->index < 0 && best_index->target_node->index > 0)
    {
        // Mueve ambos nodos hacia la posición correcta usando rotaciones simultáneas
        while (best_index != *stack_b && best_index->target_node != *stack_a)
        {
            rrb(stack_b);
            ra(stack_a);
        }
    }

    // Finaliza moviendo los nodos restantes a la posición correcta en cada stack
    while (best_index != *stack_b)
        rb(stack_b);
    while (best_index->target_node != *stack_a)
        ra(stack_a);
}

/*void	handle_mixed_positions(t_stack **stack_a, t_stack **stack_b, t_stack *best_index)
{

}*/

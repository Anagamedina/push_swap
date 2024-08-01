/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:31:54 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/31 18:30:56 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    handle_pos(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	if (cheapest->index > 0 && cheapest->target_node->index > 0)
	{
		while (cheapest != *stack_b && cheapest->target_node != *stack_a)
		{
            rr(stack_a, stack_b);
			//rb(stack_b);
			//ra(stack_a);
		}
		while (cheapest != *stack_b)
			rb(stack_b);
		while (cheapest->target_node != *stack_a)
			ra(stack_a);
	}
}

void    handle_neg(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
    if (cheapest->index < 0 && cheapest->target_node->index < 0)
    {
        while (cheapest != *stack_b && cheapest->target_node != *stack_a)
        {
            rrr(stack_a, stack_b);
            //rrb(stack_b);
            //rra(stack_a);
        }
        while (cheapest != *stack_b)
            rrb(stack_b);
        while (cheapest->target_node != *stack_a)
            rra(stack_a);
    }
}

void handle_mix(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
    if (cheapest->index > 0 && cheapest->target_node->index < 0)
    {
        while (cheapest != *stack_b && cheapest->target_node != *stack_a)
        {
            rb(stack_b);
            rra(stack_a);
        }
    }
    else if (cheapest->index < 0 && cheapest->target_node->index > 0)
    {
        while (cheapest != *stack_b && cheapest->target_node != *stack_a)
        {
            rrb(stack_b);
            ra(stack_a);
        }
    }
    while (cheapest != *stack_b)
        rb(stack_b);
    while (cheapest->target_node != *stack_a)
        ra(stack_a);
}

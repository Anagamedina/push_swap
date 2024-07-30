/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:12:55 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/30 16:20:40 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	move_elements_to_b(stack_a, stack_b);
	while (*stack_b)
	{
		t_stack	*best_index;
		assign_index(*stack_a);
		assign_index(*stack_b);
		set_target_node(*stack_a, *stack_b);
		set_price(*stack_a, *stack_b);
		best_index = find_cheapest_node(*stack_b);
		if (best_index->index > 0 && best_index->target_node->index > 0)
			handle_positive_positions(stack_a, stack_b, best_index);
		else if (best_index->index < 0 && best_index->target_node->index < 0)
			handle_negative_positions(stack_a, stack_b, best_index);
		else
			handle_mixed_positions(stack_a, stack_b, best_index);
		pa(stack_a, stack_b);
	}
	assign_index(*stack_a);
	top_smaller_node(stack_a);
}


/*void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	move_elements_to_b(stack_a, stack_b);
	while (*stack_b)
	{
		//set_current_position(*stack_a);
		//set_current_position(*stack_b);
		assign_index(*stack_a);
		assign_index(*stack_b);
		set_target_node(*stack_a, *stack_b);
		set_price(*stack_a, *stack_b);
		move_cheapest_to_a(stack_a, stack_b);
	}
	assign_index(*stack_a);
	//set_current_position(*stack_a);
	top_smaller_node(stack_a);
}*/

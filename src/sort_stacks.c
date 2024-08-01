/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:12:55 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/31 18:51:34 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	//printf("ANTES DE MOVE_ELEMENTS_TO_B\n");
	// print_stacks_x(*stack_a, *stack_b);
	move_elements_to_b(stack_a, stack_b);
	// printf("-----------------------------\n");
	// printf("DESPUES DE MOVE_ELEMENTS_TO_B\n");
	// print_stacks_x(*stack_a, *stack_b);
	// int	i = 0;
	// while (*stack_b && i == 3)
	while (*stack_b)
	{
		// printf("---------------------\n");
		// printf("ITERACION I: %i \n", i);
		// printf("---------------------\n");

		// printf("ASSIGN INDEX A: \n");
		assign_index(*stack_a);
		// print_stacks_x(*stack_a, *stack_b);
		
		// printf("---------------------\n");
		// printf("ASSIGN INDEX B: \n");
		assign_index(*stack_b);
		// print_stacks_x(*stack_a, *stack_b);
		// printf("---------------------\n");

		set_target_node(*stack_a, *stack_b);
		set_price(*stack_a, *stack_b);
		cheapest = find_cheapest_node(*stack_b);
		//if (cheapest->index > 0 && cheapest->target_node->index > 0)
		handle_pos(stack_a, stack_b, cheapest);
		//else if (cheapest->index < 0 && cheapest->target_node->index < 0)
		handle_neg(stack_a, stack_b, cheapest);
		//else
		handle_mix(stack_a, stack_b, cheapest);
		pa(stack_a, stack_b);
		// i++;
	}
	//exit(0);
	assign_index(*stack_a);
	top_smaller_node(stack_a);
}
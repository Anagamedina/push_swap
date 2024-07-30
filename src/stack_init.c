/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:38:57 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/30 17:07:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = ft_calloc(1, sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	//node->above_median = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	append_node(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = new_node(value);
	if (!(*stack))
	{
		*stack = node;
		//node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack	*create_stack_from_args(int *parsed_args, int argc)
{
	t_stack				*stack;
	int					i;

	i = 0;
	stack = NULL;
	while (i < (argc - 1))
	{
		append_node(&stack, parsed_args[i]);
		i++;
	}
	assign_index(stack);
	return (stack);
}

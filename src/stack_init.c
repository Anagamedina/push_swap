/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:38:57 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/31 18:30:25 by anamedin         ###   ########.fr       */
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
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	assign_index(t_stack *stack)
{
	t_stack		*current;
	int			i;
	int			size;

	i = 0;
	size = stack_len(stack);
	current = stack;
	while (current->next && i < (size / 2))
	{
		current->index = i;
		current = current->next;
		i++;
	}
	while (current)
	{
		current->index = i - size;
		current = current->next;
		i++;
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

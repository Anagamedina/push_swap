/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:49:04 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/30 17:04:56 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_len(t_stack *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	check_order(t_stack *stack)
{
	if (!stack)
		return (FALSE);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

t_stack	*find_last_node(t_stack *stack)
{
	t_stack	*current_last;

	current_last = stack;
	while (current_last && current_last->next)
	{
		current_last = current_last->next;
	}
	return (current_last);
}

t_stack	*find_value_min(t_stack *stack)
{
	long			min;
	t_stack			*min_node;

	min_node = NULL;
	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*find_value_max(t_stack *stack)
{
	long				max;
	t_stack				*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MAX;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void assign_index(t_stack *stack)
{
	t_stack		*current;
	int			i;
	int			size;

	i = 0;
	size = stack_len(stack);
	current = stack;
	while (current->next && i<= (size / 2))
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
/*void assign_index(t_stack *stack)
{
    int size = stack_len(stack);
    int half_size = size / 2;
    int i = 0;
    t_stack *current = stack;

    // Asignar índices positivos
    while (current && i < half_size)
    {
        current->index = i;
        current = current->next;
        i++;
    }

    // Asignar índices negativos
    while (current)
    {
        current->index = -(size - i);
        current = current->next;
        i++;
    }
}*/


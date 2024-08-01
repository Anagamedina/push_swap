/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:41:18 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/31 18:26:05 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tiny_sort(t_stack **stack_a)
{
	t_stack	*f;
	t_stack	*s;
	t_stack	*t;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	f = *stack_a;
	s = f->next;
	t = s->next;
	if (f->value > s->value && f->value > t->value && s->value > t->value)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (f->value > s->value && f->value > t->value && s->value < t->value)
		ra(stack_a);
	else if (f->value > s->value && f->value < t->value)
		sa(stack_a);
	else if (f->value < s->value && f->value > t->value)
		rra(stack_a);
	else if (f->value < s->value && s->value > t->value)
	{
		sa(stack_a);
		ra(stack_a);
	}
}
/*
static int	quantity_elements_head(t_stack **stack_a)
{
	int	len;
	int	i;
	int count;
	t_stack	*current;
	
	count = 0;
	i = 0;
	len = stack_len(*stack_a) / 2;
	current = (*stack_a);
	while (i < len)
	{
		if (current->index < 0)
			count++;
		i++;
		current = current->next;
	}
	return (count);
}

static int	quantity_elements_tail(t_stack **stack_a)
{
	int	len;
	int	i;
	int count;
	t_stack	*current;
	
	count = 0;
	i = stack_len(*stack_a) - 1;
	len = stack_len(*stack_a) / 2;
	current = find_last_node(*stack_a);
	while (i >= len)
	{
		if (current->index < 0)
			count++;
		i--;
		current = current->prev;
	}
	return (count);
}*/

void	move_elements_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	// int	nums_parte_1_stack = quantity_elements_head(stack_a);
	// int nums_parte_2_stack = quantity_elements_tail(stack_a);
	//printf("LEN STACK A: %d\n", stack_len(*stack_a) / 2);
	//printf("CANTIDAD NUMEROS NEGATIVOS/FLAG EN PARTE 1 STACK A: %d\n", nums_parte_1_stack);
	//printf("CANTIDAD NUMEROS NEGATIVOS/FLAG EN PARTE 2 STACK A: %d\n", nums_parte_2_stack);
	len_a = stack_len(*stack_a);
	while (len_a > 3)
	{
		pb(stack_b, stack_a);
		//if ((*stack_b)->index < 0)
			//rb(stack_b);
		len_a--;
	}
	len_a = stack_len(*stack_a);
	if (len_a == 3)
		tiny_sort(stack_a);
}

void	top_smaller_node(t_stack **stack_a)
{
	t_stack			*smallest;
	int				len;

	smallest = find_value_min(*stack_a);
	len = stack_len(*stack_a);
	if (smallest->index <= len / 2)
	{
		while ((*stack_a)->value != smallest->value)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != smallest->value)
			rra(stack_a);
	}
}

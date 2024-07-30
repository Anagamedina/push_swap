/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:41:18 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/30 17:06:12 by anamedin         ###   ########.fr       */
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

void	move_elements_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	while (len_a > 3)
	{
		pb(stack_b, stack_a);
		//como hago el RA
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

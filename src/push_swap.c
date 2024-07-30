/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:53:19 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/30 17:09:06 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				*parsed_args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	parsed_args = parse_args(argc, argv);
	if (!parsed_args)
		free_error(stack_a, stack_b);
	stack_a = create_stack_from_args(parsed_args, argc);
	free(parsed_args);
	if (!check_order(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a);
		if (stack_len(stack_a) == 3)
			tiny_sort(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	//print_stacks_x(stack_a, stack_b);
	free_error(stack_a, stack_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:08:57 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/25 16:19:39 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	validate_duplicate(int *parsed_args, int current_index)
{
	int	j;

	j = 0;
	while (j < current_index)
	{
		if (parsed_args[j] == parsed_args[current_index])
			return (1);
		j++;
	}
	return (0);
}

int	validate_syntax(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*parse_args(int argc, char **argv)
{
	int			*parsed_args;
	int			i;
	long long	temp_value;

	i = 1;
	parsed_args = (int *)malloc((argc - 1) * sizeof(int));
	if (!parsed_args)
		error_exit();
	while (i < (argc))
	{
		if (!validate_syntax(argv[i]))
			error_exit();
		temp_value = ft_atoll(argv[i]);
		if ((temp_value > INT_MAX || temp_value < INT_MIN)
			|| (ft_strlen(argv[i]) > 12 && temp_value == 0))
			error_exit();
		parsed_args[i - 1] = (int)temp_value;
		if (validate_duplicate(parsed_args, i - 1))
			error_exit();
		i++;
	}
	return (parsed_args);
}

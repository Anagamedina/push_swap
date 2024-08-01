/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:05:56 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/31 18:21:12 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int					value;
	int					index;
	int					push_cost;
	struct s_stack		*target_node;
	struct s_stack		*prev;
	struct s_stack		*next;
}						t_stack;

//*** Validate ***
int			validate_duplicate(int *parsed_args, int current_index);
int			validate_syntax(char *arg);
int			*parse_args(int argc, char **argv);

//*** Handle errors-free ***
void		free_stack(t_stack **stack);
void		free_error(t_stack *stack_a, t_stack *stack_b);
void		error_exit(void);

//*** Functions libft ***
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
long long	ft_atoll(const char *str);
size_t		ft_strlen(const char *str);
char		**ft_split(char const *s, char c);

//*** Stack creation ***
t_stack		*create_stack_from_args(int *parsed_args, int argc);
void		append_node(t_stack **stack, int value);
t_stack		*new_node(int value);
void		assign_index(t_stack *stack);

//*** linked list utils ***
t_stack		*find_last_node(t_stack *stack);
t_stack		*find_value_max(t_stack *stack);
t_stack		*find_value_min(t_stack *stack);
int			stack_len(t_stack *stack);
int			check_order(t_stack *stack);
void		set_price(t_stack *a, t_stack *b);
void		top_smaller_node(t_stack **stack_a);
t_stack		*find_cheapest_node(t_stack *stack_b);
//t_stack		*find_median(t_stack *stack);
void		handle_mix(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
void		handle_neg(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
void		handle_pos(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);

//***PUSH_SWAP_INIT****
void		set_target_node(t_stack *stack_a, t_stack *stack_b);
void		move_elements_to_b(t_stack **stack_a, t_stack **stack_b);

//***TESTING****
//void		print_parsed_args(int *parsed_args, int argc);
void		print_parsed_args(char *parsed_args, int argc);
void		print_stack(t_stack *stack);
void		print_stacks(t_stack *stack_a, t_stack *stack_b);
void		print_push_costs(t_stack *stack);
void		print_stacks_x(t_stack *stack_a, t_stack *stack_b);

//*** Algorithms ***
void		tiny_sort(t_stack **stack_a);
void		sort_stacks(t_stack **stack_a, t_stack **stack_b);

//*** Commands ***
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);

//*** Additional Commands ***
void		reverse_rotate(t_stack **stack);
void		rotate(t_stack **stack);
void		swap(t_stack **head);
void		push(t_stack **dest, t_stack **src);

#endif

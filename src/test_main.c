/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:51:15 by anamedin          #+#    #+#             */
/*   Updated: 2024/07/25 16:23:59 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    int n_nodes;
    int *parsed_args;
    int i;

    if (argc < 2)
        exit(1);

    i = 1;
    parsed_args = parse_args(argc, argv);
    if (!parsed_args)
        free_error(stack_a, stack_b);

    //stack_a = create_stack_from_args(parsed_args, argc - 1);
    stack_a = create_stack_from_args(parsed_args, argc);
    free(parsed_args);

    if (!stack_a)
        exit(1);

    if (check_order(stack_a))
    {
        free_stack(&stack_a);
        exit(0);
    }

    n_nodes = stack_len(stack_a);
    printf("Cantidad de nodos en  A %d:, ", n_nodes);

    if (n_nodes == 2)
        sa(&stack_a);
    else if (n_nodes == 3)
        tiny_sort(&stack_a);
    else
    {
        move_elements_to_b(&stack_a, &stack_b);
        printf("Después de mover elementos a B:\n");
        print_stacks(stack_a, stack_b);

        // Establecer los nodos objetivo para los nodos en stack_b
        set_target_node(stack_a, stack_b);
        printf("Después de asignar nodos objetivo:\n");
        print_stacks(stack_a, stack_b);

        // Asignar la posición actual y el nodo objetivo
        set_current_position(stack_a);
        set_current_position(stack_b);
        set_target_node(stack_a, stack_b);
        set_price(stack_a, stack_b);

        // Imprimir el costo de push de cada nodo en stack_b
        printf("Costo de push de cada nodo en stack_b:\n");
        print_push_costs(stack_b);


        // Asegúrate de que la pila A tenga solo 3 elementos
        tiny_sort(&stack_a);
        printf("Después de tiny_sort en A:\n");
        print_stacks(stack_a, stack_b);

        // Implementar la función push_swap para ordenar ambas pilas
        push_swap(&stack_a, &stack_b);
        printf("Después de push_swap:\n");
        print_stacks(stack_a, stack_b);

        move_cheapest_to_a(&stack_a, &stack_b);
        printf("Después de mover el nodo más barato a A:\n");
        print_stacks(stack_a, stack_b);
    }

    // Liberar memoria
    free_stack(&stack_a);
    free_stack(&stack_b);
    return(0);
}*/

      /*  // Asignar la posición actual y el nodo objetivo
        set_current_position(stack_a);
        set_current_position(stack_b);
        set_target_node(stack_a, stack_b);
        set_price(stack_a, stack_b);

        // Imprimir el costo de push de cada nodo en stack_b
        printf("Costo de push de cada nodo en stack_b:\n");
        print_push_costs(stack_b);*/


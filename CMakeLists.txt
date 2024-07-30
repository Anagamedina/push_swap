cmake_minimum_required(VERSION 3.28)
project(push_swap_clion C)

set(CMAKE_C_STANDARD 11)

add_executable(push_swap_clion
        ../push_swap_clion/includes/push_swap.h
        ../push_swap_clion/src/error.c
        ../push_swap_clion/src/libft.c
        ../push_swap_clion/src/push.c
        src/main.c
        ../push_swap_clion/src/push_swap_utils.c
        ../push_swap_clion/src/reverse.c
        ../push_swap_clion/src/rotate.c
        ../push_swap_clion/src/sort.c
        ../push_swap_clion/src/test_stack.c
        ../push_swap_clion/src/test_main.c
        ../push_swap_clion/src/validate.c
        ../push_swap_clion/src/swap.c
        ../push_swap_clion/src/test_args.c
        ../push_swap_clion/src/stack_init.c
        ../push_swap_clion/src/stack_utils.c
        ../push_swap_clion/src/sort_stacks.c
)

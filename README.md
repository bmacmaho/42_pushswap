# 42_pushswap
> The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted.

## Introduction
Pushswap is a sorting algorithm project in the curriculum of the 42 programming school. The objective of the project is to sort an array of integers using two stacks (stack **a** and stack **b**), with a limited set of operations. 

The project is designed to teach students about data structures, algorithms, and computational complexity. It requires careful planning and attention to detail to achieve an optimal solution. The project also emphasizes code quality and efficiency, as the algorithm must be able to handle large arrays of integers efficiently.

The operations are as followed...

| Operation | Description |
| --- | --- |
| sa (swap a): | Swap the first 2 elements at the top of stack a. |
| sb (swap b): | Swap the first 2 elements at the top of stack b. |
| ss: | sa and sb at the same time. |
| pa (push a): | Take the first element at the top of b and put it at the top of a. |
| pb (push b): | Take the first element at the top of a and put it at the top of b. |
| ra (rotate a): | Shift up all elements of stack a by 1. The first element becomes the last one. |
| rb (rotate b): | Shift up all elements of stack b by 1. The first element becomes the last one. |
| rr : | ra and rb at the same time. |
| rra (reverse rotate a): | Shift down all elements of stack a by 1. The last element becomes the first one. |
| rrb (reverse rotate b): | Shift down all elements of stack b by 1. The last element becomes the first one. |
| rrr : | rra and rrb at the same time. |

## Approach
### Input Error Handling
### Preparing Stacks
### The 'diff' variable
### A → B
### A ← B

The goal is not to have the algorithm with the best time or space complexity, but instead to write the algorithm that uses *the least operations*.

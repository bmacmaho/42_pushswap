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
Before we can get stuck in with the sorting algorithms, it is first necessary to insure that the program is receiving valid inputs.
For example,
- Inputs must be numeric.
- Inputs cannot be repeated.
- Inputs must be within the range of an int.

To check if each value is in the range of an int, I made use of the 'ft_strncmp' function from libft.

### Preparing Stacks
### The 'diff' variable
The **diff** represents how far a number is to the middle of the sorted array. If it's positive, it's between the middle and the end. If it's negative, it's between the start and middle.

Take this for example,
| Values: | 1 | 2 | 3 | 4 | 5 |
| --- | --- | --- | --- | --- | --- |
| Diff: | -4 | -2 | 0 | 2 | 4 |

In this example, <br>
- 1's diff is -4, as it is less than 4 other items in the stack. <br>
- 2's diff is -2, because it is greater than one item (1) but less than three items (3, 4 & 5), ie, -1 + 3 = -2.<br>
- 3's diff is 0, because it has the same amount of values greater than it as it does less than.

### A → B
### A ← B

The goal is not to have the algorithm with the best time or space complexity, but instead to write the algorithm that uses *the least operations*.

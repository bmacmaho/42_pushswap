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
Next, we need to take these inputs and store them in some sort of data structure. For this implementation, I decided to represent the two stacks using doubly-linked lists. Each node in the list contains the inputed int, and it's corresponding **diff** which is explained in the next section.

There is also the t_pushswap struct 'pushswap' which contains pointers to the heads of these lists, pointers to the ends, and some other variables that are used frequently in the rest of the project. I find that having one some-what global struct declared in the main really cleans up the code. It makes it easier to follow the flow of the project, as I don't have to pass loads of arguments to every function, just 'pushswap'. Then I can deal with it's contained variables within each function.

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
'n' is a variable that decides the size of each chunk sent to b. If the amount of inputs is less than 150, n = 8. If greater, n = 18. I should really have a function that determines the optimal 'n' depending on the amount of inputs instead of hard-coding them, but for now these work well.

curdiff is the ceiling 'diff' as we move values from A → B. Its initial value is n * 2. If the absolute value of an input's diff is less than 'curdiff' then we push it to B. If A no longer contains a value that fits in the chunk, we increase 'curdiff'.Then if the diff is negative, we rotate B. As seen in the video below, this means that we get the middle values into B first, and in an approximate order, get the values further from the centre.

[Screencast from 02-16-2023 01 02 36 AM (online-video-cutter.com)(2).webm](https://user-images.githubusercontent.com/118922473/219409373-f24d9691-d2ff-4c5d-a4dc-b02f3b3a8a5b.webm)

### A ← B

The goal is not to have the algorithm with the best time or space complexity, but instead to write the algorithm that uses *the least operations*.

*This project has been created as part of the 42 curriculum by yelallam.*

## Description

Push_swap is a sorting algorithm project that challenges you to sort data on a stack using a limited set of operations, with the goal of achieving the lowest possible number of actions. The program receives a list of integers and outputs a sequence of stack manipulation instructions that will sort them in ascending order.

The project consists of two main components:
- **push_swap**: Calculates and displays the optimal sequence of operations to sort a stack of integers
- **checker** (bonus): Validates whether a given sequence of operations correctly sorts the stack

This project explores algorithm complexity, optimization strategies, and the implementation of efficient sorting methods using constrained operations.

## Stack Operations

The following operations are available to manipulate two stacks (a and b):

- `sa` / `sb` / `ss`: Swap the first two elements at the top of stack a / b / both
- `pa` / `pb`: Push the top element from one stack to another
- `ra` / `rb` / `rr`: Rotate stack (first element becomes last)
- `rra` / `rrb` / `rrr`: Reverse rotate stack (last element becomes first)

## Algorithm Overview

The implementation uses a **chunk-based sorting algorithm** with the following phases:

### Phase 1: Indexing
Convert actual values to ranks (0 = smallest, n-1 = largest) to simplify chunk calculations.

### Phase 2: Push to Stack B (Chunks)
- Divide numbers into chunks based on stack size:
  - **100 numbers**: 5 chunks of ~20 each
  - **500 numbers**: 11 chunks of ~45 each
- For each chunk, find the closest element to the top and rotate it efficiently
- Push smaller-ranked numbers deeper into stack B using `rb`

### Phase 3: Push Back to Stack A
- Always push the largest remaining number from B back to A
- Rotate B efficiently to bring the maximum to the top
- Repeat until B is empty

### Phase 4: Small Stack Optimizations
- **2 numbers**: Single swap if needed
- **3 numbers**: Optimized with at most 2 operations
- **5 numbers**: Push 2 smallest to B, sort remaining 3, push back

## Performance Benchmarks

The algorithm achieves the following operation counts:

| Stack Size | Operations | Benchmark Requirement |
|------------|------------|----------------------|
| 3 numbers  | 0-2        | Varies by input      |
| 5 numbers  | 0-12       | No strict limit      |
| 100 numbers| ~600-700   | <700 (max), <1100 (passing) |
| 500 numbers| ~4500-5500 | <5500 (max), <8500 (passing) |

## Instructions

### Compilation
```bash
make        # Compile push_swap
make bonus  # Compile checker (bonus)
make clean  # Remove object files
make fclean # Remove object files and executables
make re     # Recompile everything
```

### Usage

**Basic usage:**
```bash
./push_swap 3 2 1 5 4
```

**With a single string argument:**
```bash
./push_swap "3 2 1 5 4"
```

**Testing with checker:**
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

**Counting operations:**
```bash
./push_swap 3 2 1 5 4 | wc -l
```

**Testing with random numbers:**
```bash
# Generate 100 random numbers and test
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | wc -l

# Verify correctness
./push_swap $ARG | ./checker $ARG
```

### Input Requirements

- Arguments must be integers within `INT_MIN` to `INT_MAX` range
- No duplicate values allowed
- Empty string arguments are treated as errors
- If already sorted or no arguments given, program outputs nothing

### Error Handling

The program displays `Error\n` to stderr for:
- Non-integer arguments
- Integer overflow/underflow
- Duplicate values
- Empty or invalid input

## Project Structure
```
push_swap/
├── Makefile
├── README.md
├── includes/
│   └── push_swap.h
├── srcs/
│   ├── main.c
│   ├── parsing/
│   │   ├── stack_init.c
│   │   └── validation.c
│   ├── operations/
│   │   ├── push.c
│   │   ├── swap.c
│   │   ├── rotate.c
│   │   └── reverse_rotate.c
│   ├── sorting/
│   │   ├── sort_small.c
│   │   ├── sort_five.c
│   │   ├── chunks.c
│   │   └── indexing.c
│   └── utils/
│       ├── stack_utils.c
│       └── helpers.c
└── bonus/
    └── checker.c
```

## Technical Choices

### Data Structure
```c
typedef struct s_stack
{
    int             data;        // Actual value
    int             index;       // Rank (0 = smallest)
    int             pos;         // Current position
    int             target_pos;  // Target position (unused in current implementation)
    struct s_stack  *next;       // Next node
}   t_stack;
```

### Key Design Decisions

1. **Linked List Implementation**: Allows O(1) push/pop operations at the head
2. **Index-Based Chunking**: Simplifies range checks and improves readability
3. **Greedy Chunk Selection**: Rotates closest element first to minimize operations
4. **Adaptive Chunk Sizing**: Different strategies for 100 vs 500 numbers
5. **Static Helper Functions**: Maintains Norminette compliance with <25 lines per function

## Resources

### Sorting Algorithms & Complexity
- [Big O Notation Explained](https://www.freecodecamp.org/news/big-o-notation-why-it-matters-and-why-it-doesnt-1674cfa8a23c/)
- [Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Turkish Algorithm (Push_swap Strategy)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

### C Programming & Linked Lists
- [Linked Lists in C](https://www.learn-c.org/en/Linked_lists)
- [Memory Management in C](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)

### 42 School Resources
- [42 Norm Guidelines](https://github.com/42School/norminette)
- Push_swap Subject (v10.0)

### AI Usage

AI (Claude by Anthropic) was used as a learning assistant throughout this project for the following purposes:

**Algorithm Design & Understanding:**
- Explaining the chunk-based sorting strategy and its optimization
- Helping understand time complexity analysis
- Clarifying the difference between various sorting approaches
- Guidance on adaptive chunk sizing for different input sizes

**Debugging & Code Review:**
- Identifying pointer-related bugs (pass-by-value vs pass-by-reference)
- Spotting infinite loops and segmentation faults
- Tracing through algorithm logic with concrete examples
- Understanding edge cases (NULL checks, boundary conditions)

**Code Quality & Norminette:**
- Refactoring functions to meet 25-line limit
- Ensuring parameter counts stay within 4-parameter limit
- Structuring code for better readability and maintainability
- Suggesting helper function decomposition

**Learning & Conceptual Clarity:**
- Understanding sentinel values (e.g., INT_MAX, -1)
- Learning about rotation cost calculations
- Clarifying linked list traversal patterns
- Explaining indexing/ranking concepts

**What AI Did NOT Do:**
- Generate complete functions from scratch without understanding
- Make design decisions without discussion
- Write code that wasn't thoroughly explained and understood
- Skip the debugging process or learning experience

All code was written iteratively with full understanding of each component. AI served as a teaching assistant, not a code generator, helping to identify bugs, explain concepts, and guide best practices while ensuring the learning process remained hands-on and comprehensive.

## Testing

### Manual Testing
```bash
# Test edge cases
./push_swap
./push_swap ""
./push_swap "1 2 3"           # Already sorted
./push_swap "3 2 1"           # Reverse sorted
./push_swap "2 one 3"         # Invalid input
./push_swap "1 1 2"           # Duplicates

# Test small stacks
./push_swap "2 1"
./push_swap "2 1 3"
./push_swap "1 5 2 4 3"

# Test medium stack
./push_swap $(seq 1 100 | shuf | tr '\n' ' ') | wc -l

# Test large stack
./push_swap $(seq 1 500 | shuf | tr '\n' ' ') | wc -l
```

### Automated Testing
```bash
# Test 100 numbers multiple times
for i in {1..10}; do
    ARG=$(seq 1 100 | shuf | tr '\n' ' ')
    echo "Test $i: $(./push_swap $ARG | wc -l) operations"
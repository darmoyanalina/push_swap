*This project has been created as part of the 42 curriculum by <adarmoya>, <neohanya>.*

# Description

The `push_swap` project is an algorithmic challenge where the goal is to sort a stack of integers using a limited set of operations and a secondary stack. This project serves as a concrete introduction to algorithmic complexity, requiring the implementation of multiple sorting strategies to handle varying degrees of data "disorder."

 - Stack $a$: Contains a random amount of negative and/or positive numbers without any duplicates at the start.
 - Stack $b$: Is initially empty.
 - Goal: Sort the numbers in stack $a$ in ascending order.

---

## Stack Operations

The following operations are allowed:

| Operation | Description |
|--------|-------------|
| sa | swap the first two elements of stack a |
| sb | swap the first two elements of stack b |
| ss | sa and sb at the same time |
| pa | push the top element from stack b to stack a |
| pb | push the top element from stack a to stack b |
| ra | Shift up all elements of stack a(first becomes last)|
| rb | Shift up all elements of stack b(first becomes last)|
| rr | ra and rb simultaneously |
| rra | Shift down all elements of stack a(last becomes first)|
| rrb | Shift down all elements of stack b(last becomes first)|
| rrr | rra and rrb simultaneously |

---

## Algorithms

This implementation includes **four different sorting strategies**, selected depending on the input characteristics.

### 1️⃣ Simple Algorithm — O(n²)

A basic sorting strategy used for small or nearly sorted inputs.

Example approaches:
- insertion-style sorting
- selection-style sorting
- simple minimum extraction

This approach is simple but inefficient for large inputs.

---

### 2️⃣ Medium Algorithm — O(n√n)

For medium complexity inputs, the program divides the dataset into **chunks**.

Steps:
1. Split numbers into √n chunks
2. Push chunk ranges into stack **b**
3. Reassemble them back into **a** in sorted order

This significantly reduces the number of operations compared to naive sorting.

---

### 3️⃣ Complex Algorithm — O(n log n)

For large or highly disordered inputs, a more efficient algorithm is required.

The most common solution is **Radix Sort adapted for stacks**.

Steps:
1. Normalize numbers into indexes
2. Sort using bitwise operations
3. Push and rotate elements between stacks

Radix sort performs well because it guarantees **O(n log n)** complexity in the push_swap operation model.

---

### 4️⃣ Adaptive Algorithm

The program computes a **disorder metric** before sorting and selects the most efficient algorithm.

Disorder is defined as the ratio of incorrectly ordered pairs.

## Instructions

---
### Compilation

To compile the project, run:

```bash
make
```

This will build the push_swap executable using the provided Makefile.

Available Makefile rules:
```bash
make        # compile the project
make clean  # remove object files
make fclean # remove object files and executable
make re     # recompile everything
```
---
### Running the Program

The program expects a list of integers as arguments representing stack a.
The first argument corresponds to the top of the stack.

Example:

```bash
./push_swap 2 1 3 6 5 8
```

The program will output a sequence of operations that sorts the numbers in ascending order.

Example output:
```bash
ra
pb
rra
pb
pb
pa
pa
```
Each operation is printed on a new line.

---
### Strategy Selection

You can force a specific sorting strategy using the following flags:
- --simple
- --medium
- --complex
- --adaptive

examples:
```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 3 1 2 5 4
./push_swap --complex 10 9 8 7 6
```

If no strategy flag is provided, the program automatically uses --adaptive
which selects the algorithm based on the input disorder.

---
### Benchmark Mode

Benchmark mode provides performance statistics after sorting.
```bash
./push_swap --bench 4 67 3 87 23
```
Benchmark output includes:
- disorder percentage
- selected strategy
- theoretical complexity
- total number of operations
- count of each operation type
Benchmark information is printed to stderr, while sorting operations remain on stdout.

---
### Using the Checker

You can verify the correctness of your operations using the checker program.
example
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

Expected output: `OK`
If the operations do not correctly sort the stack, the checker will output: `KO`

---
### Error Handling

The program prints: `Error`
- to stderr when:
- arguments are not integers
- numbers exceed the integer range
- duplicate values are present
- invalid input is provided

# Resources

The following resources were used during the development of this project to understand
C programming, algorithm design, and performance optimization.

### Programming

- **The C Programming Language** — Brian W. Kernighan & Dennis M. Ritchie
  Classic book that explains the foundations of C programming.

- **The GNU C Reference Manual**
  https://www.gnu.org/software/gnu-c-manual/

- **GNU Make Documentation**
  https://www.gnu.org/software/make/manual/make.html

---

### Algorithms and Complexity

- **Analysis of Algorithms — Wikipedia**
  https://en.wikipedia.org/wiki/Analysis_of_algorithms

- **Sorting Algorithm — Wikipedia**
  https://en.wikipedia.org/wiki/Sorting_algorithm

- **Radix Sort — Wikipedia**
  https://en.wikipedia.org/wiki/Radix_sort

- **Big-O Notation — Wikipedia**
  https://en.wikipedia.org/wiki/Big_O_notation

---

### Tutorials and Learning Resources

- https://makefiletutorial.com
- https://www.geeksforgeeks.org
- https://www.tutorialspoint.com

These websites were used to review concepts related to Makefiles, C programming,
and algorithm implementation.

---

### AI Usage

AI tools were used as a learning aid during this project for:

- explaining algorithmic complexity concepts
- helping structure project documentation
- reviewing README formatting
- providing debugging hints during development

All algorithms, implementation logic, and final code were written manually.

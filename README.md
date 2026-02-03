# push_swap

Sorting integers using two stacks (`a` and `b`) and a restricted set of stack operations.

Part of the 42 Berlin curriculum, this project focuses on algorithmic optimization, and data manipulation under constraints.

The implementation is based primarily on a binary radix sort strategy, combined with specialized handling for small inputs and optimized stack rotations to minimize the total number of operations.


---

## Table of Contents

- [Overview](#overview)
- [Allowed Operations](#allowed-operations)
- [Algorithm](#algorithm)
- [Usage](#usage)
- [Build](#build)
- [Examples](#examples)
- [Error Handling](#error-handling)
- [Notes](#notes)

---

## Overview

`push_swap` receives a list of unique integers and outputs the sequence of operations needed to sort them in ascending order.  
The goal is to generate the **fewest possible operations** while respecting project constraints.

A companion `checker` program (from a third-party) verifies whether a given sequence of operations sorts the stack correctly.

---

## Allowed Operations

The program is restricted to the following operations, each acting on two stacks: `a` and `b`.

### Swap

- `sa` — Swap the first two elements of stack `a`
- `sb` — Swap the first two elements of stack `b`
- `ss` — `sa` and `sb` at the same time

### Push

- `pa` — Push the top element from stack `b` to stack `a`
- `pb` — Push the top element from stack `a` to stack `b`

### Rotate

- `ra` — Rotate stack `a` upwards (first element becomes last)
- `rb` — Rotate stack `b` upwards
- `rr` — `ra` and `rb` at the same time

### Reverse Rotate

- `rra` — Rotate stack `a` downwards (last element becomes first)
- `rrb` — Rotate stack `b` downwards
- `rrr` — `rra` and `rrb` at the same time

Each operation is printed on a new line.  
The objective is to sort stack `a` using only these instructions.

The only permitted operations, each printed on a new line, are:

```
sa  sb  ss
pa  pb
ra  rb  rr
rra rrb rrr
```

---

## Algorithm

This implementation uses a hybrid strategy:

- Specialized handling for small inputs (≤ 3 / ≤ 5 elements)
- Chunk-based partitioning for medium and large inputs
- Optimized rotations (`ra` / `rra`, `rb` / `rrb`)
- Cost-based reinsertion from stack `b` into stack `a`
- Index-based normalization for efficient comparisons

The goal is to minimize the total number of operations while keeping the logic readable and maintainable.

---

## Usage

Run:

```bash
./push_swap <n1> <n2> <n3> ... <nN>
```

Example:

```bash
./push_swap 4 2 5 3 1
```

---

## Build

From the project root:

```bash
make
```

This produces:

- `push_swap` — instruction generator
- `checker` (if implemented)

Clean and rebuild:

```bash
make clean
make fclean
make re
```

---

## Examples

Small input:

```bash
./push_swap 3 1 2
```

Possible output:

```
sa
ra
```

Larger input:

```bash
./push_swap 42 17 99 8 23 56
```

Produces an optimized instruction sequence.

---

## Error Handling

Input is validated:

- Only integers accepted
- No duplicates
- 32-bit signed integer range

On error:

```
Error
```

is printed to `stderr`.

---

## Notes

- Emphasis on algorithmic optimization and efficiency
- Tested with common push_swap evaluators
- Designed for clarity and maintainability
- Serves as an algorithmic complement to system-level projects

---

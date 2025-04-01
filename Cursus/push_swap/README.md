# 🔢 Push_Swap
**Optimized Stack Sorting with Limited Operations**

## 📖 Overview
Push_Swap is an algorithmic project that sorts integers on a stack with a limited set of operations. The challenge is to find the **most efficient sequence of moves** to sort the stack in ascending order while adhering to strict performance benchmarks.

Key Concepts:
- **Stack manipulation** (two stacks: `a` and `b`)
- **Sorting algorithms** optimization
- **Complexity analysis** (minimizing operation counts)

## 🎯 Objectives
- Sort a stack of integers in ascending order (smallest at top)
- Use only 11 allowed operations (e.g., `sa`, `pb`, `rrr`)
- Achieve benchmark targets:
  - **≤ 700 ops** for 100 random numbers
  - **≤ 5500 ops** for 500 random numbers

## 🛠️ Features
### Core Program (`push_swap`)
- Parses input (integers or error handling)
- Implements sorting algorithm (e.g., **radix sort** or **chunk-based approach**)
- Outputs optimized instruction sequence

## 🚀 Usage
### Compilation

make        # Builds push_swap

### Sort numbers
./push_swap 3 2 1 0

# Validate with checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

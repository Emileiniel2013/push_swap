# push_swap

**push_swap** is an optimized sorting algorithm implemented in **C** that operates under strict constraints.  
The program sorts a list of integers using only a predefined set of stack operations and two stacks (`a` and `b`).

This project focuses on algorithm design, data structures, and performance optimization under limited instruction sets.

---

## ⚙️ Rules & Operations

You must sort all integers from the command-line arguments using **only** the following operations:

| Operation | Description |
|------------|-------------|
| `sa` | Swap the first 2 elements of stack **a** |
| `sb` | Swap the first 2 elements of stack **b** |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push the top element of **b** onto **a** |
| `pb` | Push the top element of **a** onto **b** |
| `ra` | Rotate stack **a** upwards (first → last) |
| `rb` | Rotate stack **b** upwards (first → last) |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack **a** (last → first) |
| `rrb` | Reverse rotate stack **b** (last → first) |
| `rrr` | Perform `rra` and `rrb` simultaneously |

No other operations are allowed.

---

## 🧠 Algorithm Overview

- Input numbers are stored in **stack a**, while **stack b** is initially empty.  
- The algorithm analyzes the current state and determines the **least number of moves** needed to position the next smallest element correctly.  
- It repeats this process until stack **a** is fully sorted.  
- Efficiency and operation count are key — the goal is to minimize the total number of moves.

My implementation uses two integer arrays for stack simulation and a rule-based strategy to select the most optimal operation sequence per element.

---

## 🧩 How to Run

### 1. Build the program
```bash
make
```
2. Run with arguments

```bash
./push_swap 4 67 3 87 23
```
3. (Optional) Check with a visualizer

You can test your output using community visualizers like [this one](https://github.com/o-reo/push_swap_visualizer).

📊 Example
```bash
$ ./push_swap 3 2 1
sa
rra
```
The output lists the operations required to sort the stack.

---
🔬 Technical Details

-Written in C (C99)

-No use of standard library sorting functions

-Algorithm optimized for time complexity and move count

-Includes input validation and error handling

---
🙌 Credits

Special thanks to A. Yigit Ogun for the excellent guide that inspired my approach:
[🔗 Push Swap – Algorithm Design Guide](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

# Push Swap Journey 

## Introduction
Push Swap is a fascinating problem-solving challenge where the goal is to sort a stack of integers with a minimal number of operations. This project allowed me to explore various sorting techniques, optimizing them for the unique operations allowed, such as rotations and swaps. Below is a brief overview of my development process and how my approach evolved.

---

## Approach Evolution

### 1. **Starting Simple: Bubble Sort Adaptation**
The journey began with a **basic bubble sort** algorithm. However, the original bubble sort was adapted to suit the unique constraints of the Push Swap problem. Instead of performing simple adjacent swaps, I had to factor in operations like:
- **Rotation (ra, rra)**
- **Swapping the first two elements (sa)**

This initial approach helped me visualize the basic operations and how they could be combined to gradually sort the stack.

---

### 2. **Step Up: The Mechanical Turk**
Once I became familiar with the movement operations and their interactions, I felt the need to refine the sorting process for efficiency. This led me to implement a version of **Mechanical Turk**. This method can be likened to **brute force**, but with a major twist:
- It incorporated better optimization based on the **cost of each operation**.
- Instead of blindly trying every possible move, I evaluated which operations would provide the most significant impact in each step, making it more efficient than the simple brute force approach.

Though not as optimal as more advanced algorithms, it was a step forward in reducing unnecessary operations.

---

### 3. **Final Touch: QuickSort with Optimization**
After experimenting with these earlier methods, I turned to the **QuickSort** algorithm, which divides the problem into smaller "chunks" based on a **pivot** element. In my case, the pivot was chosen to be the **median** of the stack. This method is known for its fast sorting performance in general and proved to be a great fit for Push Swap because:
- It efficiently splits the stack into subgroups of smaller and larger elements.
- The pivot approach allowed me to reduce the number of operations significantly while maintaining flexibility in terms of possible moves.

At this point, I felt that I had found the optimal strategy for sorting the stack in the fewest operations.

---

## Conclusion
From humble beginnings with a simple **bubble sort** to the more refined and efficient **QuickSort**, my approach to Push Swap evolved as I gained a better understanding of the allowed operations and how to optimize them. The key to success was not only understanding the problem but also continuously iterating to improve efficiency at every step. This project was a valuable learning experience, and I’m glad to have explored a range of techniques to reach the most efficient solution.

---

## Final Thoughts
The Push Swap challenge serves as a fantastic exercise in algorithm optimization. It pushed me to think critically about the best ways to utilize available operations and gave me deeper insight into sorting algorithms. I hope this README helps others understand the journey I took and the methods I employed.

Happy sorting! 🚀

# push_swap
Sorting algorithm that can only use a small list of operations given by the subject.

The subject requires to write an performant sorting algorithm, using two stacks: a - containting the numbers given in the comand line arguments, and b - wich at the beggining of the function is empty.

The list of give operations is :
-sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
-sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
-ss : sa and sb at the same time.
-pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
-pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
-ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
-rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
-rr : ra and rb at the same time.
-rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
-rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
-rrr : rra and rrb at the same time.

Every other operation on the stacks is forbidden.

My program is using two integer arrays for the operations, and the algorithm is basically looking at each number in the stack one by one looking for the best possible case where it uses the least ammount of moves possible.
After the base cast if found it applies the case and then pushed the number accordingly.
Please check out my code, and many thanks to A. Yigit Ogun, who wrote this amazing guide that helped me trough my push_swap journey : https://medium.com/@ayogun/push-swap-c1f5d2d41e97

Thanks!

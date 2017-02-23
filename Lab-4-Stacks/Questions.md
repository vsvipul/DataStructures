Practice Questions for Lab -4: Stack

Question 1: Write a program to implement a function f(S) defined on stacks of integers S which satisfies following properties:
                 f(∅) = 0                                                  i.e. for empty stack f(S) = 0
                 f(push(S,i)) = max(f(S),0)+ i               for stack S and integers i.
 
Input sequence to be pushed onto stack:
2, -3, 2, -1, 2
Value of f(S) after each pushed element:
2, -1, 2, 1, 3
 
Question 2: Create a data structure kStacks that represents k stacks. Implementation of kStacks should use only one array, i.e., k stacks should use the same array for storing elements. Following functions must be supported by kStacks.
                push(int x, int sn) –> pushes x to stack number ‘sn’ where sn is from 0 to k-1
                pop(int sn) –> pops an element from stack number ‘sn’ where sn is from 0 to k-1
Input: Let us create 3 stacks in an array of size 10
3                                              // k=3
push(15, 2);
push(45, 2);
push(17, 1);
push(49, 1);
push(39, 1);
push(11, 0);
push(9, 0);
push(7, 0);
pop(2)
pop(1)
pop(0)
 
Output:
Popped element from stack 2 is 45
Popped element from stack 1 is 39
Popped element from stack 0 is 7s
 
Question 3. Write a C program to implement a doubly ended queue.
 
Question 4. Consider a scenario where there are N processes to be completed. All the processes have a unique number assigned to them from 1 to N. Now, you are given two things:
The ideal order in which all the processes should have been executed.
The calling order in which all the processes are called.
For example, let's say that there are 3 processes. The ideal order is: 1 -> 3 -> 2. However, the calling order of the processes is: 3 -> 2 -> 1. Since the ideal order has process #1 to be executed firstly, the calling ordered is changed, i.e., the first element has to be pushed to the last place. Changing the position of the element takes 1 unit of time. Now, the new calling order is: 2 - 1. Since the ideal order has process #1 to be executed firstly, the calling ordered has to be changed again, i.e., the first element has to be pushed to the last place. The new calling order is thus: 1 - 3 - 2. Since the first element of the calling order is now same as the ideal order, that process will be executed and it will be popped out which also takes 1 unit of time. In this way all processes are changed according to ideal order and executed. Executing a process and changing the position takes 1 unit of time. Objective is to compute total time in executing all the input processes.
Input format:
The first line a number N, denoting the number of processes. The second line contains the calling order of the processes. The third line contains the ideal order of the processes.
Output format:
Print the total time taken for the entire queue of processes to be executed.
 
Sample Input:
3
3 2 1
1 3 2
Output:
5

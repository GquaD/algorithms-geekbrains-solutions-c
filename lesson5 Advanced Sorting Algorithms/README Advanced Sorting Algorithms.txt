Here I explain problems from homework task.

Task 1.
The first task was to implement advanced QuickSort algorithm.
Main algorithm is based on Hoare's sort principle.
Hoare's sort principle is following:
You select pivot element and move elements of an array so that array will be
divided into three parts: 
first - elements less than pivot
second - elements equal to pivot
third - elements bigger than pivot.

You repeat this division and moving elements recursively.

Additions to advance algorithm:
1. If at some level of recursion number of elements are less than or equal to 10,
then you should use Insertion sort.
2. If number of elements is more than 10, then you should find median of 
first, middle and last element. After that you swap found median with central
element of the array. Then you ought to use Hoare's sort.


Task 2.
The task was to sort ONLY EVEN numbers.
Odd numbers should stay on their positions.
This should have been done by using Bucket sort.
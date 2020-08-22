# C4E-Structured-Programming-Week3

WEEK 3 ASSIGNMENT:

Option 1 (General)
Use the linear linked list code to store a randomly generated set of 100 integers.  Now write a routine that will rearrange the list in sorted order of these values. Note you might want to use bubble sort to do this. Print these values in rows of 5 on the screen.

How will this work? Compare two adjacent list elements and if they are out of order swap them. After a first pass the largest element will have bubbled to the end of the list. Each pass can look at one less element as the end of a list stays sorted.

WEEK 3 HONORS ASSIGNMENT:

Modify the singly linked list to be a doubly linked list. Now write a routine that removes all duplicate data in the doubly linked list. The data will be integers generated at random from [0,49]. Initially have a list of 200 elements.

Now do this in one of two ways.  Sort the list by its data field. Remove adjacent elements of the sorted list with the same value. Or, take the first element—search the remainder of the list for elements with the same data and remove them. Then take the second element and do the same. Repeat until only one element is left.

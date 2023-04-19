## Addition of two polynomial using LinkedList as an intermediate data structure

### The algorithm for performing the Polynomial Addition using Linked List is given below:
1.	Create a new linked list, newHead to store the resultant list.
2.	Traverse both lists until one of them is null.
3.	If any list is null insert the remaining node of another list in the resultant list.
4.	Otherwise compare the degree of both nodes, a (first list’s node) and b (second list’s
node). Here three cases are possible:
5.	If the degree of a and b is equal, we insert a new node in the resultant list with the coefficient equal to the sum of coefficients of a and b and the same degree.
6.	If the degree of a is greater than b, we insert a new node in the resultant list with the coefficient and degree equal to that of a.
7.	If the degree of b is greater than a, we insert a new node in the resultant list with the coefficient and degree equal to that of b.

## Multiplication of two polynomials using Linked List as an intermediate data structure

### Algorithm for multiplication
1. Define a structure for a polynomial term with two fields: coefficient and exponent.
2. Create two linked lists, one for each polynomial.
3. Traverse the first linked list and for each term in the list, traverse the second linked list and multiply each term in the second list with the term in the first list. Add the resulting terms to a new linked list representing the product of the two polynomials.
4. Sort the resulting linked list by the exponent of each term in ascending order.
5. Combine any terms that have the same exponent by adding their coefficients.
6. Remove any terms with a coefficient of zero.
7. Return the resulting linked list as the product of the two polynomials.

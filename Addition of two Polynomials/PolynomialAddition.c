#include <stdio.h>
#include <stdlib.h>

// Define the structure of a term in a polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
} Term;

// Function to create a new term
Term *create_term(int coefficient, int exponent) {
    Term *term = (Term *) malloc(sizeof(Term));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

// Function to add two polynomials
Term *add_polynomials(Term *poly1, Term *poly2) {
    Term *result = NULL, *temp, *prev;

    // Traverse both linked lists and add the terms
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            temp = create_term(poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly2->exponent > poly1->exponent) {
            temp = create_term(poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            temp = create_term(poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        // Add the new term to the result
        if (result == NULL) {
            result = temp;
            prev = temp;
        } else {
            prev->next = temp;
            prev = temp;
        }
    }

    // Add any remaining terms from poly1
    while (poly1 != NULL) {
        temp = create_term(poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
        prev->next = temp;
        prev = temp;
    }

    // Add any remaining terms from poly2
    while (poly2 != NULL) {
        temp = create_term(poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
        prev->next = temp;
        prev = temp;
    }

    return result;
}

// Function to print a polynomial
void print_polynomial(Term *poly) {
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    // Create polynomial 1: 2x^3 + 3x^2 + 1x^0
    Term *poly1 = create_term(2, 3);
    poly1->next = create_term(3, 2);
    poly1->next->next = create_term(1, 0);

    // Create polynomial 2: 1x^3 + 2x^2 + 4x^1
    Term *poly2 = create_term(1, 3);
    poly2->next = create_term(2, 2);
    poly2->next->next = create_term(4, 1);

    // Add the two polynomials
    Term *result = add_polynomials(poly1, poly2);

    // Print the result
    printf("Polynomial 1: ");
    print_polynomial(poly1);
    printf("Polynomial 2: ");
    print_polynomial(poly2);
    printf("Resultant: ");
    print_polynomial(result);

    return 0;
}

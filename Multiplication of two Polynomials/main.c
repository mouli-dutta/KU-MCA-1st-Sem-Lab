#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

// Function to create a new node
Node* newNode(int coefficient, int exponent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->coefficient = coefficient;
    node->exponent = exponent;
    node->next = NULL;
    return node;
}

// Function to insert a node at the end of a linked list
void insertEnd(Node** head, int coefficient, int exponent) {
    Node* node = newNode(coefficient, exponent);
    if (*head == NULL) {
        *head = node;
    } else {
        Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

// Function to multiply two polynomials
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* ptr1 = poly1;
    while (ptr1 != NULL) {
        Node* ptr2 = poly2;
        while (ptr2 != NULL) {
            int coefficient = ptr1->coefficient * ptr2->coefficient;
            int exponent = ptr1->exponent + ptr2->exponent;
            Node* node = result;
            while (node != NULL && node->exponent > exponent) {
                node = node->next;
            }
            if (node == NULL) {
                insertEnd(&result, coefficient, exponent);
            } else if (node->exponent == exponent) {
                node->coefficient += coefficient;
            } else {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->coefficient = coefficient;
                newNode->exponent = exponent;
                newNode->next = node;
                if (node == result) {
                    result = newNode;
                } else {
                    Node* prev = result;
                    while (prev->next != node) {
                        prev = prev->next;
                    }
                    prev->next = newNode;
                }
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return result;
}

// Function to display a polynomial
void displayPolynomial(Node* poly) {
    Node* ptr = poly;
    while (ptr != NULL) {
        printf("%dx^%d", ptr->coefficient, ptr->exponent);
        ptr = ptr->next;
        if (ptr != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    // Create polynomial 1: 2x^3 + 3x^2 + 1x^0
    Node *poly1 = NULL;
    insertEnd(&poly1, 2, 3);
    insertEnd(&poly1, 3, 2);
    insertEnd(&poly1, 1, 0);

    // Create polynomial 2: 1x^3 + 2x^2 + 4x^1
    Node *poly2 = NULL;
    insertEnd(&poly2, 1, 3);
    insertEnd(&poly2, 2, 2);
    insertEnd(&poly2, 4, 0);

    // Multiply the two polynomials
    Node *result = multiplyPolynomials(poly1, poly2);

    // Print the result
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    printf("Resultant: ");
    displayPolynomial(result);

    return 0;
}

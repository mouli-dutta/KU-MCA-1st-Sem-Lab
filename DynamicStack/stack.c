#include "stack.h"

// checks if the stack is empty
int isEmpty(Stack* s) {
    return !s;
}

// returns the top element of the stack
int top(Stack* s) {
    return s->data;
}

// display the top element of the stack
void peek(Stack *s) {
    if(isEmpty(s)) {
        printf("The Stack is empty.\n");
        return;
    }

    printf("The top element is %d.\n", top(s));
}

// push an element on the top of the stack
void push(Stack **s, int data) {
    Stack* newStack = malloc(sizeof(Stack));

    if(!newStack) {
        printf("Can't allocate memory");
        return;
    }

    newStack->data = data;
    newStack->next = *s;
    *s = newStack;
}

// pop the last inserted element from the stack
void pop(Stack **s) {

    if(isEmpty(*s)) {
        printf("Can not pop an empty stack.\n");

    } else {
        Stack *temp = *s;
        *s = (*s)->next;

        printf("%d poped.\n", temp->data);
        free(temp);
    }
}

int search_helper(Stack* s, int data) {
    if(isEmpty(s)) return 0;

    if(s->data == data) return 1;

    return search_helper(s->next, data);

}

void search_stack(Stack* s, int data) {
    if(search_helper(s, data))
        printf("%d is found.\n", data);
    else
        printf("%d is not found.\n", data);
}

void display(Stack* s) {
    if(isEmpty(s))
        printf("The Stack is empty.\n");

    else {
        printf("The elements of the stack are:\n");

        while(!isEmpty(s)) {
            printf("%d ", top(s));
            s = s->next;
        }
        printf("\n");
    }
}


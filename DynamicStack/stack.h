#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack *next;
} Stack;

int isEmpty(Stack*);
void push(Stack**, int);
void pop(Stack**);
void peek(Stack*);
void search_stack(Stack*, int);
void display(Stack*);

#endif // STACK_H_INCLUDED

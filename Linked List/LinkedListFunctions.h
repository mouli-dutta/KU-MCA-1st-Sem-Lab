#ifndef LINKEDLISTFUNCTIONS_H_INCLUDED
#define LINKEDLISTFUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *next;
} NodePtr;

// prototypes for the functions of LinkedList

// creates a new node
NodePtr* new_node(int);

// returns the length of the list
int get_length(NodePtr*);

// insert node at the front
void insert_begin(NodePtr**, int);

// insert node at the end of the list
void insert_end(NodePtr**, int);

// insert node at given index
void insert_at(NodePtr**, int, int);

// delete the first node
void delete_first(NodePtr**);

// delete the last node
void delete_last(NodePtr**);

// delete node at given index
void delete_at(NodePtr**, int);

// returns the value at given index otherwise -1
int get(NodePtr*, int);

void set(NodePtr**, int, int);

// function to find the minimum element in the linked list 
int getMin(NodePtr*);

// function to find the maximum element in the linked list 
int getMax(NodePtr*);

// creates a linked list taking user input
NodePtr* createList();

// function to concatanate two SLLs
NodePtr* concat(NodePtr*, NodePtr*);

// function to reverse SLL
void reverse(NodePtr **);

// search an element in list
bool search_list(NodePtr*, int);

// sort the list using Merge sort algorithm
void merge_sort(NodePtr**);

// display the list
void display(NodePtr*);


#endif // LINKEDLISTFUNCTIONS_H_INCLUDED

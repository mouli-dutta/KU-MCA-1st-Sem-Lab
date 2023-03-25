#include "LinkedListFunctions.h"

// Given int data creates a new node of the list.
NodePtr* new_node(int data) {
    NodePtr *node = (NodePtr*) malloc(sizeof(NodePtr));
    node->data = data;
    node->next = NULL;
    return node;
}

// Given a reference (pointer to pointer) to the head of the list
// and an int data, inserts a new node at the front of the list.
void insert_begin(NodePtr **head, int data) {

    // create a new node and make the new node as head
    NodePtr *new_head = new_node(data);
    new_head->next = *head;
    *head = new_head;

    printf("%d is inserted at first.\n", new_head->data);
}

// Given a reference (pointer to pointer) to the head of the list
// and an int data, inserts a new node at the rear of the list.
void insert_end(NodePtr **head, int data) {
    NodePtr *new_ = new_node(data);

    // if the head is null then its an empty list
    if(*head == NULL) {
        *head = new_;
        return;
    }

    // otherwise, find the last node and add the new node
    NodePtr *last_node = *head;

    // last node's address will be null
    while(last_node->next != NULL) {
        last_node = last_node->next;
    }

    // add the last node at the end of the list
    last_node->next = new_;

    printf("%d is inserted at last.\n", new_->data);
}

// Returns the length of the given list
int get_length(NodePtr *node) {
    int len = 0;

    while(node != NULL) {
        node = node->next;
        len++;
    }
    return len;
}

// Given a reference (pointer to pointer) to the head of the list,
// an int data and an index, inserts a new node at the given index.
void insert_at(NodePtr **head, int data, int index) {
    int length = get_length(*head);
    int tmp_index = index;

    // boundary conditions
    if(index < 0 || index > length) {
        printf("Can't insert at index %d.\n", index);
        return;
    }

    // inserting at the beginning of the list
    if(index == 0){
        insert_begin(head, data);
        return;
    }

    // otherwise
    NodePtr *nth_node = *head;

    // traverse till the node at given index
    while(--index)
        nth_node = nth_node->next;

    NodePtr *tmp = new_node(data);
    tmp->next = nth_node->next;
    nth_node->next = tmp;

    printf("%d is inserted at index %d.\n", tmp->data, tmp_index);

}

void delete_first(NodePtr **head) {
    // linked list does not exist or the list is empty
    if(head == NULL || *head == NULL) {
        printf("The Linked List does not exist or the list is empty.\n");
        return;
    }

    // otherwise
    NodePtr *tmp;

    // storing the head to a temporary variable
    tmp = *head;

    // moving head to the next node
    *head = (*head)->next;

    // deleting the first node
    printf("%d deleted.\n", tmp->data);
    free(tmp);
}


void delete_last(NodePtr **head) {
    // linked list does not exist or the list is empty
    if(head == NULL || *head == NULL) {
        printf("The Linked List does not exist or the list is empty.\n");
        return;
    }

    NodePtr *tmp = *head;
    NodePtr *previous;
    // if linked list has only one element
    if(tmp->next == NULL) {
        delete_first(head);
        return;
    }

    // otherwise
    // traverse to the last node
    while(tmp->next != NULL) {
        // store previous link node
        previous = tmp;
        tmp = tmp->next;
    }
    // assign 2nd last node's next to null
    previous->next = NULL;

    // delete last node
    printf("%d deleted.\n", tmp->data);
    free(tmp);

}

void delete_at(NodePtr **head, int index) {
    // linked list does not exist or the list is empty
    if(head == NULL || *head == NULL) {
        printf("The Linked List does not exist or the list is empty.\n");
        return;
    }

    // invalid index check
    int length = get_length(*head);
    if(index < 0 || index > length) {
        printf("Can't delete at index %d.\n", index);
        return;
    }

    if(index == 0) {
        delete_first(head);
        return;
    }

    // otherwise

    // previous node of the node to be deleted
    NodePtr *previous = *head;
    for(int i = 0; i < index-1; i++)
        if(previous->next)
            previous = previous->next;

    // node to be deleted
    NodePtr *del = previous->next;

    previous->next = previous->next->next;

    printf("%d deleted.\n", del->data);

    // unlink node from memory
    // free memory
    del->next = NULL;
    free(del);

}

// Given the head of the linked list and an index
// gets the value of the node in that index
// and if not found returns -1
int get(NodePtr *head, int index) {
    int len = get_length(head);

    if(index < 0 || index > len || head == NULL) {
        printf("Invalid index\n");
        return -1;
    }

    if(index == 0)
        return head->data;

    return get(head->next, index-1);
}

// Given a reference (pointer to pointer) to the head of the list,
// modifies the current value in that node to a given value.
void set(NodePtr **head, int index, int value) {
    int len = get_length(*head);

    if(index < 0 || index >= len || head == NULL || *head == NULL) {
        printf("Can't modify the data of a node at invalid index.\n");
        return;
    }

    NodePtr *current = *head;

    for(int i = 0; i < index; i++)
        if(current->next)
            current = current->next;

    current->data = value;

    printf("Updated with new value.\n");
}

// function to find the minimum element in the linked list 
int getMin(NodePtr *head) {
    int min = INT_MAX; 
    while(head) {
        if(head->data < min) { 
            min = head->data;
        }
        head = head->next;
    }
    return min;
}

// function to find the maximum element in the linked list 
int getMax(NodePtr *head) {
    int max = INT_MIN; 
    while(head) {
        if(head->data > max) { 
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

// creates a linked list taking user input
NodePtr* createList() {
    NodePtr *head = NULL;
    printf("Do you want to insert a node?\nEnter Y for yes and N for No.\n");
    while(1) {
        char ch;
        scanf("%c", &ch);
        if(ch == 'Y' || ch == 'y') {
            printf("Enter the data of the node.\n");
            int data;
            scanf("%d", &data);
            insert_begin(&head, data);
            continue;
        }
        if(ch == 'N' || ch == 'n') break;
        printf("Do you want to insert a node?\nEnter Y for yes and N for No.\n");
    }
    return head;
}

// function to concatanate two SLLs
NodePtr* concat(NodePtr *head1, NodePtr *head2) {
    if(!head1 && !head2) {
        printf("Both lists are empty.\n");
        return NULL;
    }
    
    else if(!head1) return head2;
    else if(!head2) return head1;
    
    else {
        NodePtr *tmp = head1;
        while(tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head2;
    return head1;
    }
}

// function to reverse SLL
void reverse(NodePtr **head) {
    if(!head || !(*head)) {
        printf("The tree is empty.\n");
        return;
    }
    
    NodePtr *curr = *head;
    NodePtr *prev = NULL, *next = NULL;
    
    while(curr) {
        next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Looks for the data in a list
bool search_list(NodePtr *head, int data) {
    // base case
    if(head == NULL)
        return false;

    // check if data is found in current node
    if(head->data == data)
        return true;

    // recur for the remaining list
    return search_list(head->next, data);
}

// takes two sorted list in increasing order and
// merge them in a single sorted list, which is returned
NodePtr* sortedMerge(NodePtr *a, NodePtr *b) {
    // base case
    if(a == NULL) return b;
    else if(b == NULL) return a;

    NodePtr *result = NULL;

    if(a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);

    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

/*
    split the given list's nodes into front and back halves
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go to the front list.
    It uses the fast/slow pointer strategy
*/
void front_back_split(NodePtr *source, NodePtr **frontRef, NodePtr **backRef) {
    // if the length is less than 2
    if(source == NULL || source->next == NULL) {
        *frontRef = source;
        *backRef = NULL;
        return;
    }

    NodePtr *slow = source;
    NodePtr *fast = source->next;

    // advance `fast` by 2 nodes and `slow` by 1 node
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // `slow` is before midpoint in the list
    // so split it in two at this point
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// sort given linked list using the Merge Sort algorithm
void merge_sort(NodePtr **head) {
    // base case: length 0 or 1
    if(*head == NULL || (*head)->next == NULL) return;

    NodePtr *a;
    NodePtr *b;

    // split head into a and b sublist
    front_back_split(*head, &a, &b);

    // recursively sort the sublists
    merge_sort(&a);
    merge_sort(&b);

    // merge the two sorted list
    *head = sortedMerge(a, b);
}


void display(NodePtr *node) {
    do {
        printf("%d -> ", node->data);
    } while ((node = node->next) != NULL);
    printf("NULL\n");
}



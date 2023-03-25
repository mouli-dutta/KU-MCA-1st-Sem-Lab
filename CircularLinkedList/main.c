#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
void insertStart (struct Node **head, int data) {
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;

  // if its the first node being entered
  if (*head == NULL) {
      *head = newNode;
      (*head)->next = *head;
      return;
  }

  // if LL already as >=1 node
  struct Node *curr = *head;

  // traverse till last node in LL
  while (curr->next != *head) {
      curr = curr->next;
  }
  // assign LL's last node's next as this new node
  curr->next = newNode;

  // assign newNode's next as current head
  newNode->next = *head;

  // change head to this new node
  *head = newNode;
}

void insertLast (struct Node **head, int data) {
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;

  // if its the first node being entered
  if (*head == NULL) {
      *head = newNode;
      (*head)->next = *head;
      return;
  }

  // if LL already as >=1 node
  struct Node *curr = *head;

  // traverse till last node in LL
  while (curr->next != *head) {
      curr = curr->next;
  }

  // assign LL's current last node's next as this new node
  curr->next = newNode;

  // assign this new node's next as current head of LL
  newNode->next = *head;
}

int getCurrSize (struct Node *node) {
  int size = 0;

  while (node != NULL){
      node = node->next;
      size++;
  }
  return size;
}
//function to insert element at specific position
void insertPosition (struct Node **head, int data, int pos) {
  struct Node *newnode, *curNode;
  int i;

  if (*head == NULL) {
      printf ("List is empty");
  }
  if (pos == 1) {
      insertStart (head, data);
      return;
  }
  else {
      newnode = (struct Node *) malloc (sizeof (struct Node));
      newnode->data = data;
      curNode = *head;
      while (--pos > 1){
	    curNode = curNode->next;
	  }
      newnode->next = curNode->next;
      curNode->next = newnode;
  }
}

void deleteBegin (struct Node **head)
{

  struct Node *tempNode = *head;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete");
      return;
    }

  // if only 1 node in CLL
  if (tempNode->next == *head)
    {
      *head = NULL;
      return;
    }

  struct Node *curr = *head;

  // traverse till last node in CLL
  while (curr->next != *head)
    curr = curr->next;

  // assign last node's next to 2nd node in CLL
  curr->next = (*head)->next;

  // move head to next node
  *head = (*head)->next;
  free (tempNode);
}

void deleteEnd (struct Node **head)
{
  struct Node *tempNode = *head;
  struct Node *previous;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete");
      return;
    }

  // if Linked List has only 1 node
  if (tempNode->next == *head)
    {
      *head = NULL;
      return;
    }

  // else traverse to the last node
  while (tempNode->next != *head)
    {
      // store previous link node as we need to change its next val
      previous = tempNode;
      tempNode = tempNode->next;
    }
  // Curr assign 2nd last node's next to head
  previous->next = *head;
  // delete the last node
  free (tempNode);
  // 2nd last now becomes the last node
}

void deletePos (struct Node **head, int n)
{

  int size = getCurrSize(*head);

  if (n < 1 || size < n)
    {
      printf ("Can't delete, %d is not a valid position\n", n);
    }
  else if (n == 1)
    deleteBegin (head);
  else if (n == size)
    deleteEnd (head);
  else
    {
      struct Node *tempNode = *head;
      struct Node *previous;	// traverse to the nth node
      while (--n)
	{ // store previous link node as we need to change its next val
	  previous = tempNode;
	  tempNode = tempNode->next;
	}

      // change previous node's next node to nth node's next node
      previous->next = tempNode->next;
      // delete this nth node
      free (tempNode);
    }
}

void display (struct Node *head) {
  // if there are no node in LL
  if (head == NULL)
    return;

  struct Node *temp = head;

  //need to take care of circular structure of LL
  do
    {
      printf ("%d ", temp->data);
      temp = temp->next;

    }
  while (temp != head);
  printf ("\n");
}

// helper function to take input from user
int take_input(char *s) {
    printf("%s\n", s);
    int data;
    scanf("%d", &data);
    return data;
}

int main()
{
    printf("\tMENU\n");
    printf("1. Insert node at first.\n");
    printf("2. Insert node at last.\n");
    printf("3. Insert node at given index.\n");
    printf("4. Delete first node.\n");
    printf("5. Delete last node.\n");
    printf("6. Delete node at given index.\n");
    printf("7. Display.\n");
    printf("8. Exit.\n");
    printf("------------------------------------\n\n");

    struct Node *head = NULL;

    while(1) {
        int choice = take_input("Enter a number between 1 to 8.");

        switch(choice) {
            case 1:
                insertStart(&head, take_input("Enter the data of the node."));
                break;

            case 2:
                insertLast(&head, take_input("Enter the data of the node."));
                break;

            case 3:
                insertPosition(&head, take_input("Enter the data of the node."), take_input("Enter the index."));
                break;

            case 4:
                deleteBegin(&head);
                break;

            case 5:
                deleteEnd(&head);
                break;

            case 6:
                deletePos(&head, take_input("Enter the index."));
                break;

            case 7:
                display(head);
                break;

            case 8:
                printf("Terminating...\n");
                exit(0);
                break;

            default:
                printf("Invalid input.\n");
                break;
        }
    }
    return 0;
}

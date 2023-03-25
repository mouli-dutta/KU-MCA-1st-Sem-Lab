#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

Node* createNode(int data) {
    // creating memory for newNode
    Node *newNode = (Node*) malloc (sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert_begin(Node **head, int data) {

  Node *newNode = createNode(data);

  // assigning newNode's next as the current head
  newNode->next = *head;


  // if list already had item(s)
  // We need to make current head previous node as this new node
  if (*head != NULL)
    (*head)->prev = newNode;

  // change head to this newNode
  *head = newNode;

}

void insert_end (Node **head, int data) {
  Node *newNode = createNode(data);

  //need this if there is no node present in linked list at all
  if (*head == NULL) {
      *head = newNode;
      newNode->prev = NULL;
      return;
  }

  Node *temp = *head;

  // traverse till the last node
  while (temp->next != NULL)
    temp = temp->next;

  // assign last node's next to this new Node
  temp->next = newNode;
  // assign this new Node's previous to last node(temp)
  newNode->prev = temp;
}

int calcSize (Node *node)
{
  int size = 0;

  while (node != NULL)
    {
      node = node->next;
      size++;
    }
  return size;
}

void insert_at_given_idx (Node **head, int data, int pos)
{
  int size = calcSize (*head);

  //If pos is 0 then should use insertStart method
  //If pos is less than 0 then can't enter at all
  //If pos is greater than size then bufferbound issue
  if (pos < 1 || size < pos)
    {
      printf ("Can't insert, %d is not a valid position\n", pos);
    }
  else
    {
      Node *temp = *head;
      Node *newNode = createNode(data);

      // traverse till pos
      while (--pos)
	{
	  temp = temp->next;
	}

      // assign prev/next of this new node
      newNode->next = temp->next;
      newNode->prev = temp;

      // change next of temp node
      temp->next = newNode;
    }
}

void deleteFirst (Node **head)
{
  Node *tempNode = *head;

  // if DLL is empty
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete\n");
      return;
    }

  // if Linked List has only 1 node
  if (tempNode->next == NULL)
    {
      printf ("%d deleted\n\n", tempNode->data);
      *head = NULL;
      return;
    }

  // move head to next node
  *head = (*head)->next;
  // assign head node's previous to NULL
  (*head)->prev = NULL;

  printf ("%d deleted\n\n", tempNode->data);
  free (tempNode);
}

void deleteLast (Node **head)
{
  Node *tempNode = *head;

  // if DLL is empty
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete\n\n");
      return;
    }

  // if Linked List has only 1 node
  if (tempNode->next == NULL)
    {
      printf ("%d deleted\n\n", tempNode->data);
      *head = NULL;
      return;
    }

  // else traverse to the last node
  while (tempNode->next != NULL)
    tempNode = tempNode->next;

  struct Node *secondLast = tempNode->prev;

  // Curr assign 2nd last node's next to Null
  secondLast->next = NULL;

  printf ("%d deleted\n\n", tempNode->data);
  free (tempNode);
}

void delete_at_given_idx (Node **head, int n)
{
  //if the head node itself needs to be deleted
  int len = getLength (*head);

  // not valid
  if (n < 1 || n > len)
    {
      printf ("Enter valid position\n");
      return;
    }

  // delete the first node
  if (n == 1)
    {
      deleteFirst (head);
      return;
    }

  if (n == len)
    {
      deleteLast (head);
      return;
    }

  struct Node *tempNode = *head;

  // traverse to the nth node
  while (--n)
    {
      tempNode = tempNode->next;
    }

  Node *previousNode = tempNode->prev;	// (n-1)th node
  Node *nextNode = tempNode->next;	// (n+1)th node

  // assigning (n-1)th node's next pointer to (n+1)th node
  previousNode->next = tempNode->next;

  // assigning (n+1)th node's previous pointer to (n-1)th node
  nextNode->prev = tempNode->prev;

  // deleting nth node
  printf ("%d deleted \n\n", tempNode->data);
  free (tempNode);
}

// required for deleteNthNode
int
getLength (Node *node)
{
  int len = 0;


  while (node != NULL)
    {
      node = node->next;
      len++;
    }

  return len;
}

void display (Node *node)
{
  Node *end;
  printf ("\nIn Forward Direction\n");
  while (node != NULL)
    {
      printf ("%d  ", node->data);
      end = node;
      node = node->next;
    }

  printf ("\n\nIn Backward direction \n");
  while (end != NULL)
    {
      printf ("%d  ", end->data);
      end = end->prev;
    }

    printf("\n");
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
    printf("1. Create List.\n");
    printf("2. Insert node at first.\n");
    printf("3. Insert node at last.\n");
    printf("4. Insert node at given index.\n");
    printf("5. Delete first node.\n");
    printf("6. Delete last node.\n");
    printf("7. Delete node at given index.\n");
    printf("8. Display.\n");
    printf("9. Exit.\n");
    printf("------------------------------------\n\n");

    Node *head = NULL;

    while(1) {
        int choice = take_input("Enter a number between 1 to 9.");

        switch(choice) {
            case 1:
                head = createNode(take_input("Enter the data of the node."));
                break;

            case 2:
                insert_begin(&head, take_input("Enter the data of the node."));
                break;

            case 3:
                insert_end(&head, take_input("Enter the data of the node."));
                break;

            case 4:
                insert_at_given_idx(&head, take_input("Enter the data of the node."), take_input("Enter the index."));
                break;

            case 5:
                deleteFirst(&head);
                break;

            case 6:
                deleteLast(&head);
                break;

            case 7:
                delete_at_given_idx(&head, take_input("Enter the index."));
                break;

            case 8:
                display(head);
                break;

            case 9:
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

#include<stdio.h>
#define SIZE 5

//Basic value initialization
int queue[SIZE], front = -1, rear = -1;

//Function created to handle enqueue
void enqueue(){
    if(rear == SIZE-1){
        printf("Can't enqueue as the queue is full\n");
    }
    else{
        //The first element condition
        if(front == -1){
            front = 0;
        }

        printf("Enter the data.\n");
        int item;
        scanf("%d", &item);

        rear = rear + 1;
        queue[rear] = item;
        printf("We have enqueued %d\n",item);
   }
}

//Function created to handle dequeue
void dequeue(){
    if(front == -1){
        printf("Can't dequeue as the queue is empty\n");
    }
    else{
        printf("We have dequeued : %d\n", queue[front]);
        front = front + 1;

        //Only happens when the last element was dequeued
        if(front > rear){
	        front = -1;
	        rear = -1;
        }
   }
}

//function to print the queue
void printQueue(){
    if(rear == -1)
        printf("\nUnable to display as queue is empty");
    else{
        int i;
        printf("\nThe elements in the queue are:\n");

        for(i = front; i <= rear; i++)
	        printf("%d\n",queue[i]);
   }
}

int main() {

    printf("\tMenu\n");
    printf("1. EnQueue.\n");
    printf("2. DeQueue.\n");
    printf("3. Display.\n");
    printf("4. Exit.\n");
    printf("---------------\n");

    while(1) {
        printf("Enter a number between 1-4.\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printQueue();
                break;
            case 4:
                printf("Terminating the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\nEnter a number between 1-4.\n");
                break;

        }
    }
    return 0;
}


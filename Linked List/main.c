#include "LinkedListFunctions.h"

#if !defined (ARRAY_LENGTH)
    #define ARRAY_LENGTH(arr) (sizeof(arr)/sizeof(arr[0]))
#endif


void print_menu(char **str, int length) {
    for(int i = 0; i < length; i++)
        printf("%s", *(str+i));
}

int take_input(char *s) {
    printf("%s", s);
    int data;
    scanf("%d", &data);
    return data;
}

int main() {

    char *menu_arr[] = { "\t\tMENU\n",
                         "\t1) Create new list.\n",
                         "\t2) Insert node at first.\n",
                         "\t3) Insert node at last.\n",
                         "\t4) Insert node at given index (index starts from 0).\n",
                         "\t5) Delete first node.\n",
                         "\t6) Delete last node.\n",
                         "\t7) Delete node at given index (index starts from 0).\n",
                         "\t8) Get the value of a node at given index.\n",
                         "\t9) Set the data of a node at given index.\n",
                         "\t10) Length.\n",
                         "\t11) Sort.\n",
                         "\t12) Search.\n",
                         "\t13) Display.\n",
                         "\t14) Find the minimum node of the SLL.\n",
                         "\t15) Find the maximum node of the SLL.\n",
                         "\t16) Create a List.\n",
                         "\t17) Reverse the list.\n",
                         "\t18) Concat/Merge two lists.\n",
                         "\t19) Exit.\n\n"
                      };

    int len = ARRAY_LENGTH(menu_arr);
    print_menu(menu_arr, len);


    NodePtr *head = NULL;

    while(true) {

        int choice = take_input("Enter your choice\n");

        switch(choice) {
            case 1:
                head = new_node(take_input("Enter the data value.\n"));
            break;

            case 2:
                insert_begin(&head, take_input("Enter the data value.\n"));
            break;

            case 3:
                insert_end(&head, take_input("Enter the data value.\n"));
            break;

            case 4:
                insert_at(&head, take_input("Enter the data value.\n"), take_input("Enter the index.\n"));
            break;

            case 5:
                delete_first(&head);
            break;

            case 6:
                delete_last(&head);
            break;

            case 7:
                delete_at(&head, take_input("Enter the index.\n"));
            break;

            case 8:
                printf("The value of the node is %d.\n", get(head, take_input("Enter the index.\n")));
            break;

            case 9:
                set(&head, take_input("Enter the index.\n"), take_input("Enter the new data.\n"));
            break;

            case 10:
                printf("The length of the Linked List is %d.\n", get_length(head));
            break;

            case 11:
                merge_sort(&head);
                printf("The list is sorted in increasing order.\n");
            break;

            case 12:
                search_list(head, take_input("Enter the data you want to search.\n")) ?
                printf("Found\n") : printf("Not Found\n");
            break;

            case 13:
                display(head);
            break;
                
            case 14:
                printf("Data of the minimum node is: %d\n", getMin(head));                
            break;
                
            case 15:
                printf("Data of the maximum node is: %d\n", getMax(head));
            break;
                
            case 16:
                head = createList();
            break;
                
            case 17:
                reverse(&head);
            break;
                
            case 18:
                head = concat(head, createList());
            break;              

            case 19:
                printf("Terminating the process.\n");
                exit(0);
            break;

            default :
                printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}

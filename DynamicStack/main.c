#include "stack.h"

#if !defined (ARRAY_LENGTH)
    #define ARRAY_LENGTH(arr) (sizeof(arr)/sizeof(arr[0]))
#endif


void print_menu(char **str, int length) {
    for(int i = 0; i < length; i++)
        printf("%s", *(str+i));
}

int take_input(char *s) {
    printf("%s\n", s);
    int data;
    scanf("%d", &data);
    return data;
}

int main()
{
    char *menu_arr[] = { "\t\tMENU\n",
                         "\t1) Push.\n",
                         "\t2) Pop.\n",
                         "\t3) Peek.\n",
                         "\t4) Search.\n",
                         "\t5) Display.\n",
                         "\t6) Exit.\n\n"
                      };

    int len = ARRAY_LENGTH(menu_arr);
    print_menu(menu_arr, len);

    Stack *s = NULL;

    while(1) {
        int choice = take_input("Enter your choice.");

        switch(choice) {
            case 1:
                push(&s, take_input("Enter the element you want to push."));
            break;

            case 2:
                pop(&s);
            break;

            case 3:
                peek(s);
            break;

            case 4:
               search_stack(s, take_input("Enter the element you want to search."));
            break;

            case 5:
                display(s);
            break;

            case 6:
                printf("Terminating the program...\n");
                exit(1);
            break;

        }
    }

    return 0;
}

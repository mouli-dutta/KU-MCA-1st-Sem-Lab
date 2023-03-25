#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} BTNode;

BTNode* newNode(int data) {
    BTNode *new_node = malloc(sizeof(BTNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

BTNode* insertNode(BTNode* root, int data) {
    if(!root) return newNode(data);

    if(data > root->data)
        root->right = insertNode(root->right, data);
    else if(data < root->data)
        root->left = insertNode(root->left, data);
    return root;
}

BTNode* findSuccessor(BTNode* node) {
    BTNode* current = node->right;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

BTNode* deleteNode(BTNode* root, int key) {
    if (!root) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);

    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findSuccessor(root);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int getMax(BTNode *root) {
    if(!root) return -1;

    while(root->right) {
        root = root->right;
    }
    return root->data;
}

int getMin(BTNode *root) {
    if(!root) return -1;
    while(root->left)
        root = root->left;
    return root->data;
}

int searchBST(BTNode *root, int target) {
    if(!root) return -1;
    if(root->data == target) return 1;
    else if(target < root->data)
        return searchBST(root->left, target);
    else return searchBST(root->right, target);
}

void searchResult(BTNode *root, int target) {
    searchBST(root, target) ?
        printf("%d is found.\n", target) : printf("%d is not found.\n", target);
}


void preorder(BTNode *root) {
    if(root) {
        printf("%d, ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(BTNode *root) {
    if(root) {
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}

void postorder(BTNode *root) {
    if(root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d, ", root->data);
    }
}

void display(BTNode *root, int level) {
    if(!root) return;

    for(int i = 0; i < level; i++) {
        printf("|_");
    }

    printf("%d \n", root->data);
    display(root->left, level+1);
    display(root->right, level+1);
}

int take_input(char *s) {
    printf("%s\n", s);
    int data;
    scanf("%d", &data);
    return data;
}

int main()
{
        printf("------- Binary Search Tree Menu ------\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Get Maximum Node Data");
        printf("\n5. Get Minimum Node data");
        printf("\n\n-- Traversals --");
        printf("\n6. Inorder ");
        printf("\n7. Post Order ");
        printf("\n8. Pre Oder ");
        printf("\n9. Display ");
        printf("\n10. Exit\n");

        BTNode *root = NULL;

        while(1) {
            int choice;
            printf("\nEnter a number between 1 to 10.\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    root = insertNode(root, take_input("Enter the data of the root."));
                    break;
                case 2:
                    deleteNode(root, take_input("Enter the node to be deleted."));
                    break;
                case 3:
                    searchResult(root, take_input("Enter the key you want to search."));
                    break;
                case 4:
                    printf("Maximum node data of the BST is %d.\n", getMax(root));
                    break;
                case 5:
                    printf("Minimum node data of the BST is %d.\n", getMin(root));
                    break;
                case 6:
                    printf("Inorder traversal of the BST is:\n");
                    inorder(root);
                    break;
                case 7:
                    printf("Postorder traversal of the BST is:\n");
                    postorder(root);
                    break;
                case 8:
                    printf("Preorder traversal of the BST is:\n");
                    preorder(root);
                    break;
                case 9:
                    display(root, 0);
                    break;
                case 10:
                    printf("Terminating...\n");
                    exit(0);
                    break;
            }
        }

    return 0;
}

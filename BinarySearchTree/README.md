## Implementation of basic opertions in Binary Search Tree
1. Insertion,
2. Traversal, 
3. Searching of a node, 
4. Deletion.

### Algorithm for Insertion of a node in BST:
1.	Start at the root of the tree.
2.	If the tree is empty, create a new node and make it the root.
3.	If the new node's value is less than the current node's value, go to the left subtree.
4.	If the new node's value is greater than the current node's value, go to the right subtree.
5.	Repeat steps 3-4 until you reach a null pointer.
6.	Create a new node with the given value and attach it to the null pointer.

### Algorithm for Traversing the BST:

There are three main ways to search a Binary Search Tree:
1. Inorder Traversal
2. PreOrder Traversal
3. PostOrder Traversal

#### Algorithm for Inorder traversal:
1.	Traverse the left subtree by recursively calling the inorder function on the left child.
2.	Visit the current node.
3.	Traverse the right subtree by recursively calling the inorder function on the right child.
#### Algorithm for PreOrder traversal:
1.	Visit the current node.
2.	Traverse the left subtree by recursively calling the preorder function on the left child.
3.	Traverse the right subtree by recursively calling the preorder function on the right child.
#### Algorithm for PostOrder traversal:
1.	Traverse the left subtree by recursively calling the postorder function on the left child.
2.	Traverse the right subtree by recursively calling the postorder function on the right child.
3.	Visit the current node.


### Algorithm for Searching a node in BST:
1.	Start at the root of the tree.
2.	If the root is NULL or the root's key matches the search key, return the root.
3.	If the search key is less than the root's key, recursively search the left subtree of the root.
4.	If the search key is greater than the root's key, recursively search the right subtree of the root.
5.	Repeat steps 2-4 until the node is found or the search reaches a NULL node.

### Algorithm for deleting a node in BST:
1.	Start at the root of the tree.
2.	Search for the node to be deleted. If the node is not in the tree, exit the function.
3.	If the node to be deleted is a leaf node, simply delete it by setting its parent's corresponding child pointer to NULL and free the memory allocated for the node.
4.	If the node to be deleted has only one child, replace the node with its child by updating its parent's corresponding child pointer to point to the child and free the memory allocated for the node.
5.	If the node to be deleted has two children, find the node with the next largest value (the successor) in the right subtree of the node to be deleted. Replace the node to be deleted with the successor and then delete the successor using one of the above two methods (as it will have at most one child).
6.	Repeat steps 2-5 until the node is deleted.

## Implementing basic opertions in a Doubly Linked List 
1. Insertion
2. Traversal
3. Deletion


### Algorithm for Traversal
Step 1: IF HEAD == NULL <br/>
&nbsp;&nbsp;&nbsp;&nbsp;WRITE "UNDERFLOW" GOTO STEP 6 <br/>
&nbsp;&nbsp;&nbsp;&nbsp;[END OF IF] <br/>
Step 2: Set PTR = HEAD <br/>
Step 3: Repeat step 4 and 5 while PTR != NULL <br/>
Step 4: Write PTR → data  <br/>
Step 5: PTR = PTR → next  <br/>
Step 6: Exit <br/>

### Algorithm for Insertion of a node
1.	The new node is inserted at the beginning.
2.	The new node is inserted at the end.
3.	The new node is inserted after a given node.

#### 1.	Algorithm for insertion at beginning.	

Step 1 : IF POINTER = NULL <br/>
Step 2 : ASSIGN NEW NODE = POINTER <br/>
Step 3 : ASSIGN POINTER = POINTER -> NEXT  <br/>
Step 4 : ASSIGN NEW NODE -> DATA = VALUE  <br/>
Step 5 : ASSIGN NEW NODE -> PREV = NULL  <br/>
Step 6 : ASSIGN NEW NODE -> NEXT = START  <br/>
Step 7 : ASSIGN HEAD -> PREV = NEW NODE  <br/>
Step 8 : ASSIGN HEAD = NEW NODE <br/>
Step 9 : RETURN <br/>

#### 2.	Algorithm for insertion at end.	

Step 1 : NOW, IF POINTER = NULL <br/>
Step 2 : ASSIGN NEW NODE = POINTER <br/>
Step 3 : ASSIGN POINTER = POINTER -> NEXT  <br/>
Step 4 : ASSIGN NEW NODE -> DATA = VALUE  <br/>
Step 5 : ASSIGN NEW NODE -> PREV = NULL  <br/>
Step 6 : ASSIGN EXTRA = START <br/>
Step 7 : (REPEAT STEP 8)WHILE EXTRA = EXTRA !->NULL <br/>
Step 8 : ASSIGN EXTRA = EXTRA ->NEXT <br/>
Step 9 : ASSIGN EXTRA ->NEXT = NEW NODE <br/>
Step 10 : ASSIGN NEW NODE -> PREV = EXTRA AND RETURN <br/>

#### 3.	Algorithm for insertion at given index.	

Step 1 : Calculate the size of the node <br/>
Step 2 : If the position you want to enter is less than 1
Invalid position But, if 0 then use insertAtStart method  <br/>
Step 3 : If the position you want to enter is greater than size then
Invalid position, but if the position is equal to size then use insertLast method  <br/>
Step 4 : Else create a temp node and assign it the address of the head <br/>
Step 5 : Create a new node and assign it the data value <br/>
Step 6 : Iterate to the position you want to enter after in the linked list  <br/>
Step 7 : Assign this new node’s next and previous nodes <br/>
Step 8 : Assign previous node’s next to this new node <br/>
Step 9 : Assign next node’s previous to this new node <br/>
 

### Algorithm for Deletion

1.	The first node is deleted.
2.	The last node is deleted.
3.	The node after a given node is deleted.

#### 1.	Algorithm for delete from beginning.	

Step1: NOW IF HEAD = NULL (GO TO STEP 6)  <br/>
Step2: ASSIGN POINTER = HEAD <br/>
Step3: ASSIGN HEAD = HEAD → NEXT  <br/>
Step4: ASSIGN HEAD → PREVIOUS = NULL  <br/>
Step5: THAN FREE OR DELETE POINTER  <br/>
Step6: EXIT <br/>

#### 2.	Algorithm for delete from end.	

Step1: NOW IF HEAD = NULL (GO TO STEP 6)  <br/>
Step2: ASSIGN EXTRA = HEAD <br/>
Step3: MAKE A LOOP WHILE EXTRA = NEXT != NULL <br/>
Step4: ASSIGN EXTRA = EXTRA -> NEXT (END THE WHILE LOOP)  <br/>
Step5: THAN ASSIGN EXTRA -> PREVIOUS -> NEXT = NULL  <br/>
Step6: THAN FREE EXTRA <br/>
Step7: EXIT <br/>

#### 3.	Algorithm for delete from given index.	
Step1: IF HEAD = NULL (GOTO STEP 9 AND END OF IF LOOP)  <br/>
Step2: NOW ASSIGN EXTRA = HEAD <br/>
Step3: REPEAT STEP 4 WHILE TEMP → DATA != VALUE <br/>
Step4: ASSIGN EXTRA = EXTRA → NEXT <br/>
Step5: ASSIGN POINTER = EXTRA → NEXT <br/>
Step6: ASSIGN EXTRA → NEXT = POINTER → NEXT  <br/>
Step7: ASSIGN POINTER → NEXT → PREVIOUS = EXTRA  <br/>
Step8: REMOVE POINTER <br/>
Step9: EXIT <br/>

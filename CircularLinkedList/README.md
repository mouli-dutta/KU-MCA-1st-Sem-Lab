## Implementing basic operations of a Circular Linked List 
1. Insertion
2. Traversal
3. Deletion

### Algorithm for Traversal

Input : head {Pointer to the first node of the list} <br/>
Begin: <br/>
&nbsp;&nbsp;&nbsp;&nbsp;If (head == NULL) then <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;write ('List is empty') <br/>
&nbsp;&nbsp;&nbsp;&nbsp;Else then <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;current ← head;  <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Do <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;write ('Data =', current.data)  <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;current ← current.next; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;While (current != head) <br/>
&nbsp;&nbsp;&nbsp;&nbsp;End if <br/>
End <br/>

### Algorithm for Insertion
1.	The new node is inserted at the beginning.
2.	The new node is inserted at the end.
3.	The new node is inserted after a given node.

#### 1. Algorithm for insert at beginning.	

Step 1: NOW IF POINTER = NULL (GO TO STEP 11)  <br/>
Step 2: ASSIGN NEW NODE = POINTER <br/>
Step 3: ASSIGN POINTER = POINTER → NEXT <br/> 
Step 4: ASSIGN NEW NODE → DATA = VALUE  <br/>
Step 5: ASSIGN TEMP NODE = HEAD <br/>
Step 6: REPEAT STEP 8 WHILE TEMP → NEXT != HEAD (END OF WHILE LOOP)  <br/>
Step 7: ASSIGN TEMP NODE = TEMP → NEXT <br/>
Step 8: ASSIGN NEW NODE → NEXT = HEAD <br/>
Step 9: ASSIGN TEMP NODE → NEXT = NEW NODE  <br/>
Step 10:ASSIGN HEAD = NEW NODE <br/>
Step 11:EXIT <br/>

#### 2. Algorithm for insert at end.

Step 1: IF HEAD = NULL (END OF IF AND GO TO STEP 8)  <br/>
Step 2: ASSIGN POINTER = HEAD <br/>
Step 3: WHILE POINTER -> NEXT != HEAD (REPEAT STEP 4 AND 5)  <br/>
Step 4: ASSIGN PREVIOUS_POINTER = POINTER <br/>
Step 5: ASSIGN POINTER = POINTER -> NEXT (END OF WHILE LOOP)  <br/>
Step 6: ASSIGN PREVIOUS_POINTER -> NEXT = HEAD <br/>
Step 7: REMOVE POINTER Step 8: EXIT <br/>


#### 3.	Algorithm for insert at given index.	

Step 1: ASSIGN NEW NODE AND CURRENT NODE Step  <br/>
Step 2: IF HEAD == NULL ( GOTO STEP 9 )  <br/>
Step 3: ELSE NEW NODE → DATA = DATA  <br/>
Step 4: CURRENT NODE = HEAD <br/>
Step 5: FOR I=2 TO POS-1 <br/>
Step 6: CURRENT NODE=CURRENT NODE → NEXT (END OF FOR LOOP)  <br/>
Step 7: NEW NODE → NEXT=CURRENT NODE → NEXT <br/>
Step 8: CURRENT NODE → NEXT = NEW NODE  <br/>
Step 9: EXIT <br/>


### Algorithm for Deletion

1.	The first node is deleted.
2.	The last node is deleted.
3.	The node after a given node is deleted.

#### 1. Algorithm for deletion from beginning 
Step 1:	IF HEAD = NULL ( GO TO STEP 8 )  <br/>
Step 2:	NOW SET POINTER = HEAD <br/>
Step 3:	REPEAT STEP 4 UNTIL POINTER → NEXT != HEAD  <br/>
Step 4:	ASSIGN POINTER = POINTER → NEXT (END OF LOOP)  <br/>
Step 5:	ASSIGN POINTER → NEXT = HEAD → NEXT <br/>
Step 6:	FREE HEAD NODE <br/>
Step 7:	ASSIGN HEAD = POINTER → NEXT  <br/>
Step 8:	EXIT <br/>

#### 2. Algorithm for deletion from end
Step 1:	IF HEAD = NULL ( GO TO STEP 8 )  <br/>
Step 2:	NOW SET POINTER = HEAD <br/>
Step 3:	REPEAT STEP 4 AND 5 UNTIL POINTER → NEXT != HEAD  <br/>
Step 4:	ASSIGN PRE_POINTER = POINTER <br/>
Step 5:	ASSIGN POINTER = POINTER → NEXT  <br/>
Step 6:	ASSIGN PRE_POINTER → NEXT = HEAD  <br/>
Step 7:	REMOVE OR FREE POINTER <br/>
Step 8:	EXIT <br/>

#### 3. Algorithm for delete from given index.	

Step 1: MAKE A TWO NEW NODE U AND V  <br/>
Step 2: SET VALUE OF W = 0 <br/>
Step 3: THEN SET DELETE = POSITION-1  <br/>
Step 4: MAKE U = HEAD <br/>
Step 5: MAKE A LOOP WHILE (W != DELETE)  <br/>
Step 6: SET VALUE EQUAL TO V = U <br/>
Step 7: THEN U = U → NEXT <br/>
Step 8: INCREMENT VARIABLE VALUE W++  <br/>
Step 9: AT LAST V → NEXT = U →NEXT  <br/>
Step 10: FREE NODE U <br/>

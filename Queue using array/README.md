## Implementing a queue using array

### •	Algorithm for ENQUEUE() operation in Queue using Array:

Step 1: IF (REAR == Size - 1) // Condition for Overflow <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Write Queue is in Overflow condition therefore, insertion is not possible  <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END OF IF <br/>
Step 2: IF ((FRONT == -1) and (REAR = -1)) // Inserting an element in an empty queue  <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FRONT = REAR = 0 <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SET REAR = REAR + 1 // Increment Rear END OF IF <br/>
Step 3: SET QUEUE [REAR] = element // Assign the inserted element to the queue <br/>
Step 4: END Enqueue <br/>


### •	Algorithm for DEQUEUE() operation in Queue using Array:

Step 1: IF ((FRONT == -1) or (FRONT > REAR)) // Condition for Underflow <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Write Queue is in Underflow condition therefore, deletion is not possible <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SET Element = QUEUE [FRONT] <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SET FRONT = FRONT + 1 // Increment Front END OF IF <br/>
Step 2: End Dequeue <br/>

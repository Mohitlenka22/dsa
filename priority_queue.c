//C program to Demonstrate Priority Queue
#include<stdio.h>
#include<limits.h>
#define MAX 100



int rear = -1;


int priority_q[MAX];
int pqPriority[MAX];



int isEmpty(){
    return rear == -1;
}

int isFull(){
    return rear == MAX - 1;
}
void enqueue(int data, int priority)
{
    if(!isFull()){
        
        rear++;
 
        priority_q[rear] = data;
        pqPriority[rear] = priority;
    }
}

int peek()
{
    int maxPriority = INT_MIN;
    int indexPos = -1;
 
    for (int i = 0; i <= rear; i++) { 
       
        if (maxPriority == pqPriority[i] && indexPos > -1 && priority_q[indexPos] < priority_q[i]) 
        {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
        
        else if (maxPriority < pqPriority[i]) {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
    }
    
    return indexPos;
}

void dequeue()
{
    if(!isEmpty())
    {
        int indexPos = peek();
        for (int i = indexPos; i < rear; i++) {
            priority_q[i] = priority_q[i + 1];
            pqPriority[i] = pqPriority[i + 1];
        }
 
        rear--;
    }
}

void display(){
    for (int i = 0; i <= rear; i++) {
        printf("(%d, %d)\n",priority_q[i], pqPriority[i]);
    } 
}
// Driver Code
int main()
{
    enqueue(5, 1);
    enqueue(10, 3);
    enqueue(15, 4);
    enqueue(20, 5);
    enqueue(500, 2);
    
    printf("Before Dequeue : \n");
    display();
 
    // Dequeue the top element
    dequeue(); // 20 dequeued
    dequeue(); // 15 dequeued
    
    printf("\nAfter Dequeue : \n");
    display();

    return 0;
}
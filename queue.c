#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int isfull(int rear, int max);
int isempty(int front, int rear);
int enqueue(int q[], int rear, int max);
int dequeue(int q[], int front, int rear);
void peek(int q[], int front, int rear);
void size(int front, int rear);

int main()
{
    int n;
    printf("Enter the size of the queue : ");
    scanf("%d", &n);
    int q[n];
    int front = 0;
    int rear = 0;
    while (true)
    {
        printf("Select an option : \n 1.enqueue\n 2.dequeue\n 3.peek\n 4.size\n 5.quit\n");
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            rear = enqueue(q, rear, n);
            break;
        case 2:
            front = dequeue(q, front, rear);
            break;
        case 3:
            peek(q, front, rear);
            break;
        case 4:
            size(front, rear);
            break;
        case 5:
            exit(0);
        default:
            printf("Select a valid option.\n");
            break;
        }
    }
    return 0;
}

int isfull(int rear, int max)
{
    if (rear == max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(int front, int rear)
{
    if (front == rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int enqueue(int q[], int rear, int max)
{
    if (isfull(rear, max) == 0)
    {
        int value;
        printf("Enter a value to enqueue : ");
        scanf("%d", &value);
        q[rear] = value;
        return rear + 1;
    }
    else
    {
        printf("Queue is full.\nyou can only dequeue.\n");
        return rear;
    }
}

int dequeue(int q[], int front, int rear)
{
    if (isempty(front, rear) == 0)
    {
        printf("%d is the front value.\n", q[front]);
        return front + 1;
    }
    else
    {
        printf("Queue is empty.\nPlease enter elements into queue first.\n");
        return front;
    }
}

void peek(int q[], int front, int rear)
{
    if (isempty(front, rear) == 0)
    {
        printf("%d", q[front]);
    }
    else
    {
        printf("Queue is empty.\nPlease insert elements into the queue.\n");
    }
}

void size(int front, int rear)
{
    printf("%d is the present size of the queue.\n", (rear - front));
}
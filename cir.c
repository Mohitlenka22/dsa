#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int front = -1, rear = -1, size = 0;

bool isFull(int n)
{
    if ((front == rear + 1) || (front == 0 && rear == n - 1))
        return true;
    return false;
}

bool isEmpty()
{
    if (front == -1)
        return true;
    return false;
}

void enqueue(int cir_queue[], int n, int element)
{
    if (isFull(n))
        printf("\n Queue is full!! \n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % n;
        cir_queue[rear] = element;
        size = size + 1;
        printf("\n Inserted -> %d", element);
    }
}

int dequeue(int cir_queue[], int n)
{
    int element;
    if (isEmpty())
    {
        printf("\n Queue is empty !! \n");
        return (-1);
    }
    else
    {
        element = cir_queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }

        else
        {
            front = (front + 1) % n;
        }
        size = size - 1;
        printf("\n Deleted element -> %d \n", element);
        return (element);
    }
}

void peek(int cir_queue[], int n)
{
    if (!(isEmpty()))
    {
        printf("Element: %d\n", cir_queue[front]);
    }
    else
    {
        printf("Queue is empty");
    }
}

void Size()
{
    printf("The size: %d", size);
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int cir_queue[n];
    int element;
    while (true)
    {
        printf("Select an option : \n 1.enqueue\n 2.dequeue\n 3.peek\n 4.Size\n 5.quit\n");
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &element);
            enqueue(cir_queue, n, element);
            break;
        case 2:
            dequeue(cir_queue, n);
            break;
        case 3:
            peek(cir_queue, n);
            break;
        case 4:
            Size();
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
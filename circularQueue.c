#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isfull(int *size, int n);
bool isempty(int *size);
void enqueue(int *front, int *size, int n, int cir[]);
int dequeue(int *front, int *size, int n, int cir[]);
void peek(int *front, int cir[], int *size);

int main()
{
    int n;
    scanf("%d", &n);
    int cir[n];
    int front = 0;
    int size = 0;
    while (true)
    {
        printf("Select an option : \n 1.enqueue\n 2.dequeue\n 3.peek\n 4.size\n 5.quit\n");
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            enqueue(&front, &size, n, cir);
            break;
        case 2:
            printf(" dequeue: %d\n", dequeue(&front, &size, n, cir));
            break;
        case 3:
            peek(&front, cir, &size);
            break;
        case 4:
            printf("size : %d\n", size);
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

bool isfull(int *size, int n)
{
    if (n == *size)
        return true;
    return false;
}

bool isempty(int *size)
{
    if (*size == 0)
        return true;
    return false;
}

void enqueue(int *front, int *size, int n, int cir[])
{
    if (isfull(size, n) == false)
    {
        int x;
        printf("Enter element: ");
        scanf("%d", &x);
        int rear = (*front + *size - 1) % n;
        rear = (rear + 1) % n;
        cir[rear] = x;
        *size = *size + 1;
    }
    else
    {
        printf("Queue is full.\n");
    }
}

int dequeue(int *front, int *size, int n, int cir[])
{
    if (isempty(size) == false)
    {
        int val = cir[*front];
        *front = (*front + 1) % n;
        *size = *size - 1;
        return val;
    }
    else
    {
        printf("Queue is empty\n");
    }
}

void peek(int *front, int cir[], int *size)
{
    if (isempty(size) == false)
    {
        printf("top : %d\n", cir[*front]);
    }
}

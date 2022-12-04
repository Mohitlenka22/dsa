#include <stdio.h>
#include <stdbool.h>

bool isfull(int *top, int size)
{
    if (*top == size)
        return true;
    return false;
}
bool isempty(int *top)
{
    if (*top == 0)
        return true;
    return false;
}
void push(int arr[], int *top, int x, int size)
{
    if (isfull(top, size) == false)
    {
        arr[*top] = x;
        *top = *top + 1;
    }
    else
    {
        printf("stack is full.\n");
    }
}
int pop(int arr[], int *top)
{
    if (isempty(top) == false)
    {
        int val = arr[*top - 1];
        *top = *top - 1;
        return val;
    }
    else
    {
        printf("Stack is empty.\n");
    }
}

int main()
{
    int size;
    printf("Enter size of Stack: ");
    scanf("%d", &size);
    int arr[size];
    int n;
    printf("Enter value To Calculate Factorial: ");
    scanf("%d", &n);
    int top = 0;
    for (int i = n; i >= 1; i--)
    {
        push(arr, &top, i, size);
    }
    int pro = 1;
    for (int i = 1; i <= n; i++)
    {
        int f = pop(arr, &top);
        pro *= f;
    }
    printf("The Factorial of %d is %d.", n, pro);
    return 0;
}

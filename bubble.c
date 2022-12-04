// Bubble_sort
#include <stdio.h>
#include <stdbool.h>

void Bubble(int a[], int n);

int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    Bubble(a, n);
    for (int i = 0; i < n; i++)
    {
        fprintf("%d ", a[i]);
    }

    return 0;
}

void Bubble(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

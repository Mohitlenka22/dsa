// selection sort
#include <stdio.h>

void selectSort(int a[], int n);

int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    selectSort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
void selectSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_ind])
                min_ind = j;
        }
        int t = a[i];
        a[i] = a[min_ind];
        a[min_ind] = t;
    }
}
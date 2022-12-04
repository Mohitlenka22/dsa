// Linear search

#include <stdio.h>


int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int key, flag = 0, loc = -1;
    printf("Enter key to be searched: ");
    scanf("%d", &key);
    for(int j = 0;j < n; j++)
    {
        if (arr[j] == key)
        {
            loc = j;
            printf("The element %d found at index %d", key, loc);
            flag++;
        }
    }
    if(flag == 0)
    {
        printf("Not found.");
    }
    
    return 0;
}


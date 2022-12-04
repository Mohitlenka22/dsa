//Binary search

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarysearch(int arr[], int l, int h, int x);

int main()
{
    int arr[100];
    FILE *fp1 = fopen("data.csv", "r");
    FILE *fp2 = fopen("output.csv", "w");
    char buff[100];
    do
    {
        fgets(buff, 100, (FILE *)fp1);
    } while ((getc(fp1)) != EOF);

    char *token = strtok(buff, ",");
    int i = 0;
    while (token != NULL)
    {
        arr[i] = atoi(token);
        i++;
        token = strtok(NULL, ",");
    }
    int key;
    printf("Enter key to be searched: ");
    scanf("%d", &key);
    int res = binarysearch(arr, 0, i - 1, key);
    if (res == -1)
    {
        printf("Not Found.");
        fprintf(fp2, "Not Found.");
    }
    else
    {
        printf("The index of %d is %d.", key, res);
        fprintf(fp2, "The index of %d is %d.", key, res);
    }
    return 0;
};

int binarysearch(int arr[], int l, int h, int x)
{

    if (h >= l) {
        int mid = (l + h) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarysearch(arr, l, mid - 1, x);
        return binarysearch(arr, mid + 1, h, x);
    }

    return -1;

}
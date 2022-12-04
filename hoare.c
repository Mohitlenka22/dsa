// quicksort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void getData(char *buff, int a[]);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
    char folder_addr[] = "data.csv";
    int a[100];
    FILE *fp = fopen(folder_addr, "r");
    do
    {
        char buff[2048];
        fgets(buff, 2048, (FILE *)fp);
        getData(buff, a);
    } while ((getc(fp)) != EOF);
    return 0;
}

void getData(char *buff, int a[])
{
    char *token = strtok(buff, ",");
    int l = 0;
    while (token != NULL)
    {
        a[l] = atoi(token);
        l++;
        token = strtok(NULL, ",");
    }
    quickSort(a, 0, l - 1);
    for (int i = 0; i < l; i++)
        printf("%d ", a[i]);
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

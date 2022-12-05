//linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};
struct node *first = NULL;

void insertFirst(int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    if (first == NULL)
    {
        first = link;
        first->next = NULL;
    }
    else
    {
        link->next = first;
        first = link;
    }
}

void insertBefore(int key, int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    struct node *curr = first;
    struct node *prev = first;
    while (curr->next != NULL && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr->data == key)
    {
        link->data = data;
        prev->next = link;
        link->next = curr;
    }
}

void insertAfter(int key, int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node)), *temp = first;
    while (temp->next != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp->data == key)
    {
        link->data = data;
        link->next = temp->next;
        temp->next = link;
    }
}

void insertLast(int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    struct node *curr = first;
    link->data = data;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    if (first == NULL)
    {
        first = link;
        first->next = NULL;
    }
    else
    {
        curr->next = link;
        link->next = NULL;
    }
}
void delete (int data)
{
    struct node *curr = first;
    struct node *prev = NULL;
    while (curr->next != NULL && curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == first)
    {
        first = first->next;
        free(curr);
    }
    else if (curr->data == data && curr->next != NULL)
    {
        prev->next = curr->next;
        free(curr);
    }
    else if (curr->data == data && curr->next == NULL)
    {
        prev->next = NULL;
        free(curr);
    }
}
void display()
{
    struct node *link = first;
    while (link != NULL)
    {
        printf("%d ", link->data);
        link = link->next;
    }
}

int main()
{

    while (true)
    {
        printf("Select an option : \n 1.insertFirst\n 2.insertLast\n 3.insertBefore\n 4.insertAfter\n 5.delete\n6.display\n7.quit\n");
        int option;
        scanf("%d", &option);
        int data, key;
        switch (option)
        {
        case 1:

            printf("Enter element: ");
            scanf("%d", &data);
            insertFirst(data);
            break;
        case 2:

            printf("Enter element: ");
            scanf("%d", &data);
            insertLast(data);
            break;
        case 3:

            printf("Enter element: ");
            scanf("%d", &data);
            printf("Enter key: ");
            scanf("%d", &key);
            insertBefore(key, data);
            break;
        case 4:

            printf("Enter element: ");
            scanf("%d", &data);
            printf("Enter key: ");
            scanf("%d", &key);
            insertAfter(key, data);
            break;
        case 5:

            printf("Enter element: ");
            scanf("%d", &key);
            delete (key);
            break;
        case 6:
            printf("List: ");
            display();
            break;
        case 7:
            exit(0);
        default:
            printf("Enter valid option");
        }
    }

    return 0;
}
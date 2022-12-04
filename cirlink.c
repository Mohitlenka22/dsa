#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *first = NULL;

void insertBegin(int data)
{
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    struct node *last = first;
    curr->data = data;
    if (first == NULL)
    {
        first = curr;
        curr->next = first;
    }
    else
    {

        while (last->next != first)
        {
            last = last->next;
        }
        curr->next = first;
        last->next = curr;
        first = curr;
    }
}
void insertLast(int data)
{
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    struct node *last = first;
    curr->data = data;
    while (last->next != first)
    {
        last = last->next;
    }
    last->next = curr;
    curr->next = first;
}

void insertBefore(int key, int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    struct node *curr = first;
    struct node *prev = first;
    while(curr->next != first && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }
    if(curr->data == key)
    {
        link->next = curr;
        prev->next = link;
    }
}

void insertAfter(int key, int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    struct node *curr = first;
    struct node *prev = first;
    while(curr->next != first && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }
    if(curr->data == key)
    {
        link->next = curr->next;
        curr->next = link;
    }
}

void deleteFirst()
{
    struct node *last = first;
    while (last->next != first)
    {
        last = last->next;
    }
    last->next = first->next;
    free(first);
    first = last->next;
}

void delete (int data)
{
    struct node *temp = first;
    struct node *prev = first;
    while (temp->data != data && temp->next != first)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->data == data)
    {
        prev->next = temp->next;
        free(temp);
    }
}
void display()
{
    struct node *temp = first;
    while (temp->next != first)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}
int main()
{
    insertBegin(20);
    insertBegin(10);
    insertLast(30);
    // delete(20);
    // deleteFirst();
    insertBefore(30, 10);
    // insertAfter(10, 2);
    display();
    return 0;
}
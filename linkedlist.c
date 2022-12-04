#include <stdio.h>
#include <stdlib.h>

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
    link->next = first;
    first = link;
}

void insertBefore(int key, int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    struct node *curr = first;
    struct node *prev = first;
    while (curr->next != NULL && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr->data == key)
    {
        link->next = curr;
        prev->next = link;
    }
}

void insertEnd(int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    link->next = NULL;
    if (first == NULL)
    {
        first = link;
    }
    struct node *curr = first;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = link;
}

void deleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else
    {
        struct node *link = first->next;
        free(first);
        first = link;
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
        free(first);
    }
    if (curr->data == data)
    {
        prev->next = curr->next;
        free(curr);
    }
}
void deleteLast()
{
    if (first == NULL)
    {
        return;
    }
    if (first->next == NULL)
    {
        free(first);
        first = NULL;
    }
    struct node *curr = first;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
}
void display()
{
    struct node *link = first;
    while (first != NULL)
    {
        printf("%d ", link->data);
        link = link->next;
    }
}

int main()
{
    insertFirst(20);
    insertFirst(11);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);
    // insertFirst(11);
    insertBefore(40, 22);
    delete (11);
    // deleteFirst();
    // deleteLast();
    display();

    return 0;
}
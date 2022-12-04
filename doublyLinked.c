#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev, *next;
};

struct node *first = NULL;

void insertFirst(int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    if (first == NULL)
    {
        link->next = NULL;
        link->prev = NULL; 
        link->data = data;
        first = link;
    }
    else
    {
        link->data = data;
        link->prev = NULL;
        link->next = first;
        first->prev = link;
        first = link;
    }
}

void insertLast(int data)
{
    struct node *link, *temp;
    int item;
    link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    if (first == NULL)
    {
        link->next = NULL;
        link->prev = NULL;
        first = link;
    }
    else
    {
        temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = link;
        link->prev = temp;
        link->next = NULL;
    }
}
void insertBefore(int key, int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node)), *temp = first;
    link->data = data;
    while (temp->next != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp->data == key)
    {
        temp->prev->next = link;
        link->prev = temp->prev;
        link->next = temp;
        temp->prev = link;
    }
}
void insertAfter(int key, int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node)), *temp = first;
    link->data = data;
    while (temp->next != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp->data == key)
    {

        link->next = temp->next;
        link->prev = temp;
        temp->next = link;
        temp->next->prev = link;
    }
}

void deletionFirst()
{
    struct node *link;
    if (first->next == NULL)
    {
        first = NULL;
        free(first);
    }
    else
    {
        link = first;
        first = first->next;
        first->prev = NULL;
        free(link);
    }
}
void deleteLast()
{
    struct node *link;
    if (first->next == NULL)
    {
        first = NULL;
        free(first);
    }
    else
    {
        link = first;
        if (link->next != NULL)
        {
            link = link->next;
        }
        link->prev->next = NULL;
        free(link);
    }
}
void delete (int data)
{
    struct node *link, *prev;
    link = first;
    while (link->data != data && link->next != NULL) 
    {
        prev = link;
        link = link->next;
    }
    if(link->data == data)
    {
        prev->next = link->next->prev;
        link->next = prev;
    }
}
void display()
{
    struct node *link;
    link = first;
    while (link != NULL)
    {
        printf("%d ", link->data);
        link = link->next;
    }
}

void main()
{
    insertFirst(20);
    insertFirst(10);
    insertLast(44);
    insertBefore(20, 55);
    insertAfter(20, 11);
    // deletion_beginning();
    // deletion_last();
    // delete (20);
    display();
}
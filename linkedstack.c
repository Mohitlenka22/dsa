#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};

struct node *first = NULL;

void push(int data)
{
    struct node *link = (struct node*)malloc(sizeof(struct node));
    link->data = data;
    link->next = first;
    first = link;
}

void pop()
{
    if(first == NULL)
    {
        return;
    }
    struct node *link = first->next;
    free(first);
    first = link;
}
void peek()
{
    if(first == NULL)
    {
        return;
    }
    printf("%d\n", first->data);
}
void display()
{
    struct node *link = first;
    while(link != NULL)
    {
        printf("%d ", link->data);
        link = link->next;
    }
    
}

int main()
{
    while (true){
        printf("Select an option : \n 1.push\n 2.pop\n 3.peek\n 4.display.\n 5.quit\n");
        int option;
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter element: \n");
                int n;
                scanf("%d", &n);
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
            case 5:
                exit(0);
            default :
                printf("Select a valid option.\n");
                break;
        }
    }

}
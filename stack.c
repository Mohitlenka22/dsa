#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int push(int s[], int top, int max);
int pop(int s[], int top);
void peek(int s[], int top);
void size(int top);
int isempty(int top);
int isfull(int top, int max);

int main(){
    int n;
    printf("Enter the size of the Stack : ");
    scanf("%d", &n);
    int s[n];
    int top = 0;
    while (true){
        printf("Select an option : \n 1.push\n 2.pop\n 3.peek\n 4.size.\n 5.quit\n");
        int option;
        scanf("%d", &option);
        switch(option){
            case 1:
                top = push(s, top, n);
                break;
            case 2:
                top = pop(s, top);
                break;
            case 3:
                peek(s, top);
                break;
            case 4:
                size(top);
            case 5:
                exit(0);
            default :
                printf("Select a valid option.\n");
                break;
        }
    }
    return 0;
}

int push(int s[], int top, int max){
    if (isfull(top, max) == 0){
        int value;
        printf("Enter a value to stack : ");
        scanf("%d", &value);
        s[top] = value;
        return top+1;
    }
    else {
        printf("Stack is full.\nfirst remove elements and then add.\n");
        return top;
    }
}

int pop(int s[], int top){
    if (isempty(top) == 0){
        printf("%d is the top element.\n", s[top - 1]);
        return top - 1;
    }
    else {
        printf("First enter elements into the stack.\n");
        return top;
    }
}

void peek(int s[], int top){
    if (isempty(top) == 0){
        printf("%d is the top most element.\n", s[top]);
    }
    else {
        printf("Stack is empty.\n");
    }
}

void size(int top){
    printf("%d is the size of the stack.\n", top);
}

int isempty(int top){
    if (top == 0){
        return 1;
    }
    else {
        return 0;
    }
}

int isfull(int top, int max){
    if (top == max){
        return 1;
    }
    else {
        return 0;
    }
}



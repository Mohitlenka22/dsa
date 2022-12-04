#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = 0;

void push(char x)
{
    stack[top] = x;
    top++;
}

char pop()
{
    if (top != 0)
    {
        char val = stack[top-1];
        top--;
        return val;
    }
}

int prority(char x)
{
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if(x == '^')
        return 3;
}

int main()
{
    char exp[100];
    printf("Enter exp: ");
    scanf("%s", exp);
    char *e, x;
    e = exp;
    while (*e != '\0')
    {
        if (isalnum(*e))
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while (prority(stack[top]) >= prority(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while (top != 0)
    {
        printf("%c", pop());
    }
    return 0;
}
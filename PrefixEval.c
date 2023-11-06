#include<stdio.h>

#define size 100

typedef enum {lparenthesis, rparenthesis, plus, minus, multiply, divide, mod, eos, operand} precedence;

int a[size];

int top = -1;

precedence get_token(char c)
{
    switch(c)
    {

        case'(':
            return lparenthesis;

        case')':
            return rparenthesis;

        case'+':
            return plus;

        case'-':
            return minus;

        case'/':
            return divide;

        case'*':
            return multiply;

}

void push(int ele)
{
    if(top == size - 1)
    {
        printf("Stack is full\n");
    }

    else
    {
        a[++top] = ele;
    }
}

int pop(void)
{
    if(top == -1)
    {
        printf("Stack is empty\n");
        return -99999;
    }

    else
    {
        return a[top--];
    }
}

void prefix_eval(char prefix[])
{
    int i = 0, op1, op2;

    for(i = 0; prefix[i] != '\0'; i++);
    i = i - 1;

    while(i >= 0)
    {
        precedence temp = get_token(prefix[i]);

        if(temp == operand)
        {
            push(prefix[i] - '0'); //datatype of stack is int
        }

        else
        {
            op1 = pop();
            op2 = pop();

            switch(prefix[i])
            {
            case '+':
                push(op1 + op2);
                break;

            case '-':
                push(op1 - op2);
                break;

            case '*':
                push(op1 * op2);
                break;

            case '/':
                push(op1 / op2);
                break;

            case '%':
                push(op1 % op2);
                break;

            default:
                printf("invalid operator\n");
                break;
            }
        }
        i--;
    }
    printf("Result is %d\n", pop());
}

int main(void)
{
    char str[100];
    printf("Enter prefix expression: ");
    scanf("%s", str);

    prefix_eval(str);
}

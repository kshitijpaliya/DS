#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

int isOperator(char ch)
{
    return(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

int precedence (char ch)
{
    switch(ch)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int main ()
{
    char infix[100], post[100];
    int k =0;

    char stack[100];
    int top =-1;
    printf("Enter infix expression:\n");
    scanf("%s", &infix);

    for(int i=0; infix[i]!='\0'; i++)
    {
        if(isalnum(infix[i]))
        {
            printf("INFIX: %c\n", infix[i]);
            post[k++]=infix[i];
            printf("POST: %c\n", post[k-1]);
        }


    else if(infix[i]=='(')
    {
        stack[++top]=infix[i];
    }
    else if(infix[i]==')')
    {
        while(stack[top]!='(' && top>=0)
        {
            post[k++]=stack[top--];
        }
    top--;
    }
    else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^')
    {
        while(top>-1 && precedence(stack[top])>=precedence(infix[i]))
        {
            post[k++]=stack[top--];
        }
        stack[++top]=infix[i];
    }
    }
    while(top>=-1)
    {
        post[k++]=stack[top--];
    }
    post[k]='\0';
    for(int i=0;post[i]!='\0';i++)
    {
        printf("%c", post[i]);
    }
}


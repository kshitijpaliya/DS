#include<stdio.h>
#include<string.h>
#include <math.h>
#define MAX_SIZE 100


struct Stack{
    float items[MAX_SIZE];
    int top;
};

void initilize(struct Stack *stack)
{
    stack->top=-1;
}

_Bool isEmpty(struct Stack *stack)
{
    return stack->top==-1;
}
_Bool isFull(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack *stack, float item)
 {
     if (isFull(stack)) {
     printf("Stack overflow, cannot push %d\n", item);
     return;
    }

    stack -> top++;
    stack-> items[stack->top]=item*1.0;

 }

 float pop(struct Stack *stack) {
 if (isEmpty(stack)) {
 printf("Stack underflow, cannot pop\n");
 return -1;
 }
 float poppedItem = stack->items[stack->top];
 stack->top--;
 return poppedItem;
}

int peek(struct Stack *stack) {
 if (isEmpty(stack)) {
 printf("Stack is empty, cannot peek\n");
 return -1;
 }
 return stack->items[stack->top];
}


int main()
{
    char postfix[100];
    int k=0;


    struct Stack stack;
    initilize(&stack);

    printf("Enter postfix expression:");
    scanf("%s",&postfix);

    for(int i=0;postfix[i]!='\0';i++)
    {
        if(postfix[i]>='0' && postfix[i]<='9')
        {
            push(&stack,postfix[i]-'0');
        }
        else
        {
            float ele1 =pop(&stack);
            float ele2 = pop(&stack);
            if(postfix[i]=='+')
            {
                push(&stack,ele1+ele2+0.0);
            }
            else if(postfix[i]=='-')
            {
                push(&stack,ele2-ele1-0.0);
            }
            else if(postfix[i]=='*')
            {
                push(&stack,ele1*ele2);
            }
            else if(postfix[i]=='/')
            {

                push(&stack,(float)(ele2/ele1));
            }
            else if(postfix[i]=='^')
            {
                push(&stack,pow(ele1,ele2));
            }

        }
    }
    printf("Ans:%f",pop(&stack));
    //printf("%f",4.0/5);


}

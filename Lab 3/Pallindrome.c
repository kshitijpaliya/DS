#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

struct Stack{
    int items[MAX_SIZE];
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
void push(struct Stack *stack, char item)
 {
     if (isFull(stack)) {
     printf("Stack overflow, cannot push %d\n", item);
     return;
    }
    stack -> top++;
    stack-> items[stack->top]=item;
 }

 int pop(struct Stack *stack) {
 if (isEmpty(stack)) {
 printf("Stack underflow, cannot pop\n");
 return -1;
 }
 char poppedItem = stack->items[stack->top];
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
    struct Stack stack;
    initilize(&stack);
    char str[100];
    //input

    printf("Enter str:");
    gets(str);

    int length= strlen(str);

    for(int i=0;i<length;i++)
    {
        push(&stack,str[i]);
    }

    for(int i=0;i<length/2;i++)
    {
        if(pop(&stack)!=str[i])
        {
            printf("Not a palindrome");
            return;
        }
    }

    printf("Palindrome");




}

//#include<stdio.h>
//#define MAX 100
//
//char stack[MAX];
//int top=-1;
//
//void push(char s)
//{
//    top++;
//    stack[top]=s;
//}
//
//int main ()
//{
//    char str[MAX], c;
//    printf("Enter the string:\n");
//    scanf("%s", str);
//    int i = 0;
//    for(i=0;str[i]!='\0';i++)
//    {
//        c=str[i];
//        push(c);
//    }
///*     while(str[i]!='\0')
// *     {
// *         top=MAX-1;
// *         if(stack[top]==str[i])
// *         {
// *             printf("The string is a palindrome");
// *         }
// *         else
// *         {
// *             printf("Not a palindrome");
// *         }
// *         top--;
// *         i++;
// *     }
// */
//    int flag=1;
//    for(i=0; str[i]!='\0'; i++)
//    {
//        if(stack[top]!=str[i])
//        {
//            flag=0;
//        }
//        top--;
//    }
//    if(flag==1)
//    {
//        printf("The string is a palindrome");
//    }
//    else
//    {
//        printf("Not a palindrome");
//    }
//    return 0;
//}


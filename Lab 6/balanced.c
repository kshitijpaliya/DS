#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    char items[MAX_STACK_SIZE];
} CharStack;

typedef struct {
    int top;
    int items[MAX_STACK_SIZE];
} IntStack;

void charPush(CharStack *s, char value) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Char Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

char charPop(CharStack *s) {
    if (s->top == -1) {
        printf("Char Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

void intPush(IntStack *s, int value) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Int Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

int intPop(IntStack *s) {
    if (s->top == -1) {
        printf("Int Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

void postfixToInfix(char *postfix) {
    CharStack charStack;
    IntStack intStack;
    charStack.top = -1;
    intStack.top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            intPush(&intStack, postfix[i] - '0');
        } else {
            char operator = postfix[i];
            int operand2 = intPop(&intStack);
            int operand1 = intPop(&intStack);

            charPush(&charStack, '(');
            intPush(&intStack, operand1);

            charPush(&charStack, operator);

            intPush(&intStack, operand2);
            charPush(&charStack, ')');
        }
    }

    if (intStack.top != 0 || charStack.top != 1) {
        printf("Invalid postfix expression\n");
        return;
    }

    char result[MAX_STACK_SIZE];
    int resultIdx = 0;
    while (charStack.top != -1) {
        result[resultIdx++] = charPop(&charStack);
    }
    result[resultIdx] = '\0';

    printf("Infix expression: %s\n", result);
}

int main() {
    char postfix[] = "23*5+";
    postfixToInfix(postfix);

    return 0;
}

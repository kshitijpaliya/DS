#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define a structure for a node in the expression tree
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to construct an expression tree from a postfix expression
struct TreeNode* constructExpressionTree(char postfix[]) {
    struct TreeNode* stack[100]; // Assuming maximum size of expression is 100
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            stack[++top] = createNode(postfix[i]);
        } else if (isOperator(postfix[i])) {
            struct TreeNode* newNode = createNode(postfix[i]);
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }

    return stack[top];
}

// Function to evaluate an expression tree
int evaluateExpressionTree(struct TreeNode* root) {
    if (root == NULL) return 0;

    if (!isOperator(root->data)) {
        return root->data - '0';
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0; // Invalid operator
    }
}

int main() {
    char postfix[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    struct TreeNode* root = constructExpressionTree(postfix);

    int result = evaluateExpressionTree(root);

    printf("Result of the postfix expression: %d\n", result);

    return 0;
}
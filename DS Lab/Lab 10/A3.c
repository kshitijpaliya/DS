#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to copy a tree
struct TreeNode* copyTree(struct TreeNode* original) {
    if (original == NULL) return NULL;

    struct TreeNode* copy = createNode(original->data);
    copy->left = copyTree(original->left);
    copy->right = copyTree(original->right);

    return copy;
}

// Function to perform in-order traversal
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct TreeNode* originalTree = NULL;
    struct TreeNode* copiedTree = NULL;
    int data;
    char choice;

    // Create the original tree
    printf("Enter elements for the original tree:\n");
    do {
        printf("Enter an element: ");
        scanf("%d", &data);

        struct TreeNode* newNode = createNode(data);

        if (originalTree == NULL) {
            originalTree = newNode;
        } else {
            struct TreeNode* current = originalTree;
            struct TreeNode* parent = NULL;
            while (current != NULL) {
                parent = current;
                if (data < current->data)
                    current = current->left;
                else
                    current = current->right;
            }
            if (data < parent->data)
                parent->left = newNode;
            else
                parent->right = newNode;
        }

        printf("Do you want to insert another element? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Copy the tree
    copiedTree = copyTree(originalTree);

    // Print the original tree
    printf("\nOriginal Tree (In-order traversal): ");
    inOrderTraversal(originalTree);

    // Print the copied tree
    printf("\n\nCopied Tree (In-order traversal): ");
    inOrderTraversal(copiedTree);

    return 0;
}
